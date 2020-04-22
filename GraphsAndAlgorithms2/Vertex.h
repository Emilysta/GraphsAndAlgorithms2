#pragma once
template <typename T>
class Element;
template <typename t,typename T> // dwa typy poniewaz wersja rozszerzona potrzebuje dwóch
class Vertex
{
protected:
	t point;
	Element<Vertex<t,T>>* whereInList;
public:
	Vertex() {
		whereInList = nullptr;
		point = -100;
	}
	~Vertex() {
		whereInList = nullptr;
		delete whereInList;
	}
	Vertex(t newPoint) {
		point = newPoint;
		whereInList = nullptr;
	}
	virtual const t& getPoint() const;
	virtual const Element<Vertex<t,T>>* getPositionInList() const;
	virtual void setPoint(t newPoint);
	virtual void setPositionInList(Element<Vertex<t,T>>* newMyself);
	virtual void show();
	virtual bool isTheSame(Vertex<t,T> _vertex);
};

template <typename t, typename T>
const t& Vertex<t,T>::getPoint() const {
	return point;
}

template <typename t, typename T>
const Element<Vertex<t,T>>* Vertex<t,T>::getPositionInList() const{
	return whereInList;
}

template <typename t, typename T>
void Vertex<t,T>::setPoint(t newPoint) {
	point = newPoint;
}

template <typename t, typename T>
void Vertex<t,T>::setPositionInList(Element<Vertex<t,T>>* newMyself) {
	whereInList = newMyself;
}

template <typename t, typename T>
void Vertex<t,T>::show() {
	std::cout << point;
}

template <typename t, typename T>
bool Vertex<t,T>::isTheSame(Vertex<t,T> _vertex) {

	if (point == _vertex.getPoint()) {
		return true;
	}
	return false;
}