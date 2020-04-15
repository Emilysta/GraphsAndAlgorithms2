#pragma once
#include "Qelement.h"
#include "Edge.h"
template < typename T,typename t>
class Compare {
public:
	bool operator() (Qelement<T,t>* elem1, Qelement<T,t>* elem2) {
		if (elem1->getKey() < elem2->getKey()) {  //jesli wartosc klucza elem1 jest mniejsza
			return true; //zwraca prawdê
		}
		else { //jeœli wieksza badz rowna 
			return false; //zwraca false
		}
	}

	bool operator() (Qelement<Vertex<int>, t> elem1, Qelement<Vertex<int>, t> elem2) {
		if (elem1.getData()->getPoint()== elem2.getData()->getPoint()) {  //jesli te same elementy
			return true; //zwraca prawdê
		}
		else { //jeœli inne 
			return false; //zwraca false
		}
	}

	bool operator() (Vertex<t> elem1, Vertex<t> elem2) {
		if (elem1.getPoint() == elem2.getPoint()) {  //jesli wartosc/nazwa wierzcho³ka elem1 jest równa
			return true; //zwraca prawdê
		}
		else { //jeœli inna
			return false; //zwraca false
		}
	}

	bool operator() (Edge<t> elem1, Edge<t> elem2) {
		Compare<T,t> comp;
		if (comp(*(elem1.getStartOfEdge()),*(elem2.getStartOfEdge())) && comp(*(elem1.getEndOfEdge()), *(elem2.getEndOfEdge())) && (elem1.getWeight()==elem2.getWeight())) {  //jesli wartosc/nazwa wierzcho³ka elem1 jest równa
			return true; //zwraca prawdê
		}
		else { //jeœli inna
			return false; //zwraca false
		}
	}
	

	
};