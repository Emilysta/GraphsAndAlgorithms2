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
	void showWithVertex();
	void insert(t key, T* data);
	void insert(Qelement<T,t>* o);
	void replaceKey(Qelement<T, t>* z, t newKey, int prev, int index); //ustawia klucz i poprzednika
	Qelement<T,t>* removeMin(); //zwraca dane:klucz,wierzcho³ek koncowy i poprzednik i usuwa "opakowanie" z listy
	Qelement<T,t>* min(); //zwraca dane:klucz,wierzcho³ek koncowy i poprzednik
	void repair(int i = 0);
	int Parent(int i) {
		return (i - 1) / 2;
	}
	int Left(int i) {
		return (2*i+1);
	}
	int Right(int i) {
		return (2*i+2);
	}
	List<Qelement<T, t>>* getHeapOnList();
};

template <typename T,typename t>
PQueue<T,t>::PQueue() {
	HeapOnList = new List<Qelement<T, t>>();
}

template <typename T, typename t>
PQueue<T,t>::~PQueue() {
	 HeapOnList->~List();
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
void PQueue<T, t>::showWithVertex() {
	for (int i = 0; i < HeapOnList->size(); i++) {
		(*HeapOnList)[i]->getData()->show();
		std::cout << "   .   ";
		std::cout << (*HeapOnList)[i]->getKey();
		std::cout << "   .   ";
		std::cout << (*HeapOnList)[i]->getPrev();
		std::cout << std::endl;
	}
}


template <typename T, typename t>
void  PQueue<T,t>::insert(t key, T* data) {
	int i = HeapOnList->size();
	Compare<T,t> comp; //komparator
	Qelement<T, t>* q = new Qelement<T, t>(key, data);
	HeapOnList->insertOnBack(q);
	while (i != 0 && comp((*HeapOnList)[i],(*HeapOnList)[Parent(i)])) { //comp(elem1, elem2) zwraca prawde 
		HeapOnList->swap((*HeapOnList)[i], (*HeapOnList)[Parent(i)]); //gdy klucz z elem 1 jest mniejszy od klucza z elem 2
		i = Parent(i);
	}
}
template <typename T, typename t>
void  PQueue<T, t>::insert(Qelement<T, t>* o) {
	int i = HeapOnList->size();
	Compare<T, t> comp; //komparator
	HeapOnList->insertOnBack(o);
	while (i != 0 && comp((*HeapOnList)[i], (*HeapOnList)[Parent(i)])) { //comp(elem1, elem2) zwraca prawde 
		HeapOnList->swap((*HeapOnList)[i], (*HeapOnList)[Parent(i)]); //gdy klucz z elem 1 jest mniejszy od klucza z elem 2
		i = Parent(i);
	}
}
template <typename T, typename t>
void PQueue<T, t>::replaceKey(Qelement<T, t>* z, t newKey, int prev,int index) {
	z->setKey(newKey);
	z->setPrev(prev);
	int parent;
	do { //naprawa kopca w górê, bo zmienilismy klucz na mniejszy
		if (index % 2 == 1) {
			parent = (index - 1) / 2;
		}
		else {
			parent = (index - 2) / 2;
		}
		repair(parent);
		index = parent;
	} while (parent >= 0);
}

template <typename T, typename t>
Qelement<T,t>* PQueue<T,t>::removeMin() { 
	int size = HeapOnList->size();
	if (size == 1) {
		return HeapOnList->removeFromFront();
	}
	if (!HeapOnList->isEmpty()) {
		HeapOnList->swap((*HeapOnList)[0], (*HeapOnList)[size - 1]);
		Qelement<T, t>* tmp = HeapOnList->removeFromBack();
		repair();
		return tmp;
	}
	return nullptr;
}

template <typename T, typename t>
Qelement<T,t>* PQueue<T,t>::min() {
	return (*HeapOnList)[0]; // minimalna wartosc w pierwszej komorce tablicy
}

template <typename T, typename t>
void PQueue<T, t>::repair(int i) {
	int left = Left(i);
	int right = Right(i);
	int min = i;
	Compare<T, t> comp;
	if (left < HeapOnList->size() && comp((*HeapOnList)[left], (*HeapOnList)[min])) {  //comp(elem1, elem2) zwraca prawde 
		min = left;												//gdy klucz z elem 1 jest mniejszy od klucza z elem 2
	}
	if (right < HeapOnList->size() && comp((*HeapOnList)[right], (*HeapOnList)[min])) {
		min = right;
	}
	if (min != i)
	{
		HeapOnList->swap((*HeapOnList)[i], (*HeapOnList)[min]);
		repair(min);
	}
}


template <typename T, typename t>
List<Qelement<T,t>>* PQueue<T, t>::getHeapOnList() {
	return HeapOnList;
}






