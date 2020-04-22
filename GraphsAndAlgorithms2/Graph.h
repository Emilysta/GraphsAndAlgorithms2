#pragma once
#include "List.h"
#include "Edge.h"
template <typename T>
class Graph { //klasa bazowa po kt�rej dziedzicz� grafy na macierzy i na li�cie
protected:
	List<Vertex<int,T>>* listOfVertices;
	List<Edge<T>>* listOfEdges;
	Vertex<int,T>* startVertex;

public:
	virtual Vertex<int,T>* getStartVertex() { return startVertex; }
	virtual List<Vertex<int, T>>* vertices() { return listOfVertices; }
	virtual List<Edge<T>>* edges() { return listOfEdges; }
	virtual List<Edge<T>>* incidentEdges(Vertex<int, T>* v) {//rozwini�cie metody
		List<Edge<T>>* r = new List<Edge<T>>(); 
		return r;
	}

	virtual Vertex<int, T>* opposite(Vertex<int, T>* v, Edge<T>* e){ //rozwini�cie metody
		Vertex<int, T>* r = new Vertex<int,T>();
		return r;
	}
};
