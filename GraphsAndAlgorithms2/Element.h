#pragma once
template <typename T>
class List;
template <typename T>
class Element
{	
	Element<T>* prev;
	T* element;
	Element<T>* next;

public:
	Element() {
		prev = nullptr;
		next = nullptr;
		element = nullptr;
	}
	~Element() 
	{
		prev = nullptr;
		next = nullptr;
		delete prev;
		delete next;
		delete element;
	}
	T* getElement() const;
	Element<T>* getNext() const;
	Element<T>* getPrevious() const;
	void setElement(T* newElement);
	void setNext(Element<T>* newNext);
	void setPrevious(Element<T>* newNext);
};

template <typename T>
T* Element<T>::getElement() const {
	return element;
}

template <typename T>
Element<T>* Element<T>::getNext() const {
	return next;
}

template <typename T>
Element<T>* Element<T>::getPrevious() const {
	return prev;
}

template <typename T>
void Element<T>::setElement(T* newElement) {
	element = newElement;
}

template <typename T>
void Element<T>::setNext(Element<T>* newNext) {
	next = newNext;
}

template <typename T>
void Element<T>::setPrevious(Element<T>* newPrev) {
	prev = newPrev;
}