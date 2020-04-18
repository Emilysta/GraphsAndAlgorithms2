#pragma once
#include "Matrix.h"
#include "TypesOfList.h"
#include "ExtendedEdge.h"

template <typename T>
class GraphOnList
{
	List<ExtendedVertex<int,T>>* listOfVertices;
	List<ExtendedEdge<T>>* listOfEdges;
	List<List<ExtendedEdge<T>>>* aList;// lista s¹siedztwa;
	ExtendedVertex<int,T>* startVertex;

public:
	GraphOnList();
	~GraphOnList();
	void fillGraph(std::string nameOfFile);
	void show();
	void insertVertex(int o);
	void insertEdge(ExtendedVertex<int,T>* v, ExtendedVertex<int,T>* w, T weight);
	//bool removeVertex(ExtendedVertex<int,T>* v);
	bool removeEdge(ExtendedEdge<T>* e);
	//List<Edge<T>>* incidentEdges(ExtendedVertex<int,T>* v);
	//List<Edge<T>>* edges();
	//void showEdges();
	//ListV* vertices();
	//void showVertices();
	//ExtendedVertex<int,T>** endVertices(Edge<T>* e);
	//ExtendedVertex<int,T>* opposite(ExtendedVertex<int,T>* v, Edge<T>* e);
	//bool areAdjacent(ExtendedVertex<int,T>* v, ExtendedVertex<int,T>* w);//true jesli s¹ s¹siednie, false jeœli nie s¹
	//void replaceV(ExtendedVertex<int,T>* v, int number);
	//void replaceE(Edge<T>* e, T weight);
	//ExtendedVertex<int,T>* getStartVertex();
};

template < typename T >
GraphOnList<T>::GraphOnList() {
	listOfEdges = new List<ExtendedEdge<T>>();
	listOfVertices = new List<ExtendedVertex<int,T>>();
	aList = new List<List<ExtendedEdge<T>>>();
	startVertex = 0;
}

template < typename T >
GraphOnList<T>::~GraphOnList() {
	
	for (int i = 0; i < listOfVertices->size(); i++)
		(*listOfVertices)[0]->setIncidentEdges(nullptr);
	for (int i = 0; i < aList->size(); i++) {
		delete (*aList)[i];// = nullptr;
	}
	delete listOfEdges;
	delete listOfVertices;
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
			listOfVertices->insertOnBack(new ExtendedVertex<int,T>(i)); 
		}
		for (int i = 0; i < numberOfVertices; i++) {
			aList->insertOnBack(new List<ExtendedEdge<T>>());
		}
		startVertex = (*listOfVertices)[start];
		int i = 0;
		while (file>>row)
		{
			i++;
			file >> column >> weight;
			ExtendedEdge<T>* edge = 
				new ExtendedEdge<T>(weight, nullptr, (*listOfVertices)[row], (*listOfVertices)[column]); //nullptr bo narazie nie znamy miejsca w liscie 
			listOfEdges->insertOnBack(edge); // w œrodku funkcji ustawia sie wskaznik na miejsce w liscie
			(*aList)[row]->insertOnBack(edge);
			(*aList)[column]->insertOnBack(edge);	
		}
		std::cout <<"Liczba"<< i<<std::endl;
	}
	else {
		std::cout << "Plik nie jest poprawny!";
	}
	file.close();
}

template <typename T>
void GraphOnList<T>::show() {
	std::cout << "Liczba krawedzi: ";
	std::cout << listOfEdges->size();
	std::cout << std::endl;
	std::cout << "Liczba wierzcholkow: ";
	std::cout << listOfVertices->size();
	std::cout << std::endl;
	std::cout << "Wierzcholek startowy: " << startVertex->getPoint() << std::endl;
	//this->showVertices();
	//aMatrix->show();
}

template <typename T>
void GraphOnList<T>::insertVertex(int o) {
	if (o == listOfVertices->size()) {
		ExtendedVertex<int,T>* v = new ExtendedVertex<int,T>(o);
		listOfVertices->insertOnBack(v);
		aList->insertOnBack(new List<ExtendedEdge<T>>());
	}
	else {
		std::cerr << "nie da siê dodaæ wierzcho³aka o podanym numerze, albo juz istnieje, albo nie mia³by powiazania z numerami porzednimi" << std::endl;
	}
}

template <typename T>
void GraphOnList<T>::insertEdge(ExtendedVertex<int,T>* v, ExtendedVertex<int,T>* w, T weight) { //dodawanie tylko jesli takie wierzcholki istnieja
	if ((v->getPoint() >= 0 && v->getPoint() < listOfVertices->size()) && 
		(w->getPoint() >= 0 && w->getPoint() < listOfVertices->size())) {
		ExtendedEdge<T>* edge = new ExtendedEdge<T>(weight, nullptr, v, w);
		listOfEdges->insertOnBack(edge);
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
bool GraphOnList<T>::removeEdge(ExtendedEdge<T>* e) {//usuwa krawedz z istniejacych
	Compare<T, int> comp;
	if (e->getStartOfEdge()->getPoint() >= 0 && e->getStartOfEdge()->getPoint() < listOfVertices->size()
		&& e->getEndOfEdge()->getPoint() >= 0 && e->getEndOfEdge()->getPoint() < listOfVertices->size()) {
		(*aList)[e->getEndOfEdge()->getPoint()]->findAndDelete(e) = nullptr;
		(*aList)[e->getStartOfEdge()->getPoint()]->findAndDelete(e) = nullptr;
		listOfEdges->findAndDelete(e);
		return true;
	}
	std::cerr << "nie usunieto krawedzi" << std::endl;
	return false;
}
//
//template <typename T>
//List<Edge<T>>* GraphOnList<T>::incidentEdges(ExtendedVertex<int,T>* v) {
//	List<Edge<T>>* list = new List<Edge<T>>();
//	for (int i = 0; i < listOfVertices->size(); i++) {
//		if (aMatrix->getElement(v->getPoint(), i) != nullptr)
//			list->insertOnBack(aMatrix->getElement(v->getPoint(), i));
//	}
//	return list;
//}
//
//template <typename T>
//void GraphOnList<T>::showEdges() {
//	std::cout << "Start   End   Weight" << std::endl;
//	listOfEdges->showList();
//}
//
//template <typename T>
//List<Edge<T>>* GraphOnList<T>::edges() {
//	return listOfEdges;
//}
//
//template <typename T>
//void GraphOnList<T>::showVertices() {
//	listOfVertices->showList();
//}
//
//template <typename T>
//ListV* GraphOnList<T>::vertices() {
//	return listOfVertices;
//}
//
//template <typename T>
//ExtendedVertex<int,T>** GraphOnList<T>::endVertices(Edge<T>* e) {
//	ExtendedVertex<int,T>** array = new ExtendedVertex<int,T> * [2];
//	array[0] = e->getStartOfEdge();
//	array[1] = e->getEndOfEdge();
//	return array;
//}
//
//template <typename T>
//ExtendedVertex<int,T>* GraphOnList<T>::opposite(ExtendedVertex<int,T>* v, Edge<T>* e) {
//
//	if (v->getPoint() != e->getStartOfEdge()->getPoint()) {
//		return e->getStartOfEdge();
//	}
//	else {
//		return e->getEndOfEdge();
//	}
//}
//
//template <typename T>
//bool GraphOnList<T>::areAdjacent(ExtendedVertex<int,T>* v, ExtendedVertex<int,T>* w) {
//	if (aMatrix->getElement(v->getPoint(), w->getPoint()) != nullptr) {
//		return true;
//	}
//	return false;
//}
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
//template <typename T>
//ExtendedVertex<int,T>* GraphOnList<T>::getStartVertex() {
//	return startVertex;
//}

