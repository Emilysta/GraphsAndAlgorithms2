#pragma once
#include "Element.h"
template <typename T>
class List {
	Element<T>* head;
	Element<T>* tail;
	int size2;
public:
	List();
	~List();
	void removeFromFront();
	void removeFromBack();
	void insertOnFront(T* elem);
	void insertOnBack(T* elem);
	int size();
	void showList();
	bool isEmpty() const;
	Element<T>* getHead() const;

	T* operator [](int toSearch) const;
};

template <typename T>
List<T>::List() {
	size2 = 0;
	head = nullptr;
	tail = nullptr;
}


template <typename T>
List<T>::~List() {
	//delete tail;
	while (!isEmpty()){
		removeFromFront();
		--size2;
	}
	delete head; //???? czy bez wyciek�w? co z reszta poloaczonych elementow

}

template <typename T>
void List<T>::removeFromFront() {
	Element<T>* toRemove = head;
	head = toRemove->getNext();
	toRemove->setNext(nullptr);
	delete toRemove;
	--size2;
}

template <typename T>
void List<T>::removeFromBack() {
	Element<T>* toRemove = tail;
	tail = toRemove->getPrevious();
	toRemove->setPrevious(nullptr);
	delete toRemove;
	tail->setNext(nullptr);
	--size2;
}

template <typename T>
void List<T>::insertOnFront(T* elem) {
	Element<T>* newElem = new Element<T>;
	newElem->setElement(elem);
	newElem->setPrevious(nullptr);//prev = nullptr;
	if (head == nullptr) {
		newElem->setNext(nullptr);// next = nullptr;
		head = newElem;
		tail = newElem;
	}
	else {
		newElem->setNext(head);// next = head;
		head->setPrevious(newElem);// prev = newElem;
		head = newElem;
	}
	++size2;
}

template <typename T>
void List<T>::insertOnBack(T* elem) {
	Element<T>* newElem = new Element<T>();
	newElem->setElement(elem);
	newElem->setNext(nullptr); // next = nullptr;
	if (head == nullptr) {
		newElem->setPrevious(nullptr);
		head = newElem;
		tail = newElem;
	}
	else {
		//newElem->setNext(nullptr);
		newElem->setPrevious(tail);
		tail->setNext(newElem);// next = newElem;
		tail = newElem;
	}
	++size2;
}

template <typename T>
int List<T>::size() {
	int count = 0;
	Element<T>* h = head;
	if (isEmpty()) {
		//std::cout << "Lista pusta\n";
	}
	else {
		while (h != nullptr) {
			count++;
			h = h->getNext();// next;
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
		for (int i = 0; i < size(); i++) {
			(h->getElement())->show();
			std::cout<< " ";
			h = h->getNext();// next;
		}
	}
	std::cout << '\n';
}

template <typename T>
bool List<T>::isEmpty() const {
	return (head == nullptr);
}

template <typename T>
Element<T>* List<T>::getHead() const {
	return head;
}

template <typename T>
T* List<T>::operator [](int toSearch) const {
	int count = 0;
	Element<T>* tmp = head;
	if (toSearch >= size2) {
		std::cout << "Wykroczono poza zakres";
		return nullptr;
	}
	do {
		if (count==toSearch){
			return tmp->getElement();
		}
		else {
			count++;
			tmp = tmp->getNext();
		}
	} while (tmp != nullptr);

	return nullptr;
}
