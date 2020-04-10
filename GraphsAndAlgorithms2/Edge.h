#pragma once
#include "Vertex.h"
template <typename T>
class Element;
template <typename t>
class Edge 
{
	t weight;
	Element<Edge<t>>* whereInList;
	Vertex<int>* startOfEdge;
	Vertex<int>* endOfEdge;

public:
	Edge() {
		whereInList = nullptr;
		weight = -100;
		startOfEdge = nullptr;
		endOfEdge = nullptr;
	}
	~Edge() {
		delete whereInList;
		delete startOfEdge;
		delete endOfEdge;
	}
	Edge(t newWeight, Element<Edge<t>>* newWhere, Vertex<int>* newStart,Vertex<int>* newEnd) {
		weight = newWeight;
		whereInList = newWhere;
		startOfEdge = newStart;
		endOfEdge = newEnd;
	}
	const t& getWeight() const;
	Element<Edge<t>>* getPositionInList() const;
	Vertex<int>* getStartOfEdge() const;
	Vertex<int>* getEndOfEdge() const;
	void setWeight(t newWeight);
	void setPositionInList(Element<Edge<t>>* newMyself);
	void show();
	void toShowInMatrix();
	bool isTheSame(Edge<t> _edge);
};

template <typename t>
const t& Edge<t>::getWeight() const {
	return weight;
}

template <typename t>
Element<Edge<t>>* Edge<t>::getPositionInList() const {
	return whereInList;
}

template <typename t>
Vertex<int>* Edge<t>::getStartOfEdge() const {
	return whereInList;
}

template <typename t>
Vertex<int>* Edge<t>::getEndOfEdge() const {
	return whereInList;
}

template <typename t>
void Edge<t>::setWeight(t newWeight) {
	weight = newWeight;
}

template <typename t>
void Edge<t>::setPositionInList(Element<Edge<t>>* newMyself) {
	whereInList = newMyself;
}

template <typename t>
void Edge<t>::show() {
	startOfEdge->show();
	std::cout << "\t";
	endOfEdge->show();
	std::cout << "\t";
	std::cout << weight<<"\n";
}

template <typename t>
void Edge<t>::toShowInMatrix() {
	startOfEdge->show();
	std::cout << ".";
	endOfEdge->show();
	std::cout << ".";
	std::cout << weight;
}
template <typename t>
bool Edge<t>::isTheSame(Edge<t> _edge) {

	if (weight == _edge.getWeight() && startOfEdge == _edge->getStartOfEdge() && endOfEdge == _edge->getEndOfEdge()) {
		return true;
	}
	return false;
}