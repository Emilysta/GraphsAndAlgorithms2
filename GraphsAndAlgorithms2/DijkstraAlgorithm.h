#pragma once
#include "Graph.h"
#include "PQueue.h"
#include <chrono>
template <typename t>
PQueue <Vertex<int, t>, t> * Dijkstra(Graph<t> * graph) {
	PQueue <Vertex<int, t>, t>* Q = new PQueue<Vertex<int, t>, t>();
	PQueue <Vertex<int, t>, t>* S = new PQueue<Vertex<int, t>, t>();
	Compare <Vertex<int, t>, t> comp;
	int numberV = graph->vertices()->size();
	bool* arr = new bool[numberV];
	for (int j = 0; j < numberV; j++) {
		arr[j] = true;
	}
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < graph->vertices()->size(); i++) {
		if (comp(*(graph->getStartVertex()), *((*(graph->vertices()))[i]))) {
			Q->insert(0, (*graph->vertices())[i]);
		}
		else {
			Q->insert(INT_MAX, (*graph->vertices())[i]);
		}
	}
	while (!Q->isEmpty()) {
		Qelement<Vertex<int, t>, t>* elemPQ = new Qelement<Vertex<int, t>, t>();
		elemPQ = Q->removeMin();
		Vertex<int, t>* d = elemPQ->getData();
		arr[d->getPoint()] = false;
		S->insert(elemPQ);
		List<Edge<t>>* incidentEdges = graph->incidentEdges(d);
		for (int i = 0; i < incidentEdges->size(); i++) {
			Vertex<int, t>* z = graph->opposite(d, (*incidentEdges)[i]);
			t number = elemPQ->getKey() + (*incidentEdges)[i]->getWeight();
			if (arr[z->getPoint()] != false) {
				Qelement<Vertex<int, t>, t>* o = new Qelement<Vertex<int, t>, t>();
				o = Q->getHeapOnList()->findAndDelete(new Qelement<Vertex<int, t>, t>(0, z));

				if (number < o->getKey()) {
					o->setKey(number);
					o->setPrev(d->getPoint());
				}
				Q->insert(o);
			}
		}
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "algorytm: " << duration.count() << "ms\n";
	return S;
}

