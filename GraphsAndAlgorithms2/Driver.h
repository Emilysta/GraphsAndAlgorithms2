#pragma once
#include<iostream>
#include <fstream>
#include "GraphOnList.h"
#include "GraphOnMatrix.h"
#include "DijkstraAlgorithm.h"
void graphOnMatrixTest() {
	//test na pliku c10d100x39.txt
	std::string name = "E:\\Code\\Pliki\\c10d25x38.txt"; 
	std::cout <<"Test na pliku: "<< name << std::endl;
	GraphOnMatrix<int>* graph = new GraphOnMatrix<int>();
	graph->fillGraph(name);
	graph->show();
	std::cout << "Wpycham wierzcholek nr 10: \n";
	graph->insertVertex(10);
	graph->show();
	graph->insertEdge((*graph->vertices())[0], (*graph->vertices())[10], 6);
	graph->show();
	if(graph->areAdjacent((*graph->vertices())[0], (*graph->vertices())[10]))
		std::cout<<"Wierzcholki 0 i 10 sa sasiednie\n";
	std::cout << "Wierzcholek sasiedni do 0 wzgledem krawedzi o wadze 43: ";
	graph->opposite((*graph->vertices())[0], (*graph->edges())[0])->show();;
	std::cout << std::endl;
	std::cout << "Krawedzie przylegajace do wierzcholka nr 1: \n";
	graph->incidentEdges((*graph->vertices())[1])->showList();
	std::cout << std::endl;
	std::cout << "wierzchoki koncowe krawedzi o indeksie 2: \n";
	Vertex<int, int>** array = new Vertex<int, int> * [2];
	array=graph->endVertices((*graph->edges())[2]);
	array[0]->show();
	std::cout << std::endl;
	array[1]->show();
	std::cout << std::endl;
	std::cout << "Zamieniam wartosc w wierzcholku 10 na 11: \n";
	graph->replaceV((*graph->vertices())[10],11);
	graph->showVertices();
	std::cout << "Zamieniam wage krawedzi 5.9.69 90: \n";
	graph->replaceE((*graph->edges())[8], 90);
	graph->show();
	std::cout << "Usuwam krawedz 5.8.22: \n";
	graph->removeEdge((*graph->edges())[7]);
	graph->show();
	std::cout << "Usuwam wierzcholek o numerze 9 wraz z powiazaniami: \n";
	graph->removeVertex((*graph->vertices())[9]);
	graph->show();
	delete graph;
}
void graphOnListTest() {
	std::string name = "E:\\Code\\Pliki\\c10d25x38.txt"; 
	std::cout << "Test na pliku: "<< name << std::endl;
	GraphOnList<int>* graph2 = new GraphOnList<int>();
	graph2->fillGraph(name);
	graph2->show();
	std::cout << "Wpycham wierzcholek nr 10: \n";
	graph2->insertVertex(10);
	graph2->show();
	graph2->insertEdge(dynamic_cast <ExtendedVertex<int,int>*>((*graph2->vertices())[0]), dynamic_cast <ExtendedVertex<int, int>*>((*graph2->vertices())[10]), 6);
	graph2->show();
	if (graph2->areAdjacent((*graph2->vertices())[0], (*graph2->vertices())[10]))
		std::cout << "Wierzcholki 0 i 10 sa sasiednie\n";
	std::cout << "Wierzcholek sasiedni do 0 wzgledem krawedzi o wadze 43: ";
	graph2->opposite((*graph2->vertices())[0], (*graph2->edges())[0])->show();;
	std::cout << std::endl;
	std::cout << "Krawedzie przylegajace do wierzcholka nr 1: \n";
	graph2->incidentEdges((*graph2->vertices())[1])->showList();
	std::cout << std::endl;
	std::cout << "wierzchoki koncowe krawedzi o indeksie 2: \n";
	ExtendedVertex<int, int>** array = new ExtendedVertex<int, int> * [2];
	array = graph2->endVertices((*graph2->edges())[2]);
	array[0]->show();
	std::cout << std::endl;
	array[1]->show();
	std::cout << std::endl;
	std::cout << "Zamieniam wartosc w wierzcholku 10 na 11: \n";
	graph2->replaceV((*graph2->vertices())[10], 11);
	graph2->showVertices();
	std::cout << "Zamieniam wage krawedzi 5.9.69 90: \n";
	graph2->replaceE((*graph2->edges())[8], 90);
	graph2->show();
	std::cout << "Usuwam krawedz 5.8.22: \n";
	graph2->removeEdge((*graph2->edges())[7]);
	graph2->show();
	std::cout << "Usuwam wierzcholek o numerze 9 wraz z powiazaniami: \n";
	graph2->removeVertex(dynamic_cast <ExtendedVertex<int, int>*>((*graph2->vertices())[9]));
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
	queue->show();
	queue->removeMin()->show();
	std::cout << std::endl;
	queue->show();
	queue->show();
	queue->removeMin()->show();
	std::cout << std::endl;
	queue->show();
	queue->removeMin()->show();
	std::cout << std::endl;
	queue->show();
	queue->removeMin()->show();
	std::cout << std::endl;
	queue->show();
	queue->removeMin()->show();
	std::cout << std::endl;
	queue->show();
	std::cout << "Wpycham 1\n";
	queue->insert(1, new Vertex<int, int>(4));
	queue->show();
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
	std::cout << "Czy zapisac koszty drogi i sciezki do pliku Dijkstra.txt? t/n: ";
	char t;
	bool toFile = false;
	do{
		std::cin >> t;
	} while (t != 'n' && t != 't');
	if (t == 't') {
		toFile = true;
	}
	std::ofstream file;
	if (toFile) {
		file.open("Dijkstra.txt", std::ofstream::out | std::ofstream::app);
		file << "Graf na macierzy - wyniki dzialania algorytmu: \n";
		file.close();
	}
	Dijkstra(graph, time, toFile);
	std::cout << "Zakonczono test dla grafu na macierzy. Czas dzialania algorytmu: " << time <<"micro s\n";
	if (toFile) {
		file.open("Dijkstra.txt", std::ofstream::out | std::ofstream::app);
		file << "Graf na liscie - wyniki dzialania algorytmu: \n";
		file.close();
	}
	Dijkstra(graph2, time, toFile);
	std::cout << "Zakonczono test dla grafu na liscie. Czas dzialania algorytmu: " << time << "micro s\n";
	delete graph2;
	delete graph;
}