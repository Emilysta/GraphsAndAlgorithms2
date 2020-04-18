#pragma once
#include "List.h"
#include "Edge.h"
template <typename T>
class Graph {
protected:
	List<Vertex<int,T>>* listOfVertices;
	List<Edge<T>>* listOfEdges;
	Vertex<int,T>* startVertex;

public:
	virtual Vertex<int,T>* getStartVertex() { return startVertex; }
	virtual List<Vertex<int, T>>* vertices() { return listOfVertices; }
	virtual List<Edge<T>>* edges() { return listOfEdges; }
	virtual List<Edge<T>>* incidentEdges(Vertex<int, T>* v) { //tylko jako pic
		List<Edge<T>>* r = new List<Edge<T>>();
		return r;
	}
	virtual Vertex<int, T>* opposite(Vertex<int, T>* v, Edge<T>* e) {//tylko jako pic
		Vertex<int, T>* r = new Vertex<int,T>();
		return r;
	}
};
