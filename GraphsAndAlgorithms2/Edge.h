#pragma once
#include "Vertex.h"
template <typename T>
class Element;
template <typename t>
class Edge 
{
protected:
	t weight;
	Element<Edge<t>>* whereInList;
	Vertex<int,t>* startOfEdge;
	Vertex<int,t>* endOfEdge;

public:
	Edge() {
		whereInList = nullptr;
		weight = -100;
		startOfEdge = nullptr;
		endOfEdge = nullptr;
	}
	~Edge() {
		whereInList = nullptr;
		startOfEdge = nullptr;
		endOfEdge = nullptr;
	}
	Edge(t newWeight, Element<Edge<t>>* newWhere, Vertex<int,t>* newStart,Vertex<int,t>* newEnd) {
		weight = newWeight;
		whereInList = newWhere;
		startOfEdge = newStart;
		endOfEdge = newEnd;
	}
	virtual const t& getWeight() const;
	virtual Element<Edge<t>>* getPositionInList() const;
	virtual Vertex<int,t>* getStartOfEdge() const;
	virtual Vertex<int,t>* getEndOfEdge() const;
	virtual void setWeight(t newWeight);
	virtual void setPositionInList(Element<Edge<t>>* newMyself);
	virtual void show();
	virtual void toShowInMatrix();
	virtual bool isTheSame(Edge<t> _edge);
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
Vertex<int,t>* Edge<t>::getStartOfEdge() const {
	return startOfEdge;
}

template <typename t>
Vertex<int,t>* Edge<t>::getEndOfEdge() const {
	return endOfEdge;
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

	if (weight == _edge.getWeight() && startOfEdge == _edge.getStartOfEdge() && endOfEdge == _edge.getEndOfEdge()) {
		return true;
	}
	return false;
}