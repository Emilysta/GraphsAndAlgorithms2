#pragma once
#include "Vertex.h"
template <typename T>
class List;
template <typename T>
class Element;
template <typename t>
class ExtendedEdge
{
	t weight;
	Element<ExtendedEdge<t>>* whereInList;
	ExtendedVertex<int,t>* startOfEdge;
	ExtendedVertex<int,t>* endOfEdge;
	List<ExtendedEdge<t>>* incidentToStart;
	List<ExtendedEdge<t>>* incidentToEnd;

public:
	ExtendedEdge() {
		whereInList = nullptr;
		weight = -100;
		startOfEdge = nullptr;
		endOfEdge = nullptr;
		incidentToStart = new List<ExtendedEdge<t>>();
		incidentToEnd = new List<ExtendedEdge<t>>();
	}
	~ExtendedEdge() {
		whereInList = nullptr;
		startOfEdge = nullptr;
		endOfEdge = nullptr;
		incidentToStart = nullptr;
		incidentToEnd = nullptr;
	}
	ExtendedEdge(t newWeight, Element<ExtendedEdge<t>>* newWhere, ExtendedVertex<int,t>* newStart, ExtendedVertex<int,t>* newEnd) {
		weight = newWeight;
		whereInList = newWhere;
		startOfEdge = newStart;
		endOfEdge = newEnd;
		incidentToStart = new List<ExtendedEdge<t>>();
		incidentToEnd = new List<ExtendedEdge<t>>();

	}
	const t& getWeight() const;
	Element<ExtendedEdge<t>>* getPositionInList() const;
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
	return weight;
}

template <typename t>
Element<ExtendedEdge<t>>* ExtendedEdge<t>::getPositionInList() const {
	return whereInList;
}

template <typename t>
ExtendedVertex<int, t>* ExtendedEdge<t>::getStartOfEdge() const {
	return startOfEdge;
}

template <typename t>
ExtendedVertex<int, t>* ExtendedEdge<t>::getEndOfEdge() const {
	return endOfEdge;
}

template <typename t>
void ExtendedEdge<t>::setWeight(t newWeight) {
	weight = newWeight;
}

template <typename t>
void ExtendedEdge<t>::setPositionInList(Element<ExtendedEdge<t>>* newMyself) {
	whereInList = newMyself;
}

template <typename t>
void ExtendedEdge<t>::show() {
	startOfEdge->show();
	std::cout << "\t";
	endOfEdge->show();
	std::cout << "\t";
	std::cout << weight << "\n";
}

template <typename t>
void ExtendedEdge<t>::toShow() {
	startOfEdge->show();
	std::cout << ".";
	endOfEdge->show();
	std::cout << ".";
	std::cout << weight;
}
template <typename t>
bool ExtendedEdge<t>::isTheSame(ExtendedEdge<t> _edge) {

	if (weight == _edge.getWeight() && startOfEdge == _edge->getStartOfEdge() && endOfEdge == _edge->getEndOfEdge()) {
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