#include <iostream>
#include "GraphOnMatrix.h"
#include "GenerateGraphs.h"

void testListOfVertices() {
	//Test dzia³ania metod listy
	ListV* list = new ListV();
	list->insertOnFront(new Vertex<int>(0));
	list->insertOnFront(new Vertex<int>(1));
	list->insertOnFront(new Vertex<int>(2));
	list->insertOnFront(new Vertex<int>(3));
	list->insertOnFront(new Vertex<int>(4));
	std::cout << "Rozmiar: " << list->size() << std::endl;
	list->removeFromBack();
	list->showList();
	std::cout << "Rozmiar: " << list->size() << std::endl;
	list->insertOnBack(new Vertex<int>(0));
	list->showList();
	std::cout << "Rozmiar: " << list->size() << std::endl;

	//std::cout << "Head: ";
	//list->getHead()->getElement()->show();
	//(*list)[4]->show();
	std::cout << std::endl;
	delete list;
}
void graphTest() {
	std::string name = "E:\\Code\\GraphsAndAlgorithms2\\test.txt";
	GraphOnMatrix<int>* graph = new GraphOnMatrix<int>();
	std::cout << "Elo" << std::endl;
	graph->fillGraph(name);
	std::cout << "Elo xd" << std::endl;
	std::cin.ignore();
	std::cout << "Elo xd" << std::endl;
	graph->show();
	delete graph;
}

int main() {
	//testListOfVertices();
	graphTest();
	std::cin.ignore();
	std::cout << "elo 320";
	std::cin.ignore();
	return 0;
}