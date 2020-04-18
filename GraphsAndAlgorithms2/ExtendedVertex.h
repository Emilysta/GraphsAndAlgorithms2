#pragma once
#include "Vertex.h"
template <typename T>
class ExtendedEdge;
template <typename T>
class List;
template <typename T>
class Element;
template <typename t,typename T>
class ExtendedVertex : public Vertex<t,T>
{
	List<Edge<T>>* incidentEdges;

public:
	ExtendedVertex() {
		this->whereInList = nullptr;
		this->point = -100;
		incidentEdges = new List<Edge<T>>();
	}
	~ExtendedVertex() {
		this->whereInList = nullptr;
		incidentEdges = nullptr;
	}
	ExtendedVertex(t newPoint) {
		this->point = newPoint;
		this->whereInList = nullptr;
		incidentEdges = new List<Edge<T>>();
	}
	const t& getPoint() const;
	const Element<Vertex<t,T>>* getPositionInList() const;
	void setPoint(t newPoint);
	void setPositionInList(Element<ExtendedVertex<t,T>>* newMyself);
	void show();
	bool isTheSame(ExtendedVertex<t,T> _vertex);
	void setIncidentEdges(List<Edge<T>>* newIncident);
	List<Edge<T>>* getIncidentEdges();
};

template <typename t,typename T>
const t& ExtendedVertex<t,T>::getPoint() const {
	return this->point;
}

template <typename t, typename T>
const Element<Vertex<t,T>>* ExtendedVertex<t,T>::getPositionInList() const {
	return this->whereInList;
}

template <typename t, typename T>
void ExtendedVertex<t,T>::setPoint(t newPoint) {
	this->point = newPoint;
}

template <typename t, typename T>
void ExtendedVertex<t,T>::setPositionInList(Element<ExtendedVertex<t,T>>* newMyself) {
	this->whereInList = newMyself;
}

template <typename t, typename T>
void ExtendedVertex<t,T>::show() {
	std::cout << this->point;
}

template <typename t, typename T>
bool ExtendedVertex<t,T>::isTheSame(ExtendedVertex<t,T> _vertex) {

	if (this->point == _vertex.getPoint()) {
		return true;
	}
	return false;
}

template <typename t, typename T>
void ExtendedVertex<t,T>::setIncidentEdges(List<Edge<T>>* newIncident) {
	incidentEdges = newIncident;
}

template <typename t, typename T>
List<Edge<T>>* ExtendedVertex<t,T>::getIncidentEdges() {
	return incidentEdges;
}