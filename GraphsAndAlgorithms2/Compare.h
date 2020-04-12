#pragma once
#include "Qelement.h"
template < typename T,typename t>
class Compare {
public:
	bool operator() (Qelement<T,t>* elem1, Qelement<T,t>* elem2) {
		if (elem1->getKey() < elem2->getKey()) {  //jesli wartosc klucza elem1 jest mniejsza
			return true; //zwraca prawd�
		}
		else { //je�li wieksza badz rowna 
			return false; //zwraca false
		}
	}
};