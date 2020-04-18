#pragma once
#include "Element.h"
#include "Compare.h"
template <typename T>
class ExtendedEdge;
template <typename T>
class List {
	Element<T>* head; //Element<T> to "opakowanie" 
	Element<T>* tail;
	int size2;
public:
	List();
	~List();
	T* removeFromFront();
	T* removeAtIndex(int index);
	T* removeFromBack();
	void insertOnFront(T* elem);
	void insertAfter(int index, T* newElem);
	void insertOnBack(T* elem);
	int size();
	void showList();
	bool isEmpty() const;
	void swap(T* elem1, T* elem2);//zamiana miejscami
	Element<T>* getHead() const;
	Element<T>* getTail() const;
	Element<T>* getElemAtIndex(int index) const; //zwraca "opakowanie" o indeksie
	T* operator [](int toSearch) const; //zwraca element z "opakowania" o danym indeksie
	T* findElem(T* elem) const;
	T* findAndDelete(T* elem);
};

template <typename T>
List<T>::List() {
	size2 = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
List<T>::~List() {
	while (!isEmpty()){
		removeFromFront();
	}
	delete head;
}

template <typename T>
T* List<T>::removeFromFront() {
	if (size2 != 0) {
		Element<T>* toRemove = head;
		head = toRemove->getNext();
		toRemove->setNext(nullptr);
		--size2;
		return toRemove->getElement();
	}
}

template <typename T>
T* List<T>::removeAtIndex(int index) {
	if (index < 0 || index >= size2) {
		std::cout << "Zly indeks!" << std::endl;
		return nullptr;
	}
	else {
		if (index == 0) {
			return removeFromFront();
		}
		if (index == size2 - 1) {
			 return removeFromBack();
		}
		if (index > 0 && index < size2 - 1) {
			Element<T>* toRemove = getElemAtIndex(index);
			(toRemove->getPrevious())->setNext(toRemove->getNext());
			(toRemove->getNext())->setPrevious(toRemove->getPrevious());
			//toRemove->setNext(nullptr);
			//toRemove->setPrevious(nullptr);
			--size2;
			return toRemove->getElement();
		}
	}
}

template <typename T>
T* List<T>::removeFromBack() {
	Element<T>* toRemove = tail;
	if (size2 > 1) {
		tail = toRemove->getPrevious();
		tail->setNext(nullptr);
		toRemove->setPrevious(nullptr);
	}
	else {
		tail = nullptr;
		head = nullptr;
	}
	--size2;
	return toRemove->getElement();
}

template <typename T>
void List<T>::insertOnFront(T* elem) {
	++size2;
	Element<T>* newElem = new Element<T>;
	newElem->setElement(elem);
	newElem->setPrevious(nullptr);
	if (head == nullptr && tail == nullptr) {
		newElem->setNext(nullptr);
		head = newElem;
		tail = newElem;
		newElem->getElement()->setPositionInList(getElemAtIndex(0)); //ustawiam pozycje na index 0
	}
	else {
		newElem->setNext(head);
		head->setPrevious(newElem);
		head = newElem;
		newElem->getElement()->setPositionInList(getElemAtIndex(0)); //ustawiam pozycje na index 0
	}
}

template <typename T>
void List<T>::insertAfter(int index, T* newElem) {
	if (index < 0 || index >= size2) {
		std::cout << "Zly indeks!" << std::endl;
	}
	else {
		if (index == size2 - 1) {
			insertOnBack(newElem);
			return;
		}
		else {
			Element<T>* toAdd = new Element<T>();
			toAdd->setElement(newElem);
			toAdd->setPrevious(getElemAtIndex(index));
			toAdd->setNext(getElemAtIndex(index)->getNext());
			getElemAtIndex(index)->getNext()->setPrevious(toAdd);
			getElemAtIndex(index)->setNext(toAdd);
			toAdd->getElement()->setPositionInList(getElemAtIndex(index + 1)); //usatwiam pozycje elementu w li�cie
			++size2;
		}
	}
}

template <typename T>
void List<T>::insertOnBack(T* elem) {
	++size2;
	Element<T>* newElem = new Element<T>();
	newElem->setElement(elem);
	if (tail == nullptr && head ==nullptr) {
		head = newElem;
		tail = newElem;
		newElem->getElement()->setPositionInList(getElemAtIndex(size2-1)); //ustawiam pozycje na index ostatni
	}
	else {
		newElem->setPrevious(tail);
		tail->setNext(newElem);
		tail = newElem;
		newElem->getElement()->setPositionInList(getElemAtIndex(size2 - 1)); //ustawiam pozycje na index ostatni
	}
}

void List<List<ExtendedEdge<int>>>::insertOnBack(List<ExtendedEdge<int>>* elem) {
	++size2;
	Element<List<ExtendedEdge<int>>>* newElem = new Element<List<ExtendedEdge<int>>>();
	newElem->setElement(elem);
	if (tail == nullptr && head == nullptr) {
		head = newElem;
		tail = newElem;
	}
	else {
		newElem->setPrevious(tail);
		tail->setNext(newElem);
		tail = newElem;
	}
}

template <typename T>
int List<T>::size() {
	int count = 0;
	if (isEmpty()) {
		return count;
	}
	else {
		Element<T>* h = head;
		while (h != nullptr) {
			count++;
			h = h->getNext();
		}
	}
	return count;
}

template <typename T>
void List<T>::showList() {
	Element<T>* h = head;
	if (isEmpty()) {
		std::cout << "Lista pusta\n";
	}
	else {
		for (int i = 0; i < size2; i++) {
			(h->getElement())->show();
			std::cout<< " ";
			h = h->getNext();
		}
	}
	std::cout << '\n';
}

template <typename T>
bool List<T>::isEmpty() const {
	return (head == nullptr);
}

template <typename T>
void List<T>::swap(T* elem1, T* elem2) {
	T tmp = *(elem1);
	*elem1 = *elem2;
	*elem2 = tmp;
}

template <typename T>
Element<T>* List<T>::getHead() const {
	return head;
}

template <typename T>
Element<T>* List<T>::getTail() const {
	return tail;
}

template <typename T>
Element<T>* List<T>::getElemAtIndex(int index) const {
	int count = 0;
	Element<T>* tmp = head;
	if (index >= size2) {
		std::cout << "Wykroczono poza zakres";
		return nullptr;
	}
	do {
		if (count == index) {
			return tmp;
		}
		else {
			count++;
			tmp = tmp->getNext();
		}
	} while (tmp != nullptr);

	return nullptr;
}

template <typename T>
T* List<T>::operator [](int toSearch) const {

	Element<T>* tmp = head;
	if (toSearch >= size2) {
		std::cout << "Wykroczono poza zakres";
		return nullptr;
	}
	for (int i = 0; i < toSearch; i++)
		tmp = tmp->getNext();
	return tmp->getElement();
}
//	do {
//		if (count==toSearch){
//			return tmp->getElement();
//		}
//		else {
//			count++;
//			tmp = tmp->getNext();
//		}
//	} while (tmp != nullptr);
//
//	return nullptr;
//}

template <typename T>
T* List<T>::findElem(T* elem) const {
	if (!isEmpty()) {
		Element<T>* tmp = head;
		Compare<Vertex<int>, int> comp;
		do {
			if (comp(*elem, *(tmp->getElement()))) {
				return tmp->getElement();
			}
			else {
				tmp = tmp->getNext();
			}
		} while (tmp != nullptr);
	}
	return nullptr;
}


template <typename T>
T* List<T>::findAndDelete(T* elem) {
	if (!isEmpty()) {
		int count = 0;
		Element<T>* tmp = head;
		Compare<Vertex<int>, int> comp;
		do {
			if (comp(*elem, *(tmp->getElement()))) {
				if (count == 0) {
					return removeFromFront();
				}
				if (count == size2 - 1) {
					return removeFromBack();
				}
				else {
					(tmp->getPrevious())->setNext(tmp->getNext());
					(tmp->getNext())->setPrevious(tmp->getPrevious());
					--size2;
					return tmp->getElement();
				}
			}
			else {
				count++;
				tmp = tmp->getNext();
			}
		} while (tmp != nullptr);
	}
	return nullptr;
}