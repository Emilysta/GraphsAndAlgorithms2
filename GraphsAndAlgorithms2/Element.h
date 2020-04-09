#pragma once
template <typename T>
class List;
template <typename T>
class Element
{
	T elem;
	Element<T>* next;
	friend class List<T>;
public:
	Element() {
		next = nullptr;
		elem = 0;
	}
	~Element() {

	}
	T getElement();
	Element getNext();
	void setElement(T newElement);
	void setNext(Element<T> newNext);
};

template <typename T>
T Element<T>::getElement() {
	return elem;
}

template <typename T>
Element<T> Element<T>::getNext() {
	return next;
}

template <typename T>
void Element<T>::setElement(T newElement) {
	elem = newElement;
}

template <typename T>
void Element<T>::setNext(Element<T> newNext) {
	next = newNext;
}
