#pragma once
#include "GraphOnMatrix.h"
#include "PQueue.h"
#include <chrono>
template <typename t>
PQueue <Vertex<int>, t>*  Dijkstra(GraphOnMatrix<t>* graph) {
	//PQueue <Vertex<int>, t>* Q = new PQueue<Vertex<int>, t>();
	//PQueue <Vertex<int>, t>* S = new PQueue<Vertex<int>, t>();
	//Compare <Vertex<int>, t> comp;
	//auto start = std::chrono::high_resolution_clock::now();
	//int numberOFVertices = graph->vertices()->size()
	//for (int i = 0; i < numberOFVertices; i++) {
	//	if (*(graph->getStartVertex())->getPoint() == i ){
	//		Q->insert(0, new Vertex<int>(i));
	//	}
	//	else {
	//		Q->insert(100000, new Vertex<int>(i));
	//	}
	//}
	//bool tab[numberOFVertices];
	//for (int j = 0; j < numberOFVertices; j++) {
	//	tab[j] = true;
	//}
	//while (!Q->isEmpty()) {
	//	//Q->show();
	//	//std::cout << "KONIEC KOLEJKI" << std::endl;
	//	Qelement<Vertex<int>,t>* elemPQ = new Qelement<Vertex<int>,t>();
	//	elemPQ = Q->removeMin();
	//	Vertex<int>* v = elemPQ->getData();
	//	tab[v->getPoint()] = false;
	//	S->insert(elemPQ);
	//	List<Edge<t>>* incidentEdges = graph->incidentEdges(elemPQ->getData());
	//	for (int i = 0; i < incidentEdges->size(); i++) {
	//		Edge<t>* e = (*incidentEdges)[i];
	//		Vertex<int>* z = graph->opposite(v,e);
	//		t number = elemPQ->getKey() + e->getWeight();
	//		Qelement<Vertex<int>, t>* o = new Qelement<Vertex<int>, t>();
	//		o = Q->getHeapOnList()->findElem(new Qelement<Vertex<int>, t>(0, z));
	//		if (tab[z->getPositionInList()==true) {
	//			if (number < o->getKey()) {
	//				Q->replaceKey(z, number, elemPQ->getData()->getPoint());
	//			}
	//		}
	//	}
	//	Q->repair();
	//}
	PQueue <Vertex<int>, t>* Q = new PQueue<Vertex<int>, t>();
	PQueue <Vertex<int>, t>* S = new PQueue<Vertex<int>, t>();
	Compare <Vertex<int>, t> comp; 
	int numberV=graph->vertices()->size();
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
		Qelement<Vertex<int>, t>* elemPQ = new Qelement<Vertex<int>, t>();
		elemPQ = Q->removeMin();
		arr[elemPQ->getData()->getPoint()] = false;
		S->insert(elemPQ);
		List<Edge<t>>* incidentEdges = graph->incidentEdges(elemPQ->getData());
		for (int i = 0; i < incidentEdges->size(); i++) {
			Vertex<int>* z = graph->opposite(elemPQ->getData(), (*incidentEdges)[i]);
			t number = elemPQ->getKey() + (*incidentEdges)[i]->getWeight();
			if (arr[z->getPoint()] != false) {
				Qelement<Vertex<int>, t>* o = new Qelement<Vertex<int>, t>();
				o = Q->getHeapOnList()->findAndDelete(new Qelement<Vertex<int>, t>(0, z));

				if (number < o->getKey()) {
					o->setKey(number);
					o->setPrev(elemPQ->getData()->getPoint());
					//Q->insert(o);
				}
				Q->insert(o);
			}
		}
	}
	
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "algorytm: "<< duration.count() << "ms\n";
	return S;
}