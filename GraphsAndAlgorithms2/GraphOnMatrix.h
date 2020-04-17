#pragma once
#include "Matrix.h"
#include "TypesOfList.h"

template <typename T>
class GraphOnMatrix
{
	ListV* listOfVertices;
	List<Edge<T>>* listOfEdges;
	Matrix<Edge<T>*>* aMatrix;// macierz s¹siedztwa;
	Vertex<int>* startVertex;

public:
	GraphOnMatrix();
	~GraphOnMatrix();
	void fillGraph(std::string nameOfFile);
	void show();
	void insertVertex(int o);
	void insertEdge(Vertex<int>* v,Vertex<int>* w,T weight);
	bool removeVertex(Vertex<int>* v);
	bool removeEdge(Edge<T>* e);
	List<Edge<T>>* incidentEdges(Vertex<T>* v);
	List<Edge<T>>* edges();
	void showEdges();
	ListV* vertices();
	void showVertices();
	Vertex<int>** endVertices(Edge<T>* e);
	Vertex<int>* opposite(Vertex<int>* v, Edge<T>* e);
	bool areAdjacent(Vertex<int>* v, Vertex<int>* w);//true jesli s¹ s¹siednie, false jeœli nie s¹
	void replaceV(Vertex<int>* v, int number);
	void replaceE(Edge<T>* e, T weight);
	void repairMatrix();
	Vertex<int>* getStartVertex();
};

template < typename T >
GraphOnMatrix<T>::GraphOnMatrix() {
	listOfEdges = new List<Edge<T>>();
	listOfVertices = new List<Vertex<int>>();
	aMatrix = new Matrix<Edge<T>*>();
	startVertex = 0;
}

template < typename T >
GraphOnMatrix<T>::~GraphOnMatrix() {
	aMatrix->setNullptr();
	delete listOfEdges;
	delete listOfVertices;
}

template <typename T>
void GraphOnMatrix<T>::fillGraph(std::string nameOfFile) { //do poprawy Bardzo Wazne
	int numberOfEdges;
	int numberOfVertices;
	int start;

	int row;  //startpoint of edge
	int column; //endpoint 
	T weight;
	std::fstream file;

	file.open(nameOfFile.c_str());
	if (file.good()) {
		file >> numberOfEdges >> numberOfVertices >> start;
		aMatrix = new Matrix<Edge<T>*>(numberOfVertices);
		for (int i = 0; i < numberOfVertices; i++) {
			listOfVertices->insertOnBack(new Vertex<int>(i)); //no i trzeba te wskazniki na sameg siebie!!!!
		}
		startVertex = (*listOfVertices)[start];
		while (!file.eof())
		{
			file >> row >> column >> weight;
			Edge<T>* edge = new Edge<T>(weight,nullptr,(*listOfVertices)[row],(*listOfVertices)[column]); //nullptr bo narzei nie znam miejsca w liscie 
			listOfEdges->insertOnBack(edge); // w œrodku funkjci ustawia sie wskaznik na miejsce w liscie
			aMatrix->setElement(row, column, edge);
			//edge = new Edge<T>(weight, nullptr, (*listOfVertices)[column], (*listOfVertices)[row]);
			//listOfEdges->insertOnBack(edge);
			aMatrix->setElement(column, row, edge);
		}
	}
	else {
		std::cout << "Plik nie jest poprawny!";
	}
	file.close();
}

template <typename T>
void GraphOnMatrix<T>::show() {
	std::cout << "Liczba krawedzi: ";
	std::cout << listOfEdges->size();
	std::cout << std::endl;
	std::cout << "Liczba wierzcholkow: ";
	std::cout << listOfVertices->size();
	std::cout << std::endl;
	std::cout << "Wierzcholek startowy: " << startVertex->getPoint() << std::endl;
	this->showVertices();
	aMatrix->show();
}

template <typename T>
void GraphOnMatrix<T>::insertVertex(int o) {
	if (o == listOfVertices->size()) {
		Vertex<int>* v = new Vertex<int>(o);
		listOfVertices->insertOnBack(v);
		repairMatrix();
	}
	else {
		std::cerr << "nie da siê dodaæ wierzcho³aka o podanym numerze, albo juz istnieje, albo nie mia³by powiazania z numerami porzednimi"<<std::endl;
	}
}

template <typename T>
void GraphOnMatrix<T>::repairMatrix() {
	int size =listOfVertices->size();
	Matrix<Edge<T>*> tmp = *aMatrix;
	aMatrix = new Matrix<Edge<T>*>(size);
	for (int i = 0; i < size-1; i++) { //przepisanie macierzy
		for (int j = 0; j < size-1; j++) {
			aMatrix->setElement(i, j, tmp.getElement(i, j));
		}
	}
}

template <typename T>
void GraphOnMatrix<T>::insertEdge(Vertex<int>* v, Vertex<int>* w, T weight) { //dodawanie tylko jesli takie wierzcholki istnieja
	if ((v->getPoint() >= 0 && v->getPoint() < listOfVertices->size()) && (w->getPoint() >= 0 && w->getPoint() < listOfVertices->size())) {
		Edge<T>* edge = new Edge<T>(weight, nullptr, v, w);
		listOfEdges->insertOnBack(edge);
		aMatrix->setElement(v->getPoint(), w->getPoint(), edge);
		aMatrix->setElement(w->getPoint(), v->getPoint(), edge);
		edge = nullptr;
	}
	else {
		std::cerr << "Jeden z wierzcholkow lub wierzcholki nie istnieja" << std::endl;
	}
}

template <typename T>
bool GraphOnMatrix<T>::removeVertex(Vertex<int>* v) { //usuwa powiazania ale zostawia macierz danej wielkosci jaka byla
	if (listOfVertices->findElem(v)!=nullptr){
		for (int j = 0; j < listOfVertices->size(); j++) {
			if (aMatrix->getElement(j, v->getPoint()) != nullptr) {
				removeEdge(aMatrix->getElement(j, v->getPoint()));
				aMatrix->setElement(j, v->getPoint(), nullptr);
			}
			if (aMatrix->getElement(v->getPoint(), j) != nullptr) {
				removeEdge(aMatrix->getElement(v->getPoint(), j));
				aMatrix->setElement(v->getPoint(), j, nullptr);
			}
		}
		listOfVertices->removeAtIndex(v->getPoint());
		std::cout << "usunieto z listy vierzcholokow wraz z powiazaniami" << std::endl;
		return true;
	}
	std::cerr << "nie usunieto wierzcholka" << std::endl;
	return false;
} 

template <typename T>
bool GraphOnMatrix<T>::removeEdge(Edge<T>* e) {//usuwa krawedz z istniejacych
	Compare<T, int> comp;

	for (int i = 0; i < listOfEdges->size(); i++) {
		if (comp(*e, *(*listOfEdges)[i])) {
			int row = e->getStartOfEdge()->getPoint();
			int column = e->getEndOfEdge()->getPoint();
			aMatrix->setElement(row, column, nullptr);
			aMatrix->setElement(column, row, nullptr);
			listOfEdges->removeAtIndex(i);
			return true;
		}
	}
	std::cerr << "nie usunieto krawedzi" << std::endl;
	return false;
}

template <typename T>
List<Edge<T>>* GraphOnMatrix<T>::incidentEdges(Vertex<T>* v) {
	List<Edge<T>>* list = new List<Edge<T>>();
	for (int i = 0; i < listOfVertices->size(); i++) {
		if (aMatrix->getElement(v->getPoint(),i) != nullptr)
			list->insertOnBack(aMatrix->getElement(v->getPoint(), i));
	}
	return list;
}

template <typename T>
void GraphOnMatrix<T>::showEdges() {
	std::cout << "Start   End   Weight" << std::endl;
	listOfEdges->showList();
}

template <typename T>
List<Edge<T>>* GraphOnMatrix<T>::edges() {
	return listOfEdges;
}

template <typename T>
void GraphOnMatrix<T>::showVertices() {
	listOfVertices->showList();
}

template <typename T>
ListV* GraphOnMatrix<T>::vertices() {
	return listOfVertices;
}

template <typename T>
Vertex<int>** GraphOnMatrix<T>::endVertices(Edge<T>* e){
	Vertex<int>** array = new Vertex<int>*[2];
	array[0] = e->getStartOfEdge();
	array[1] = e->getEndOfEdge();
	return array;
}

template <typename T>
Vertex<int>* GraphOnMatrix<T>::opposite(Vertex<int>* v, Edge<T>* e) {
	//Compare<T, int> comp;
	//int number = v->getPoint();
	//for(int i = 0; i<listOfVertices->size();i++){
	//	if (aMatrix->getElement(number, i) != nullptr) {
	//		if ( comp(*e, *aMatrix->getElement(number, i)) ) {
	//			if (comp(*v, *aMatrix->getElement(number, i)->getStartOfEdge())) {
	//				return aMatrix->getElement(number, i)->getEndOfEdge();
	//			}
	//			if (comp(*v, *aMatrix->getElement(number, i)->getEndOfEdge())) {
	//				return aMatrix->getElement(number, i)->getStartOfEdge();
	//			}
	//		}
	//	}
	//}
	if (v->getPoint()!= e->getStartOfEdge()->getPoint()) {
		return e->getStartOfEdge();
	}
	else{
		return e->getEndOfEdge();
	}
	//return nullptr;
}

template <typename T>
bool GraphOnMatrix<T>::areAdjacent(Vertex<int>* v, Vertex<int>* w) {
	if (aMatrix->getElement(v->getPoint(), w->getPoint()) != nullptr) {
		return true;
	}
	return false;
}

template <typename T>
void GraphOnMatrix<T>::replaceV(Vertex<int>* v, int number) {
	v->setPoint(number);
}

template <typename T>
void GraphOnMatrix<T>::replaceE(Edge<T>* e, T weight) {
	e->setWeight(weight);
}

template <typename T>
Vertex<int>* GraphOnMatrix<T>::getStartVertex() {
	return startVertex;
}

