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
	Element<T>* remove(); //usuwanie element�w wraz z "opakowaniami", uzywane przy destruktorze
	T* removeAtIndex(int index); //usun na podanym indeksie
	T* removeFromBack();
	void insertOnFront(T* elem);
	void insertAfter(int index, T* newElem);
	void insertOnBack(T* elem);
	int size();
	void showList();
	bool isEmpty() const;
	void swap(T* elem1, T* elem2);//zamiana miejscami
	void swapP(T* elem1, T* elem2);//zamiana miejscami
	Element<T>* getHead() const;
	Element<T>* getTail() const;
	Element<T>* getElemAtIndex(int index) const; //zwraca "opakowanie" o indeksie
	T* operator [](int toSearch) const; //zwraca element z "opakowania" o danym indeksie
	T* findElem(T elem); //wyszukuje w liscie dany element
	T* findElem(T elem, int& i); //wyszukuje w liscie dany element, zapisuje do i jego polozenie
	T* findAndDelete(T elem); //wyszukuje i usuwa z listy, zwraca element z "opakowania",usuwa opakowanie 
	void setNullptr();
};

template <typename T>
List<T>::List() {
	size2 = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
List<T>::~List() {
	while (size2 !=0) {
		delete remove();
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
		if (size2 == 0) {
			tail = nullptr;
		}
		T* tmp = toRemove->getElement();
		toRemove->setElement(nullptr);
		delete toRemove;
		return tmp;
	}
	return nullptr;
}
template <typename T>
Element<T>* List<T>::remove() {
	if (size2 != 0) {
		Element<T>* toRemove = head;
		head = toRemove->getNext();
		toRemove->setNext(nullptr);
		--size2;
		if (size2 == 0) {
			tail = nullptr;
		}
		return toRemove;
	}
	return nullptr;
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
			--size2;
			return toRemove->getElement();
		}
	}
	return nullptr;
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
	T* tmp = toRemove->getElement();
	toRemove->setElement(nullptr);
	delete toRemove;
	return tmp;
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
		newElem->getElement()->setPositionInList(newElem); //ustawiam pozycje
	}
	else {
		newElem->setNext(head);
		head->setPrevious(newElem);
		head = newElem;
		newElem->getElement()->setPositionInList(newElem); //ustawiam pozycje
	}
	newElem = nullptr;
	delete newElem;
}

void List<int>::insertOnFront(int* elem) {
	++size2;
	Element<int>* newElem = new Element<int>;
	newElem->setElement(elem);
	newElem->setPrevious(nullptr);
	if (head == nullptr && tail == nullptr) {
		newElem->setNext(nullptr);
		head = newElem;
		tail = newElem;
	}
	else {
		newElem->setNext(head);
		head->setPrevious(newElem);
		head = newElem;
	}
	newElem = nullptr;
	delete newElem;
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
			toAdd->getElement()->setPositionInList(toAdd); //usatwiam pozycje elementu w li�cie
			++size2;
		}
	}
}

template <typename T>
void List<T>::insertOnBack(T* elem) {
	++size2;
	Element<T>* newElem = new Element<T>();
	newElem->setElement(elem);
	if (tail == nullptr && head == nullptr) {
		head = newElem;
		tail = newElem;
		newElem->getElement()->setPositionInList(newElem); //ustawiam pozycje 
	}
	else {
		newElem->setPrevious(tail);
		tail->setNext(newElem);
		tail = newElem;
		newElem->getElement()->setPositionInList(newElem); //ustawiam pozycje 
	}
}

void List<List<Edge<int>>>::insertOnBack(List<Edge<int>>* elem) {
	++size2;
	Element<List<Edge<int>>>* newElem = new Element<List<Edge<int>>>();
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
	newElem = nullptr;
	delete newElem;
}

template <typename T>
int List<T>::size() {
	return size2;
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
			std::cout << " ";
			h = h->getNext();
		}
	}
	std::cout << '\n';
}

void List<int>::showList() {
	Element<int>* h = head;
	std::ofstream file;
	file.open("Dijkstra.txt", std::ofstream::out | std::ofstream::app);
	if (isEmpty()) {
		file << "Lista pusta\n";
	}
	else {
		for (int i = 0; i < size2; i++) {
			file << *h->getElement();
			file << " ";
			h = h->getNext();
		}
	}
	file.close();
}

template <typename T>
bool List<T>::isEmpty() const {
	if (size2 == 0) {
		return true;
	}
	else { return false; }
}

template <typename T>
void List<T>::swap(T* elem1, T* elem2) {
	T tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

template <typename T>
void List<T>::swapP(T* elem1, T* elem2) {
	T* tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
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
	if (toSearch >= size2) {
		std::cout << "Wykroczono poza zakres";
		return nullptr;
	}
	if (toSearch < size2 / 2)
	{
		Element<T>* tmp = head;
		for (int i = 0; i < toSearch; i++)
			tmp = tmp->getNext();
		return tmp->getElement();
	}
	else {
		Element<T>* tmp = tail;
		for (int i = size2-1; i > toSearch; i--)
			tmp = tmp->getPrevious();
		return tmp->getElement();
	}
}

template <typename T>
T* List<T>::findElem(T elem){
	if (!isEmpty()) {
		Element<T>* tmp = head;
		Compare<Vertex<int,int>, int> comp;
		do {
			if (comp(elem, *(tmp->getElement()))) {
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
T* List<T>::findElem(T elem,int& i) {
	i = 0;
	if (!isEmpty()) {
		Element<T>* tmp = head;
		Compare<Vertex<int, int>, int> comp;
		do {
			
			if (comp(elem, *(tmp->getElement()))) {
				return tmp->getElement();
			}
			else {
				i++;
				tmp = tmp->getNext();
			}
		} while (tmp != nullptr);
	}
	return nullptr;
}


template <typename T>
T* List<T>::findAndDelete(T elem) {
	if (!isEmpty()) {
		int count = 0;
		Element<T>* toRemove = head;
		Compare<Vertex<int, T>, int> comp;
		do {
			if (comp(elem, *(toRemove->getElement()))) {
				if (count == 0) {
					return removeFromFront();
				}
				if (count == size2 - 1) {
					return removeFromBack();
				}
				else {
					(toRemove->getPrevious())->setNext(toRemove->getNext());
					(toRemove->getNext())->setPrevious(toRemove->getPrevious());
					--size2;
					T* tmp = toRemove->getElement();
					toRemove->setNext(nullptr);
					toRemove->setPrevious(nullptr);
					toRemove->setElement(nullptr);
					delete toRemove;
					return tmp;
				}
			}
			else {
				count++;
				toRemove = toRemove->getNext();
			}
		} while (toRemove != nullptr);
	}
	return nullptr;
}


template <typename T>
void List<T>::setNullptr() {
	if (head != nullptr) {
		Element<T>* h = head;
		if (isEmpty()) {
			std::cout << "Lista pusta\n";
		}
		else {
			for (int i = 0; i < size2; i++) {
				(h->setElement(nullptr));
				h = h->getNext();
			}
		}
	}
}