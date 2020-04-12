#pragma once
#include "Compare.h"
#include "List.h"
template <typename T,typename t>
class PQueue { //kolejka priorytetowa na bazie kopca, kopiec na bazie listy
	List<Qelement<T,t>>* HeapOnList;
public:
	PQueue();
	~PQueue();
	bool isEmpty() const;
	int size();
	void show();
	void insert(t key, T* data);
	Qelement<T,t>* removeMin(); //zwraca wartosc klucza... w naszym wypadku drogi
	Qelement<T,t>* min();
	int Parent(int i) {
		return (i - 1) / 2;
	}
	int Left(int i) {
		return (2*i+1);
	}
	int Right(int i) {
		return (2*i+2);
	}
};

template <typename T,typename t>
PQueue<T,t>::PQueue() {
	HeapOnList = new List<Qelement<T, t>>();
}

template <typename T, typename t>
PQueue<T,t>::~PQueue() {
	delete HeapOnList;
}

template <typename T, typename t>
bool PQueue<T,t>::isEmpty() const { //prawda jesli pusta kolejka
	return HeapOnList->isEmpty(); //falsz jesli cos jest w kolejce
}

template <typename T, typename t>
int PQueue<T,t>::size() {
	return HeapOnList->size();
}

template <typename T, typename t>
void PQueue<T, t>::show() { //wyœwietlenie kluczy 
	HeapOnList->showList();
}

template <typename T, typename t>
void  PQueue<T,t>::insert(t key, T* data) {
	int i = HeapOnList->size();
	Compare<T,t> comp; //komparator
	HeapOnList->insertOnBack(new Qelement<T,t>(key, data));
	while (i != 0 && comp((*HeapOnList)[i],(*HeapOnList)[Parent(i)])) { //comp(elem1, elem2) zwraca prawde 
		HeapOnList->swap((*HeapOnList)[i], (*HeapOnList)[Parent(i)]); //gdy klucz z elem 1 jest mniejszy od klucza z elem 2
		i = Parent(i);
	}
}

template <typename T, typename t>
Qelement<T,t>* PQueue<T,t>::removeMin() { //czy tu dobrze?
	Qelement<T, t>* tmp = (*HeapOnList)[0];

	if (!HeapOnList->isEmpty()) {
		return (*HeapOnList)[0];
	}
}

template <typename T, typename t>
Qelement<T,t>* PQueue<T,t>::min() {
	return (*HeapOnList)[0]; // minimalna wartosc w pierwszej komorce tablicy
}





