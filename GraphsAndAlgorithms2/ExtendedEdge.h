#pragma once
#include "Vertex.h"
template <typename T>
class List;
template <typename T>
class Element;
template <typename t>
class ExtendedEdge: public Edge<t>
{
	List<ExtendedEdge<t>>* incidentToStart;
	List<ExtendedEdge<t>>* incidentToEnd;

public:
	ExtendedEdge() {
		this->whereInList = nullptr;
		this->weight = -100;
		this->startOfEdge = nullptr;
		this->endOfEdge = nullptr;
		incidentToStart = new List<ExtendedEdge<t>>();
		incidentToEnd = new List<ExtendedEdge<t>>();
	}
	~ExtendedEdge() {
		this->whereInList = nullptr;
		this->startOfEdge = nullptr;
		this->endOfEdge = nullptr;
		incidentToStart = nullptr;
		incidentToEnd = nullptr;
	}
	ExtendedEdge(t newWeight, Element<Edge<t>>* newWhere, Vertex<int,t>* newStart, Vertex<int,t>* newEnd) {
		this->weight = newWeight;
		this->whereInList = newWhere;
		this->startOfEdge = dynamic_cast<ExtendedVertex<int, t>*>(newStart);
		this->endOfEdge = dynamic_cast<ExtendedVertex<int, t>*>(newEnd);
		incidentToStart = new List<ExtendedEdge<t>>();
		incidentToEnd = new List<ExtendedEdge<t>>();

	}
	const t& getWeight() const;
	Element<Edge<t>>* getPositionInList() const;
	ExtendedVertex<int, t>* getStartOfEdge() const;
	ExtendedVertex<int, t>* getEndOfEdge() const;
	void setWeight(t newWeight);
	void setPositionInList(Element<ExtendedEdge<t>>* newMyself);
	void show();
	void toShow();
	bool isTheSame(ExtendedEdge<t> _edge);
	void setIncidentToStart(List<ExtendedEdge<t>>* newIncident);
	void setIncidentToEnd(List<ExtendedEdge<t>>* newIncident);
	List<ExtendedEdge<t>>* getIncidentToStart();
	List<ExtendedEdge<t>>* getIncidentToEnd();

};

template <typename t>
const t& ExtendedEdge<t>::getWeight() const {
	return this->weight;
}

template <typename t>
Element<Edge<t>>* ExtendedEdge<t>::getPositionInList() const {
	return this->whereInList;
}

template <typename t>
ExtendedVertex<int, t>* ExtendedEdge<t>::getStartOfEdge() const {
	return dynamic_cast<ExtendedVertex<int, t>*>(this->startOfEdge);
}

template <typename t>
ExtendedVertex<int, t>* ExtendedEdge<t>::getEndOfEdge() const {
	return dynamic_cast<ExtendedVertex<int, t>*>(this->endOfEdge);
}

template <typename t>
void ExtendedEdge<t>::setWeight(t newWeight) {
	this->weight = newWeight;
}

template <typename t>
void ExtendedEdge<t>::setPositionInList(Element<ExtendedEdge<t>>* newMyself) {
	this->whereInList = newMyself;
}

template <typename t>
void ExtendedEdge<t>::show() {
	this->startOfEdge->show();
	std::cout << "\t";
	this->endOfEdge->show();
	std::cout << "\t";
	std::cout << this->weight << "\n";
}

template <typename t>
void ExtendedEdge<t>::toShow() {
	this->startOfEdge->show();
	std::cout << ".";
	this->endOfEdge->show();
	std::cout << ".";
	std::cout << this->weight;
}
template <typename t>
bool ExtendedEdge<t>::isTheSame(ExtendedEdge<t> _edge) {

	if (this->weight == _edge.getWeight() && this->startOfEdge == _edge->getStartOfEdge() && this->endOfEdge == _edge->getEndOfEdge()) {
		return true;
	}
	return false;
}
template <typename t>
void ExtendedEdge<t>::setIncidentToStart(List<ExtendedEdge<t>>* newIncident) {
	incidentToStart = newIncident;
}

template <typename t>
void ExtendedEdge<t>::setIncidentToEnd(List<ExtendedEdge<t>>* newIncident) {
	incidentToStart = newIncident;
}

template <typename t>
List<ExtendedEdge<t>>* ExtendedEdge<t>::getIncidentToStart() {
	return incidentToStart;
}

template <typename t>
List<ExtendedEdge<t>>* ExtendedEdge<t>::getIncidentToEnd() {
	return incidentToEnd;
}