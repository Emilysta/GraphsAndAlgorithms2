#pragma once
#include "Matrix.h"
#include "TypesOfList.h"
#include "Graph.h"

template <typename T>
class GraphOnMatrix : public Graph<T>
{
	Matrix<Edge<T>*>* aMatrix;// macierz s¹siedztwa;
public:
	GraphOnMatrix();
	~GraphOnMatrix();
	void fillGraph(std::string nameOfFile);
	void show();
	void insertVertex(int o);
	void insertEdge(Vertex<int,T>* v,Vertex<int,T>* w,T weight);
	bool removeVertex(Vertex<int,T>* v);
	bool removeEdge(Edge<T>* e);
	List<Edge<T>>* incidentEdges(Vertex<int,T>* v);
	List<Edge<T>>* edges();
	void showEdges();
	List<Vertex<int,T>>* vertices();
	void showVertices();
	Vertex<int,T>** endVertices(Edge<T>* e);
	Vertex<int,T>* opposite(Vertex<int,T>* v, Edge<T>* e);
	bool areAdjacent(Vertex<int,T>* v, Vertex<int,T>* w);//true jesli s¹ s¹siednie, false jeœli nie s¹
	void replaceV(Vertex<int,T>* v, int number);
	void replaceE(Edge<T>* e, T weight);
	void repairMatrix();
	Vertex<int,T>* getStartVertex();
};

template < typename T >
GraphOnMatrix<T>::GraphOnMatrix() {
	this->listOfEdges = new List<Edge<T>>();
	this->listOfVertices = new List<Vertex<int,T>>();
	aMatrix = nullptr;//new Matrix<Edge<T>*>();
	this->startVertex = 0;
}

template < typename T >
GraphOnMatrix<T>::~GraphOnMatrix() {
	aMatrix->setNullptr();
	for (int i = 0; i < this->listOfVertices->size(); i++) {
		for (int j = 0; j < this->listOfVertices->size(); j++) {
			Edge<T>* e= aMatrix->getElement(i, j);
			aMatrix->setElement(i, j, nullptr);
			delete e;
		}
	}
	delete aMatrix;
	delete this->listOfEdges;
	delete this->listOfVertices;
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
			this->listOfVertices->insertOnBack(new Vertex<int, T>(i));
		}
		this->startVertex = (*this->listOfVertices)[start];
		while (file>>row)
		{
			file >> column >> weight;
			Edge<T>* edge = new Edge<T>(weight,nullptr,(*this->listOfVertices)[row],(*this->listOfVertices)[column]); //nullptr bo narzei nie znam miejsca w liscie 
			this->listOfEdges->insertOnBack(edge); // w œrodku funkjci ustawia sie wskaznik na miejsce w liscie
			aMatrix->setElement(row, column, edge);
			aMatrix->setElement(column, row, edge);
			edge = nullptr;
			delete edge;
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
	std::cout << this->listOfEdges->size();
	std::cout << std::endl;
	std::cout << "Liczba wierzcholkow: ";
	std::cout << this->listOfVertices->size();
	std::cout << std::endl;
	std::cout << "Wierzcholek startowy: " << this->startVertex->getPoint() << std::endl;
	//this->showVertices();
	//aMatrix->show();
}

template <typename T>
void GraphOnMatrix<T>::insertVertex(int o) {
	if (o == this->listOfVertices->size()) {
		Vertex<int,T>* v = new Vertex<int,T>(o);
		this->listOfVertices->insertOnBack(v);
		repairMatrix();
	}
	else {
		std::cerr << "nie da siê dodaæ wierzcho³aka o podanym numerze, albo juz istnieje, albo nie mia³by powiazania z numerami porzednimi"<<std::endl;
	}
}

template <typename T>
void GraphOnMatrix<T>::repairMatrix() {
	int size = this->listOfVertices->size();
	Matrix<Edge<T>*> tmp = *aMatrix;
	aMatrix = new Matrix<Edge<T>*>(size);
	for (int i = 0; i < size-1; i++) { //przepisanie macierzy
		for (int j = 0; j < size-1; j++) {
			aMatrix->setElement(i, j, tmp.getElement(i, j));
		}
	}
}

template <typename T>
void GraphOnMatrix<T>::insertEdge(Vertex<int,T>* v, Vertex<int,T>* w, T weight) { //dodawanie tylko jesli takie wierzcholki istnieja
	if ((v->getPoint() >= 0 && v->getPoint() < this->listOfVertices->size()) && (w->getPoint() >= 0 && w->getPoint() < this->listOfVertices->size())) {
		Edge<T>* edge = new Edge<T>(weight, nullptr, v, w);
		this->listOfEdges->insertOnBack(edge);
		aMatrix->setElement(v->getPoint(), w->getPoint(), edge);
		aMatrix->setElement(w->getPoint(), v->getPoint(), edge);
		edge = nullptr;
	}
	else {
		std::cerr << "Jeden z wierzcholkow lub wierzcholki nie istnieja" << std::endl;
	}
}

template <typename T>
bool GraphOnMatrix<T>::removeVertex(Vertex<int,T>* v) { //usuwa powiazania ale zostawia macierz danej wielkosci jaka byla
	if (this->listOfVertices->findElem(v)!=nullptr){
		for (int j = 0; j < this->listOfVertices->size(); j++) {
			if (aMatrix->getElement(j, v->getPoint()) != nullptr) {
				removeEdge(aMatrix->getElement(j, v->getPoint()));
				aMatrix->setElement(j, v->getPoint(), nullptr);
			}
			if (aMatrix->getElement(v->getPoint(), j) != nullptr) {
				removeEdge(aMatrix->getElement(v->getPoint(), j));
				aMatrix->setElement(v->getPoint(), j, nullptr);
			}
		}
		this->listOfVertices->removeAtIndex(v->getPoint());
		std::cout << "usunieto z listy vierzcholokow wraz z powiazaniami" << std::endl;
		return true;
	}
	std::cerr << "nie usunieto wierzcholka" << std::endl;
	return false;
} 

template <typename T>
bool GraphOnMatrix<T>::removeEdge(Edge<T>* e) {//usuwa krawedz z istniejacych
	Compare<T, int> comp;

	for (int i = 0; i < this->listOfEdges->size(); i++) {
		if (comp(*e, *(*this->listOfEdges)[i])) {
			int row = e->getStartOfEdge()->getPoint();
			int column = e->getEndOfEdge()->getPoint();
			aMatrix->setElement(row, column, nullptr);
			aMatrix->setElement(column, row, nullptr);
			this->listOfEdges->removeAtIndex(i);
			return true;
		}
	}
	std::cerr << "nie usunieto krawedzi" << std::endl;
	return false;
}

template <typename T>
List<Edge<T>>* GraphOnMatrix<T>::incidentEdges(Vertex<int,T>* v) {
	List<Edge<T>>* list = new List<Edge<T>>();
	for (int i = 0; i < this->listOfVertices->size(); i++) {
		if (aMatrix->getElement(v->getPoint(),i) != nullptr)
			list->insertOnBack(aMatrix->getElement(v->getPoint(), i));
	}
	return list;
}

template <typename T>
void GraphOnMatrix<T>::showEdges() {
	std::cout << "Start   End   Weight" << std::endl;
	this->listOfEdges->showList();
}

template <typename T>
List<Edge<T>>* GraphOnMatrix<T>::edges() {
	return this->listOfEdges;
}

template <typename T>
void GraphOnMatrix<T>::showVertices() {
	this->listOfVertices->showList();
}

template <typename T>
List<Vertex<int,T>>* GraphOnMatrix<T>::vertices() {
	return this->listOfVertices;
}

template <typename T>
Vertex<int,T>** GraphOnMatrix<T>::endVertices(Edge<T>* e){
	Vertex<int,T>** array = new Vertex<int,T>*[2];
	array[0] = e->getStartOfEdge();
	array[1] = e->getEndOfEdge();
	return array;
}

template <typename T>
Vertex<int,T>* GraphOnMatrix<T>::opposite(Vertex<int,T>* v, Edge<T>* e) {

	if (v->getPoint()!= e->getStartOfEdge()->getPoint()) {
		return e->getStartOfEdge();
	}
	else{
		return e->getEndOfEdge();
	}
	//return nullptr;
}

template <typename T>
bool GraphOnMatrix<T>::areAdjacent(Vertex<int,T>* v, Vertex<int,T>* w) {
	if (aMatrix->getElement(v->getPoint(), w->getPoint()) != nullptr) {
		return true;
	}
	return false;
}

template <typename T>
void GraphOnMatrix<T>::replaceV(Vertex<int,T>* v, int number) {
	v->setPoint(number);
}

template <typename T>
void GraphOnMatrix<T>::replaceE(Edge<T>* e, T weight) {
	e->setWeight(weight);
}

template <typename T>
Vertex<int,T>* GraphOnMatrix<T>::getStartVertex() {
	return this->startVertex;
}

