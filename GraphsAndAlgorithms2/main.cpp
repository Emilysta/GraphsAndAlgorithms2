#include <iostream>
#include "GraphOnMatrix.h"
#include "GenerateGraphs.h"
#include "PQueue.h"

void testListOfVertices() {
	//Test dzia³ania metod listy
	ListV* list = new ListV();
	std::cout<<list->size();
	list->insertOnBack(new Vertex<int>(-1));
	list->insertOnBack(new Vertex<int>(0));
	list->insertOnFront(new Vertex<int>(0));
	list->insertOnFront(new Vertex<int>(1));
	list->insertOnFront(new Vertex<int>(2));
	list->insertOnFront(new Vertex<int>(3));
	list->insertOnFront(new Vertex<int>(4));
	list->showList();
	std::cout << "Rozmiar: " << list->size() << std::endl;
	list->removeFromFront();
	list->removeFromFront();
	list->showList();
	list->removeFromFront();
	list->showList();
	std::cout << "Rozmiar: " << list->size() << std::endl;
	list->insertOnBack(new Vertex<int>(0));
	list->showList();
	std::cout << "Rozmiar: " << list->size() << std::endl;
	std::cout << "Head: ";
	list->getHead()->getElement()->show();
	std::cout << std::endl;
	std::cout << " Element o 6 indeksie: ";
	if ((*list)[6] != nullptr) {
		(*list)[6]->show();
	}
	std::cout << std::endl;
	delete list;
}
void graphTest() {
	std::string name = "E:\\Code\\GraphsAndAlgorithms2\\test.txt";
	GraphOnMatrix<int>* graph = new GraphOnMatrix<int>();
	graph->fillGraph(name);
	graph->show();
	delete graph;
}
void priorityQueueTest() {
	PQueue<Vertex<int>, int>* queue= new PQueue<Vertex<int>,int>();
	queue->insert(10, new Vertex<int>(10));
	queue->insert(0, new Vertex<int>(0));
	queue->show();
	//std::cout<<queue->min()->getKey();
}

int main() {
	//testListOfVertices();
	//graphTest();
	priorityQueueTest();
	std::cin.ignore();
	return 0;
}