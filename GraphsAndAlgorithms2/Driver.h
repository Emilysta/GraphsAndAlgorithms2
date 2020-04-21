#pragma once
#include<iostream>
#include "GraphOnList.h"
#include "GraphOnMatrix.h"
#include "DijkstraAlgorithm.h"
void graphOnMatrixTest() {
	std::string name = "E:\\Code\\Pliki\\c10d100x39.txt"; //\\GraphsAndAlgorithms2\\test.txt";//
	std::cout << name << std::endl;
	GraphOnMatrix<int>* graph = new GraphOnMatrix<int>();
	graph->fillGraph(name);
	graph->show();
	delete graph;
}
void graphOnListTest() {
	std::string name = "E:\\Code\\Pliki\\c10d100x39.txt"; //\\GraphsAndAlgorithms2\\test.txt";//
	std::cout << name << std::endl;
	GraphOnList<int>* graph2 = new GraphOnList<int>();
	graph2->fillGraph(name);
	graph2->show();
	delete graph2;
}


void priorityQueueTest() {
	PQueue<Vertex<int, int>, int>* queue = new PQueue<Vertex<int, int>, int>();
	queue->insert(10, new Vertex<int, int>(0));
	queue->insert(0, new Vertex<int, int>(1));
	queue->insert(1, new Vertex<int, int>(2));
	queue->insert(1, new Vertex<int, int>(3));
	queue->insert(1, new Vertex<int, int>(4));
	queue->insert(2, new Vertex<int, int>(0));
	queue->insert(2, new Vertex<int, int>(1));
	queue->insert(1, new Vertex<int, int>(2));
	queue->insert(2, new Vertex<int, int>(3));
	queue->insert(3, new Vertex<int, int>(4));
	delete queue;
}

void testListOfVertices() {
	//Test dzia³ania metod listy
	ListV* list = new ListV();
	list->insertOnBack(new Vertex<int, int>(0));
	list->insertOnBack(new Vertex<int, int>(1));
	list->insertOnBack(new Vertex<int, int>(2));
	list->insertOnBack(new Vertex<int, int>(3));
	list->insertOnBack(new Vertex<int, int>(4));
	list->insertOnBack(new Vertex<int, int>(5));
	list->showList();
	list->removeAtIndex(2);
	std::cout << "Rozmiar: " << list->size() << std::endl;
	list->insertAfter(5, new Vertex<int,int>(7));
	list->showList();
	list->removeFromBack();
	list->showList();
	std::cout << "Rozmiar: " << list->size() << std::endl;
	list->insertOnBack(new Vertex<int,int>(0));
	list->showList();
	std::cout << "Rozmiar: " << list->size() << std::endl;
	std::cout << "Head: ";
	list->getHead()->getElement()->show();
	std::cout << std::endl;
	std::cout << "Element o 6 indeksie: ";
	if ((*list)[6] != nullptr) {
		(*list)[6]->show();
	}
	std::cout << std::endl;
	delete list;
}

void testDijkstra() {
	std::string name = "E:\\Code\\Pliki\\c10d25x38.txt";
	std::cout << name << std::endl;
	GraphOnMatrix<int>* graph = new GraphOnMatrix<int>();
	graph->fillGraph(name);
	GraphOnList<int>* graph2 = new GraphOnList<int>();
	graph2->fillGraph(name);
	double time = 0;
	Dijkstra(graph, time, true);
	Dijkstra(graph2, time, true);
	delete graph2;
	delete graph;
}