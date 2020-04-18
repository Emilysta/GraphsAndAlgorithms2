#pragma once
#include "List.h"
#include "Edge.h"
class Graph {
protected:
	int numberOfVertices = 0;
	int numberOfEdges = 0;
	int startingVertex = 0;

public:
	int GetVertices() { return numberOfVertices; }
	int GetEdges() { return numberOfEdges; }
	int GetStartingVertex() { return startingVertex; }
	virtual List<Edge>* Neighbours(int vertexIndex) {
		List<Edge>* tmp = new List<Edge>();
		return tmp;
	}
	virtual int GetEdgeWeigth(int vertex1, int vertex2) { return 0; }
};