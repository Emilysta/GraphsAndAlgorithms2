#include <iostream>
#include "GraphOnMatrix.h"
#include "GenerateGraphs.h"
#include "PQueue.h"
#include "DijkstraAlgorithm.h"

void testListOfVertices() {
	//Test dzia³ania metod listy
	ListV* list = new ListV();
	list->removeAtIndex(0);
	list->insertOnBack(new Vertex<int>(0));
	list->insertOnBack(new Vertex<int>(1));
	list->insertOnBack(new Vertex<int>(2));
	list->insertOnBack(new Vertex<int>(3));
	list->insertOnBack(new Vertex<int>(4));
	list->insertOnBack(new Vertex<int>(5));
	list->showList();
	list->removeAtIndex(2);
	//std::cout << "Rozmiar: " << list->size() << std::endl;
	//list->insertAfter(5, new Vertex<int>(7));
	//list->showList();
	//list->removeFromBack();
	//list->showList();
	//std::cout << "Rozmiar: " << list->size() << std::endl;
	//list->insertOnBack(new Vertex<int>(0));
	list->showList();
	std::cout << "Rozmiar: " << list->size() << std::endl;
	//std::cout << "Head: ";
	//list->getHead()->getElement()->show();
	//std::cout << std::endl;
	std::cout << "Element o 6 indeksie: ";
	if ((*list)[6] != nullptr) {
		(*list)[6]->show();
	}
	std::cout << std::endl;
	delete list;
}
void graphTest() {
	std::string name = "E:\\Code\\GraphsAndAlgorithms2\\test.txt";
	std::cout << name;
	GraphOnMatrix<int>* graph = new GraphOnMatrix<int>();
	graph->fillGraph(name);
	graph->show();
	////graph->vertices();
	////graph->edges();
	//Vertex<int>** arr = graph->endVertices(new Edge<int>(4, nullptr, new Vertex<int>(0), new Vertex<int>(1)));
	//arr[0]->show();
	//arr[1]->show();
	////graph->removeEdge(Edge<int>(4, nullptr, new Vertex<int>(0), new Vertex<int>(1)));
	//graph->removeVertex(Vertex<int>(2));
	//graph->show();
	////Edge<int>* edge = new Edge<int>(7, nullptr, (graph->vertices())[1], (graph->vertices())[2]);
	//graph->insertEdge((*graph->vertices())[1], (*graph->vertices())[2],7);
	//graph->show();
	//graph->incidentEdges(new Vertex<int>(0))->showList();
	//std::cout << "Wiercholek przeciwlegly do 1, wzgledem krawedzi 0.1.4 :";
	//graph->opposite(new Vertex<int>(1), new Edge<int>(4, nullptr, new Vertex<int>(0), new Vertex<int>(1)))->show();
	//std::cout << std::endl;
	//if (graph->areAdjacent(new Vertex<int>(1), new Vertex<int>(0)))
	//{
	//	std::cout << "Sa sasiednie." << std::endl;
	//}
	//graph->replaceV(new Vertex<int>(0), 7);
	//graph->replaceE(new Edge<int>(4, nullptr, new Vertex<int>(7), new Vertex<int>(1)), 5);
	//graph->show();
	std::cout << "Dlugosc najkrotszych sciezek dla wierzcholkkow: \n";
	std::cout << "Dlug . Wierzcholek \n";
	PQueue<Vertex<int>, int>* queue = Dijkstra(graph);
	queue->showWithVertex();
	delete graph;
}
void priorityQueueTest() {
	PQueue<Vertex<int>, int>* queue= new PQueue<Vertex<int>,int>();
	queue->insert(10, new Vertex<int>(0));
	queue->insert(0, new Vertex<int>(1));
	queue->insert(5, new Vertex<int>(2));
	queue->insert(7, new Vertex<int>(3));
	queue->insert(1, new Vertex<int>(4));

	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;

	//std::cout<<queue->min()->getKey();
}

int main() {
	//testListOfVertices();
	//graphTest();
	GenerateGraphsToFile<int>();
	//priorityQueueTest();
	std::cin.ignore();
	return 0;
}