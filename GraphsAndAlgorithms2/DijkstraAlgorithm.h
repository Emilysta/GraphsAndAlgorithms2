#pragma once
#include "Graph.h"
#include "PQueue.h"
#include <chrono>
template <typename t>
void Dijkstra(Graph<t> * graph,double& time,bool toFile) {
	PQueue <Vertex<int, t>, t>* Q = new PQueue<Vertex<int, t>, t>();
	PQueue <Vertex<int, t>, t>* S = new PQueue<Vertex<int, t>, t>();
	Compare <t, t> comp;
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
		Qelement<Vertex<int, t>, t>* elemPQ = Q->removeMin();
		Vertex<int, t>* d = elemPQ->getData();
		arr[d->getPoint()] = false;
		S->insert(elemPQ);
		List<Edge<t>>* incidentEdges = graph->incidentEdges(d);
		for (int i = 0; i < incidentEdges->size(); i++) {
			Vertex<int, t>* z = graph->opposite(d, (*incidentEdges)[i]);
			t number = elemPQ->getKey() + (*incidentEdges)[i]->getWeight();
			if (arr[z->getPoint()] != false) {
				Qelement<Vertex<int, t>, t>* o = Q->getHeapOnList()->findAndDelete(Qelement<Vertex<int, t>, t>(0, z));

				if (number < o->getKey()) {
					o->setKey(number);
					o->setPrev(d->getPoint());
				}
				Q->insert(o);
			}
		}
		incidentEdges->setNullptr();
		delete incidentEdges;
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	time = duration.count();
	delete Q;
	if (toFile) {
		for (int i = 0; i < S->getHeapOnList()->size(); i++) {
			Qelement<Vertex<int, t>, t>* o = (*S->getHeapOnList())[i];
			t key = o->getKey();
			std::cout << "W.koncowy: " << o->getData()->getPoint();
			std::cout << " Koszt sciezki: ";
			std::cout << key;
			std::cout << " Sciezka: ";
			List<int> path;
			while (true) {
				int* path2 = new int(o->getData()->getPoint());
				path.insertOnFront(path2);
				if (o->getData()->getPoint() == graph->getStartVertex()->getPoint()) {
					break;
				}
				o = S->getHeapOnList()->findElem(Qelement<Vertex<int, t>, t>(0, new Vertex<int, int>(o->getPrev())));
			}
			path.showList();
			std::cout << std::endl;
		}
	}
	delete S;
	delete[] arr;
}

