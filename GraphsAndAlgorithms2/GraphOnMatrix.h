#pragma once
#include "Matrix.h"
#include "TypesOfList.h"

template <typename T>
class GraphOnMatrix
{
	ListV* listOfVertices;
	ListE* listOfEdges;
	Matrix<Edge<T>*>* aMatrix; //short version of adjacency matrix - macierz s¹siedztwa;
	int startVertex;

public:
	GraphOnMatrix();
	~GraphOnMatrix();
	void fillGraph(std::string nameOfFile);
	void show();
};

template < typename T >
GraphOnMatrix<T>::GraphOnMatrix() {
	listOfEdges = new ListE();
	listOfVertices = new ListV();
	aMatrix = new Matrix<Edge<T>*>();
	startVertex = 0;
}

template < typename T >
GraphOnMatrix<T>::~GraphOnMatrix() {
	//delete listOfEdges;
	//delete listOfVertices;
	//delete aMatrix;
}

template <typename T>
void GraphOnMatrix<T>::fillGraph(std::string nameOfFile) { //do poprawy Bardzo Wazne
	int numberOfEdges;
	int numberOfVertices;

	int row;  //startpoint of edge
	int column; //endpoint 
	T weight;
	std::fstream file;

	file.open(nameOfFile.c_str());
	if (file.good()) {
		file >> numberOfEdges >> numberOfVertices >> startVertex;
		aMatrix = new Matrix<Edge<T>*>(numberOfVertices);
		for (int i = 0; i < numberOfVertices; i++) {
			listOfVertices->insertOnBack(new Vertex<int>(i)); //no i trzeba te wskazniki na sameg siebie!!!!
		}
		while (!file.eof())
		{
			file >> row >> column >> weight;
			Edge<T>* edge = new Edge<T>(weight,nullptr,(*listOfVertices)[row],(*listOfVertices)[column]);// tutaj do poprawy napisac searcha do wyszukiwania wierdzcholku o numerze xd
			listOfEdges->insertOnBack(edge);
			aMatrix->setElement(row, column, edge);
			edge = new Edge<T>(weight, nullptr, (*listOfVertices)[column], (*listOfVertices)[row]);
			listOfEdges->insertOnBack(edge);
			aMatrix->setElement(column, row, edge);
		}
	}
	else {
		std::cout << "Plik nie jest poprawny!";
	}
	file.close();
}
template <typename T>
void GraphOnMatrix<T>::show() {
	std::cout << "Liczba krawedzi: ";
	std::cout << listOfEdges->size();
	std::cout << std::endl;
	std::cout << "Liczba wierzcholkow: ";
	std::cout << listOfVertices->size();
	std::cout << std::endl;
	std::cout << "Wierzcholek startowy: " << startVertex << std::endl;

	aMatrix->show();
}
