#pragma once
#include "Matrix.h"
#include "TypesOfList.h"

template <typename T>
class GraphOnMatrix
{
	ListV* listOfVertices;
	List<Edge<T>>* listOfEdges;
	Matrix<Edge<T>*>* aMatrix;// macierz s�siedztwa;
	Vertex<int>* startVertex;

public:
	GraphOnMatrix();
	~GraphOnMatrix();
	void fillGraph(std::string nameOfFile);
	void show();
	void insertVertex(int o);
	void insertEdge(Vertex<int>* v,Vertex<int>* w,T weight);
	bool removeVertex(Vertex<int> v);
	bool removeEdge(Edge<T> e);
	List<Edge<T>>* incidentEdges(Vertex<T>* v);
	List<Edge<T>>* edges();
	void showEdges();
	ListV* vertices();
	void showVertices();
	Vertex<int>** endVertices(Edge<T>* e);
	Vertex<int>* opposite(Vertex<int>* v, Edge<T>* e);
	bool areAdjacent(Vertex<int>* v, Vertex<int>* w);//true jesli s� s�siednie, false je�li nie s�
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
			listOfEdges->insertOnBack(edge); // w �rodku funkjci ustawia sie wskaznik na miejsce w liscie
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
	Vertex<int>* v = new Vertex<int>(o);
	listOfVertices->insertOnBack(v);
}

template <typename T>
void GraphOnMatrix<T>::insertEdge(Vertex<int>* v, Vertex<int>* w, T weight) {
	Edge<T>* edge = new Edge<T>(weight, nullptr, v, w);
	listOfEdges->insertOnBack(edge);
	aMatrix->setElement(v->getPoint(),w->getPoint(),edge);
	aMatrix->setElement(w->getPoint(),v->getPoint(),edge);
	edge = nullptr;
}

template <typename T>
bool GraphOnMatrix<T>::removeVertex(Vertex<int> v) { 
	Compare<T, int> comp;
	for (int i = 0; i < listOfVertices->size(); i++) {
		if (comp(v, *(*listOfVertices)[i])) {
			for (int j = 0; j < listOfVertices->size(); j++) {
				if (aMatrix->getElement(j, i) != nullptr) {
					removeEdge(*aMatrix->getElement(j, i));
					aMatrix->setElement(j, i, nullptr);
				}
				if (aMatrix->getElement(i, j) != nullptr) {
					removeEdge(*aMatrix->getElement(i, j));
					aMatrix->setElement(i, j, nullptr);
				}
			}
			listOfVertices->removeAtIndex(i);
			return true;
		}
	}
	return false;
} 
//do poprawy bo trzeba usunac kraedzie przylegajace

template <typename T>
bool GraphOnMatrix<T>::removeEdge(Edge<T> e) {
	Compare<T, int> comp;
	for (int i = 0; i < listOfEdges->size(); i++) {
		if (comp(e, *(*listOfEdges)[i])) {
			int row = (*listOfEdges)[i]->getStartOfEdge()->getPoint();
			int column =(*listOfEdges)[i]->getEndOfEdge()->getPoint();
			aMatrix->setElement(row, column, nullptr);
			aMatrix->setElement(column, row, nullptr);
			listOfEdges->removeAtIndex(i);
			return true;
		}
	}
	return false;
}

template <typename T>
List<Edge<T>>* GraphOnMatrix<T>::incidentEdges(Vertex<T>* v) {
	Compare<T, int> comp;
	List<Edge<T>>* list= new List<Edge<T>>();
	for (int i = 0; i < listOfEdges->size(); i++) {
		if (comp(*v, *((*listOfEdges)[i]->getStartOfEdge()))) {
			list->insertOnBack((*listOfEdges)[i]);
		}
		if (comp(*v, *((*listOfEdges)[i]->getEndOfEdge()))) {
			list->insertOnBack((*listOfEdges)[i]);
		}
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
	Compare<T, int> comp;
	for (int i = 0; i < listOfEdges->size(); i++) {
		if (comp(*e, *((*listOfEdges)[i]))) {
			if (comp(*v, *((*listOfEdges)[i]->getStartOfEdge()))) {
				return (*listOfEdges)[i]->getEndOfEdge();
			}
			if (comp(*v, *((*listOfEdges)[i]->getEndOfEdge()))) {
				return (*listOfEdges)[i]->getStartOfEdge();
			}
		}
	}
	return nullptr;
}

template <typename T>
bool GraphOnMatrix<T>::areAdjacent(Vertex<int>* v, Vertex<int>* w) {
	Compare<T, int> comp;
	for (int i = 0; i < listOfEdges->size(); i++) {
		if (comp(*v, *((*listOfEdges)[i]->getStartOfEdge())) || comp(*v, *((*listOfEdges)[i]->getEndOfEdge()))) {
			if (comp(*w, *((*listOfEdges)[i]->getEndOfEdge())) || comp(*w, *((*listOfEdges)[i]->getStartOfEdge()))) {
				return true;
			}
		}
	}
	return false;
}

template <typename T>
void GraphOnMatrix<T>::replaceV(Vertex<int>* v, int number) {
	Compare<T, int> comp;
	for (int i = 0; i < listOfVertices->size(); i++) {
		if (comp(*v, *((*listOfVertices)[i]))) {
			(*listOfVertices)[i]->setPoint(number);
		}
	}
}

template <typename T>
void GraphOnMatrix<T>::replaceE(Edge<T>* e, T weight) {
	Compare<T, int> comp;
	for (int i = 0; i < listOfEdges->size(); i++) {
		if (comp(*e, *((*listOfEdges)[i]))) {
			(*listOfEdges)[i]->setWeight(weight);
		}
	}
}

template <typename T>
void GraphOnMatrix<T>::repairMatrix() {

}

template <typename T>
Vertex<int>* GraphOnMatrix<T>::getStartVertex() {
	return startVertex;
}

