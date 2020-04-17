#pragma once
template <typename T,typename t>
class Qelement { //element kolejki priorytetowej
	int previous;
	t key; //waga drogi w algorytmie 
	T* data;	//Wierzcholek poprzedni
	Element<Qelement<T,t>>* whereInList;
public:
	Qelement() {
		previous = -1;
		key = -1;
		data = nullptr;
		whereInList = nullptr;
	}
	Qelement(t newKey, T* newData) {
		previous = -1;
		key = newKey;
		data = newData;
		whereInList = nullptr;
	}

	~Qelement() = default;
	const int& getPrev() const;
	const t& getKey() const;
	T* getData() const;
	void setPrev(int newPrev);
	void setKey(t newKey);
	void setData(T* newData);
	void show();
	const Element<Qelement<T,t>>* getPositionInList() const;
	void setPositionInList(Element<Qelement<T, t>>* newMyself);
};


template <typename T, typename t>
const int& Qelement<T, t>::getPrev() const {
	return previous;
}

template <typename T, typename t>
const t& Qelement<T,t>::getKey() const {
	return key;
}

template <typename T, typename t>
T* Qelement<T,t>::getData() const {
	return data;
}

template <typename T, typename t>
void Qelement<T, t>::setPrev(int newPrev) {
	previous = newPrev;
}

template <typename T, typename t>
void Qelement<T,t>::setKey(t newKey) {
	key = newKey;
}

template <typename T, typename t>
void Qelement<T,t>::setData(T* newData) {
	data = newData;
}

template <typename T, typename t>
void Qelement<T, t>::show() { //wyœwietlenie tylko klucza
	std::cout << key;
}

template <typename T, typename t>
const Element<Qelement<T, t>>* Qelement<T, t>::getPositionInList() const {
	return whereInList;
}

template <typename T, typename t>
void Qelement<T, t>::setPositionInList(Element<Qelement<T, t>>* newMyself) {
	whereInList = newMyself;
}
