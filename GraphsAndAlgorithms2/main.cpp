#include <iostream>
#include "GraphOnMatrix.h"
#include "GraphOnList.h"
#include "GenerateGraphs.h"
#include "PQueue.h"
#include "DijkstraAlgorithm.h"
#include "Times.h"


void testListOfVertices() {
	//Test dzia³ania metod listy
	ListV* list = new ListV();
	list->removeAtIndex(0);
	list->insertOnBack(new Vertex<int,int>(0));
	list->insertOnBack(new Vertex<int,int>(1));
	list->insertOnBack(new Vertex<int,int>(2));
	list->insertOnBack(new Vertex<int,int>(3));
	list->insertOnBack(new Vertex<int,int>(4));
	list->insertOnBack(new Vertex<int,int>(5));
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
	std::string name = "E:\\Code\\Pliki\\c500d100x39.txt"; //\\GraphsAndAlgorithms2\\test.txt";//
	std::cout << name << std::endl;
	//GraphOnMatrix<int>* graph = new GraphOnMatrix<int>();
	//graph->fillGraph(name);
	///graph->show();
	GraphOnList<int>* graph2 = new GraphOnList<int>();
	graph2->fillGraph(name);
	graph2->show();
	//graph2->incidentEdges((*graph2->vertices())[0])->showList();
	//if (graph->areAdjacent(new Vertex<int>(1), new Vertex<int>(0))) {
	//	std::cout << "sa sasiednie"<<std::endl;
	//}
	/*graph2->insertVertex(4);
	graph2->show();*/
	//graph->show();
	/*graph2->insertEdge(new ExtendedVertex<int,int>(2), new ExtendedVertex<int,int>(4), 6);
	graph2->show();*/
	//graph->removeVertex(new Vertex<int>(4));
	//graph->show();
	//graph->removeEdge(new Edge<int>(4, nullptr, new Vertex<int>(0), new Vertex<int>(1)));
	//graph->show();
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
	//PQueue<Vertex<int,int>, int>* queue = Dijkstra(graph);
	//double time=0;
	//PQueue<Vertex<int,int>, int>* queue2 = Dijkstra(graph2,time);
	//queue2->showWithVertex();
	//std::cout << "Dlugosc najkrotszych sciezek dla wierzcholkkow: \n";
	//std::cout << "w K . dlug . w p \n";
	//queue2->showWithVertex();
	//graph->replaceV((*graph->vertices())[3], 4);
	//graph->replaceE((*graph->edges())[0], 8);
	//graph->show();
	//delete graph;
	delete graph2;
}
void priorityQueueTest() {
	PQueue<Vertex<int,int>, int>* queue= new PQueue<Vertex<int,int>,int>();
	queue->insert(10, new Vertex<int,int>(0));
	queue->insert(0, new Vertex<int,int>(1));
	queue->insert(1, new Vertex<int,int>(2));
	queue->insert(1, new Vertex<int,int>(3));
	queue->insert(1, new Vertex<int,int>(4));
	queue->insert(2, new Vertex<int,int>(0));
	queue->insert(2, new Vertex<int,int>(1));
	queue->insert(1, new Vertex<int,int>(2));
	queue->insert(2, new Vertex<int,int>(3));
	queue->insert(3, new Vertex<int,int>(4));

	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
	queue->show();
	std::cout << queue->removeMin()->getKey() << std::endl;
}

int main() {
	//testListOfVertices();
	//graphTest();
	//priorityQueueTest();
	timesTest();
	std::cout << "elo";
	std::cout << "2";
	std::cout << "2";
	std::cout << "2";
	return 0;
}