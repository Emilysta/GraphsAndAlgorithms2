#pragma once
template <typename T>
class ExtendedEdge;
template <typename T>
class List;
template <typename T>
class Element;
template <typename t,typename T>
class ExtendedVertex
{
	t point;
	Element<ExtendedVertex<t,T>>* whereInList;
	List<ExtendedEdge<T>>* incidentEdges;

public:
	ExtendedVertex() {
		whereInList = nullptr;
		point = -100;
		incidentEdges = new List<ExtendedEdge<T>>();
	}
	~ExtendedVertex() {
		whereInList = nullptr;
		incidentEdges = nullptr;
	}
	ExtendedVertex(t newPoint) {
		point = newPoint;
		whereInList = nullptr;
		incidentEdges = new List<ExtendedEdge<T>>();
	}
	const t& getPoint() const;
	const Element<ExtendedVertex<t,T>>* getPositionInList() const;
	void setPoint(t newPoint);
	void setPositionInList(Element<ExtendedVertex<t,T>>* newMyself);
	void show();
	bool isTheSame(ExtendedVertex<t,T> _vertex);
	void setIncidentEdges(List<ExtendedEdge<T>>* newIncident);
	List<ExtendedEdge<T>>* getIncidentEdges();
};

template <typename t,typename T>
const t& ExtendedVertex<t,T>::getPoint() const {
	return point;
}

template <typename t, typename T>
const Element<ExtendedVertex<t,T>>* ExtendedVertex<t,T>::getPositionInList() const {
	return whereInList;
}

template <typename t, typename T>
void ExtendedVertex<t,T>::setPoint(t newPoint) {
	point = newPoint;
}

template <typename t, typename T>
void ExtendedVertex<t,T>::setPositionInList(Element<ExtendedVertex<t,T>>* newMyself) {
	whereInList = newMyself;
}

template <typename t, typename T>
void ExtendedVertex<t,T>::show() {
	std::cout << point;
}

template <typename t, typename T>
bool ExtendedVertex<t,T>::isTheSame(ExtendedVertex<t,T> _vertex) {

	if (point == _vertex.getPoint()) {
		return true;
	}
	return false;
}

template <typename t, typename T>
void ExtendedVertex<t,T>::setIncidentEdges(List<ExtendedEdge<T>>* newIncident) {
	incidentEdges = newIncident;
}

template <typename t, typename T>
List<ExtendedEdge<T>>* ExtendedVertex<t,T>::getIncidentEdges() {
	return incidentEdges;
}