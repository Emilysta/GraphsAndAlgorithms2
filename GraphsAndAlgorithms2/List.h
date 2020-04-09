#pragma once
#pragma once
#include "Element.h"
template <typename T>
class List {
	Element<T>* head;
public:
	List();
	~List();
	void removeFromFront();
	void insertOnFront(const T& elem);
	int size();
	void showList();
	bool isEmpty() const;
	const T& getHead() const;
};

template <typename T>
List<T>::List() {
	head = new Element<T>();
}


template <typename T>
List<T>::~List() {
	while (!isEmpty()) {
		removeFromFront();
	}
	delete head; //???? czy bez wycieków? co z reszta poloaczonych elementow
}

template <typename T>
void List<T>::removeFromFront() {
	Element<T>* toRemove = head;
	head = toRemove->next;
	delete toRemove;
}

template <typename T>
void List<T>::insertOnFront(const T& elem) {

	Element<T>* newElem = new Element<T>;
	newElem->elem = elem;
	newElem->next = head;
	head = newElem;

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
			h = h->next;
		}
	}
	return --count;
}

template <typename T>
void List<T>::showList() {
	Element<T>* h = head;
	if (isEmpty()) {
		std::cout << "Lista pusta\n";
	}
	else {
		for (int i = 0; i < size(); i++) {
			std::cout << h->elem << " ";
			h = h->next;
		}
	}
	std::cout << '\n';
}

template <typename T>
bool List<T>::isEmpty() const {
	return (head->next == nullptr);
}

template <typename T>
const T& List<T>::getHead() const {
	return head->elem;
}