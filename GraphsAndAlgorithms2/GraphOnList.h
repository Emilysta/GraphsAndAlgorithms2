#pragma once
#include "Matrix.h"
#include "TypesOfList.h"
#include "ExtendedEdge.h"
#include "Graph.h"
#include "Vertex.h"

template <typename T>
class GraphOnList : public Graph<T>
{
	List<List<Edge<T>>>* aList;// lista s¹siedztwa;

public:
	GraphOnList();
	~GraphOnList();
	void fillGraph(std::string nameOfFile);
	void show();
	void insertVertex(int o);
	void insertEdge(ExtendedVertex<int,T>* v, ExtendedVertex<int,T>* w, T weight);
	//bool removeVertex(ExtendedVertex<int,T>* v);
	bool removeEdge(Edge<T>* e);
	List<Edge<T>>* incidentEdges(Vertex<int,T>* v);
	List<Edge<T>>* edges();
	void showEdges();
	ListV* vertices();
	void showVertices();
	ExtendedVertex<int,T>** endVertices(Edge<T>* e);
	Vertex<int,T>* opposite(Vertex<int,T>* v, Edge<T>* e);
	bool areAdjacent(ExtendedVertex<int,T>* v, ExtendedVertex<int,T>* w);//true jesli s¹ s¹siednie, false jeœli nie s¹
	//void replaceV(ExtendedVertex<int,T>* v, int number);
	//void replaceE(Edge<T>* e, T weight);
	Vertex<int,T>* getStartVertex();
};

template < typename T >
GraphOnList<T>::GraphOnList() {
	this->listOfEdges = new List<Edge<T>>();
	this->listOfVertices = new List<Vertex<int,T>>();
	aList = new List<List<Edge<T>>>();
	this->startVertex = 0;
}

template < typename T >
GraphOnList<T>::~GraphOnList() {
	
	for (int i = 0; i < this->listOfVertices->size(); i++)
		dynamic_cast<ExtendedVertex<int,T>*>((*this->listOfVertices)[0])->setIncidentEdges(nullptr);
	delete this->aList;
	delete this->listOfEdges;
	delete this->listOfVertices;
}

template <typename T>
void GraphOnList<T>::fillGraph(std::string nameOfFile) { //do poprawy Bardzo Wazne
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
		for (int i = 0; i < numberOfVertices; i++) {
			aList->insertOnBack(new List<Edge<T>>());
		}
		for (int i = 0; i < numberOfVertices; i++) {
			ExtendedVertex<int, T>* v = new ExtendedVertex<int, T>(i);
			v->setIncidentEdges((*aList)[i]);
			this->listOfVertices->insertOnBack(v);
		}
		this->startVertex = (*this->listOfVertices)[start];
		while (file>>row)
		{
			file >> column >> weight;
			Edge<T>* edge = 
				new Edge<T>(weight, nullptr, dynamic_cast<ExtendedVertex<int, T>*>((*this->listOfVertices)[row]), dynamic_cast<ExtendedVertex<int, T>*>((*this->listOfVertices)[column])); //nullptr bo narazie nie znamy miejsca w liscie 
			this->listOfEdges->insertOnBack(edge); // w œrodku funkcji ustawia sie wskaznik na miejsce w liscie
			(*aList)[row]->insertOnBack(edge);
			(*aList)[column]->insertOnBack(edge);	
		}
	}
	else {
		std::cout << "Plik nie jest poprawny!";
	}
	file.close();
}

template <typename T>
void GraphOnList<T>::show() {
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
void GraphOnList<T>::insertVertex(int o) {
	if (o == this->listOfVertices->size()) {
		ExtendedVertex<int,T>* v = new ExtendedVertex<int,T>(o);
		this->listOfVertices->insertOnBack(v);
		aList->insertOnBack(new List<Edge<T>>());
		v->setIncidentEdges((*aList)[aList->size() - 1]);
	}
	else {
		std::cerr << "nie da siê dodaæ wierzcho³aka o podanym numerze, albo juz istnieje, albo nie mia³by powiazania z numerami porzednimi" << std::endl;
	}
}

template <typename T>
void GraphOnList<T>::insertEdge(ExtendedVertex<int,T>* v, ExtendedVertex<int,T>* w, T weight) { //dodawanie tylko jesli takie wierzcholki istnieja
	if ((v->getPoint() >= 0 && v->getPoint() < this->listOfVertices->size()) &&
		(w->getPoint() >= 0 && w->getPoint() < this->listOfVertices->size())) {
		Edge<T>* edge = new Edge<T>(weight, nullptr, v, w);
		this->listOfEdges->insertOnBack(edge);
		(*aList)[v->getPoint()]->insertOnBack(edge);
		(*aList)[w->getPoint()]->insertOnBack(edge);
		edge = nullptr;
	}
	else {
		std::cerr << "Jeden z wierzcholkow lub wierzcholki nie istnieja" << std::endl;
	}
}

//template <typename T>
//bool GraphOnList<T>::removeVertex(ExtendedVertex<int,T>* v) { //usuwa powiazania ale zostawia 
//	if (listOfVertices->findElem(v) != nullptr) { //macierz danej wielkosci jaka byla
//		for (int j = 0; j < listOfVertices->size(); j++) {
//			if (aMatrix->getElement(j, v->getPoint()) != nullptr) {
//				removeEdge(aMatrix->getElement(j, v->getPoint()));
//				
//			}
//			if (aMatrix->getElement(v->getPoint(), j) != nullptr) {
//				removeEdge(aMatrix->getElement(v->getPoint(), j));
//				
//			}
//		}
//		listOfVertices->removeAtIndex(v->getPoint());
//		std::cout << "usunieto z listy vierzcholokow wraz z powiazaniami" << std::endl;
//		return true;
//	}
//	std::cerr << "nie usunieto wierzcholka" << std::endl;
//	return false;
//}
template <typename T>
bool GraphOnList<T>::removeEdge(Edge<T>* e) {//usuwa krawedz z istniejacych
	Compare<T, int> comp;
	if (e->getStartOfEdge()->getPoint() >= 0 && e->getStartOfEdge()->getPoint() < this->listOfVertices->size()
		&& e->getEndOfEdge()->getPoint() >= 0 && e->getEndOfEdge()->getPoint() < this->listOfVertices->size()) {
		(*aList)[e->getEndOfEdge()->getPoint()]->findAndDelete(e) = nullptr;
		(*aList)[e->getStartOfEdge()->getPoint()]->findAndDelete(e) = nullptr;
		this->listOfEdges->findAndDelete(e);
		return true;
	}
	std::cerr << "nie usunieto krawedzi" << std::endl;
	return false;
}
//do sprawdzenia
template <typename T>
List<Edge<T>>* GraphOnList<T>::incidentEdges(Vertex<int,T>* v) {
	return (*aList)[v->getPoint()];
}
//do sprawdzenia
template <typename T>
void GraphOnList<T>::showEdges() {
	std::cout << "Start   End   Weight" << std::endl;
	this->listOfEdges->showList();
}

template <typename T>
List<Edge<T>>* GraphOnList<T>::edges() {
	return this->listOfEdges;
}

template <typename T>
void GraphOnList<T>::showVertices() {
	this->listOfVertices->showList();
}

template <typename T>
ListV* GraphOnList<T>::vertices() {
	return this->listOfVertices;
}

template <typename T>
ExtendedVertex<int,T>** GraphOnList<T>::endVertices(Edge<T>* e) {
	ExtendedVertex<int,T>** array = new ExtendedVertex<int,T> * [2];
	array[0] = e->getStartOfEdge();
	array[1] = e->getEndOfEdge();
	return array;
}
//do sprawdzenia
template <typename T>
Vertex<int,T>* GraphOnList<T>::opposite(Vertex<int,T>* v, Edge<T>* e) {

	if (v->getPoint() != e->getStartOfEdge()->getPoint()) {
		return e->getStartOfEdge();
	}
	else {
		return e->getEndOfEdge();
	}
}
//do sprawdzenia
template <typename T>
bool GraphOnList<T>::areAdjacent(ExtendedVertex<int,T>* v, ExtendedVertex<int,T>* w) {

	for (int i = 0; i < (*aList)[v->getPoint()]->size(); i++) {
		if ( (*(*aList)[v->getPoint()])[i].GetEndOfEdge() == w->getPoint() || (*(*aList)[v->getPoint()])[i].GetStartOfEdge() == w->getPoint()) {
			return true;
		}
	}
	return false;
}
//do sprawdzenia

//
//template <typename T>
//void GraphOnList<T>::replaceV(ExtendedVertex<int,T>* v, int number) {
//	v->setPoint(number);
//}
//
//template <typename T>
//void GraphOnList<T>::replaceE(Edge<T>* e, T weight) {
//	e->setWeight(weight);
//}
//
template <typename T>
Vertex<int,T>* GraphOnList<T>::getStartVertex() {
	return this->startVertex;
}

