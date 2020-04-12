#pragma once
template <typename T,typename t>
class Qelement {
	t key; //waga drogi w algorytmie 
	T* data;	//Wierzcholek poprzedni
public:
	Qelement() {
		key = -1;
		data = nullptr;
	}
	Qelement(t newKey, T* newData) {
		key = newKey;
		data = newData;
	}
	~Qelement() = default;
	const t& getKey() const;
	T* getData() const;
	void setKey(t newKey);
	void setData(T* newData);
	void show();
};

template <typename T, typename t>
const t& Qelement<T,t>::getKey() const {
	return key;
}

template <typename T, typename t>
T* Qelement<T,t>::getData() const {
	return data;
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

