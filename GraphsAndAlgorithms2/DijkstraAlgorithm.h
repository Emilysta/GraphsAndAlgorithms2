#pragma once
#include "GraphOnMatrix.h"
#include "PQueue.h"
template <typename t>
PQueue <Vertex<int>, t>*  Dijkstra(GraphOnMatrix<t>* graph) {
	PQueue <Vertex<int>, t>* Q = new PQueue<Vertex<int>, t>();
	PQueue <Vertex<int>, t>* S = new PQueue<Vertex<int>, t>();
	Compare <Vertex<int>, t> comp;
	for (int i = 0; i < graph->vertices()->size(); i++) {
		if (comp(*(graph->getStartVertex()), *((*(graph->vertices()))[i]))){
			Q->insert(0, (*graph->vertices())[i]);
		}
		else {
			Q->insert(INT_MAX, (*graph->vertices())[i]);
		}
	}
	while (!Q->isEmpty()) {
		Qelement<Vertex<int>,t>* elemPQ = new Qelement<Vertex<int>,t>();
		elemPQ = Q->removeMin();
		S->insert(elemPQ->getKey(),elemPQ->getData());
		List<Edge<t>>* incidentEdges = graph->incidentEdges(elemPQ->getData());
		for (int i = 0; i < incidentEdges->size(); i++) {
			Vertex<int>* z = graph->opposite(elemPQ->getData(),(*incidentEdges)[i]);
			t number = elemPQ->getKey() + (*incidentEdges)[i]->getWeight();
			Qelement<Vertex<int>, t>* o = new Qelement<Vertex<int>, t>();
			o = Q->getHeapOnList()->findElem(new Qelement<Vertex<int>, t>(0, z));
			if (o!= nullptr) {
				if (number < o->getKey()) {
					o->setKey(number);
				}
			}
		}
		Q->repair();
	}
	return S;
}