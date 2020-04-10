#pragma once
template <typename T>
class Element;
template <typename t>
class Vertex
{
	t point;
	Element<Vertex<t>>* whereInList;
public:
	Vertex() {
		whereInList = nullptr;
		point = -100;
	}
	~Vertex() {
		delete whereInList;
	}
	Vertex(t newPoint) {
		point = newPoint;
		whereInList = nullptr;
	}
	const t& getPoint() const;
	const Element<Vertex<t>>* getPositionInList() const;
	void setPoint(t newPoint);
	void setPositionInList(Element<Vertex<t>>* newMyself);
	void show();
	bool isTheSame(Vertex<t> _vertex);
};

template <typename t>
const t& Vertex<t>::getPoint() const {
	return point;
}

template <typename t>
const Element<Vertex<t>>* Vertex<t>::getPositionInList() const{
	return whereInList;
}

template <typename t>
void Vertex<t>::setPoint(t newPoint) {
	point = newPoint;
}

template <typename t>
void Vertex<t>::setPositionInList(Element<Vertex<t>>* newMyself) {
	whereInList = newMyself;
}

template <typename t>
void Vertex<t>::show() {
	std::cout << point;
}

template <typename t>
bool Vertex<t>::isTheSame(Vertex<t> _vertex) {

	if (point == _vertex.getPoint()) {
		return true;
	}
	return false;
}