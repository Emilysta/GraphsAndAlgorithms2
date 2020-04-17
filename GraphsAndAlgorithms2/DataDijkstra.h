#pragma once
#include "Element.h"
template <typename T, typename t>
class DataDijkstra { //element kolejki priorytetowej
	int previous;
	t key; //waga drogi w algorytmie 
	T* data;	//Wierzcholek poprzedni
	Element<DataDijkstra<T, t>>* whereInList;
public:
	DataDijkstra() {
		previous = -1;
		key = -1;
		data = nullptr;
		whereInList = nullptr;
	}
	DataDijkstra(t newKey, T* newData) {
		previous = -1;
		key = newKey;
		data = newData;
		whereInList = nullptr;
	}
	~DataDijkstra() = default;
	const t& getKey() const;
	const int& getPrev() const;
	T* getData() const;
	void setPrev(int newPrev);
	void setKey(t newKey);
	void setData(T* newData);
	void show();
	const Element<DataDijkstra<T, t>>* getPositionInList() const;
	void setPositionInList(Element<DataDijkstra<T, t>>* newMyself);
};

template <typename T, typename t>
const t& DataDijkstra<T, t>::getKey() const {
	return key;
}

template <typename T, typename t>
const int& DataDijkstra<T, t>::getPrev() const {
	return previous;
}

template <typename T, typename t>
T* DataDijkstra<T, t>::getData() const {
	return data;
}

template <typename T, typename t>
void DataDijkstra<T, t>::setKey(t newKey) {
	key = newKey;
}

template <typename T, typename t>
void DataDijkstra<T, t>::setPrev(int newPrev) {
	previous = newPrev;
}

template <typename T, typename t>
void DataDijkstra<T, t>::setData(T* newData) {
	data = newData;
}

template <typename T, typename t>
void DataDijkstra<T, t>::show() { //wyœwietlenie tylko klucza
	std::cout << key;
}

template <typename T, typename t>
const Element<DataDijkstra<T, t>>* DataDijkstra<T, t>::getPositionInList() const {
	return whereInList;
}

template <typename T, typename t>
void DataDijkstra<T, t>::setPositionInList(Element<DataDijkstra<T, t>>* newMyself) {
	whereInList = newMyself;
}
#pragma once
