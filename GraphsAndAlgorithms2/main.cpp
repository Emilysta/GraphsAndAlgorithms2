#include <iostream>
#include <string>
#include "List.h"
template <typename T>
void GenerateGraphsToFile() {
	const int countOfInstances = 1;
	int countOfVertices[5] = { 10,50,100,500,1000 };
	int maxCountOfEdges[5] = { 45,1225,4950,124750,499500 }; // 0.5*n(n-1) where n is number of vertices 
	float density[4] = { 0.25,0.50,0.75,1.00 };
	const int types = 20;
	std::string names[types] = { "c10d25x","c10d50x","c10d75x" ,"c10d100x" , //c means count
							"c50d25x","c50d50x","c50d75x" ,"c50d100x" ,	 //d means density 
							"c100d25x","c100d50x","c100d75x" ,"c100d100x" , //sth after "x" means number of instancy
							"c500d25x","c500d50x","c500d75x" ,"c500d100x" ,
							"c1000d25x","c1000d50x","c1000d75x" ,"c1000d100x" };
	for (int i = 0; i < types; i++) {
		std::string nameOfFile = names[i];
		for (int j = 0; j < countOfInstances; j++) {
			nameOfFile += std::to_string(j + 1);
			std::ofstream file(nameOfFile.c_str());
			//std::cout << nameOfFile << std::endl;
			int edges = (int)(density[i % 4] * maxCountOfEdges[i / 4]); //density of graph
			int startPoint = rand() % countOfVertices[i / 4];//start point from 0 to count-1
			file << edges << "\t" << countOfVertices[i / 4] << "\t" << startPoint << "\n";
			for (int k = 0; k < edges; k++) {
				int startOfEdge;
				int endOfEdge;
				T weight;
				int toSave
			}
		}
	}
}

void test() {
	//Test dzia³ania metod listy
	List<int>* list = new List<int>;
	list->insertOnFront(10);
	list->insertOnFront(11);
	list->insertOnFront(12);
	list->insertOnFront(13);
	list->removeFromFront();
	list->insertOnFront(21);
	std::cout << "Rozmiar: " << list->size() << std::endl;
	list->showList();
	std::cout << list->getHead();
	std::cout << std::endl;
	delete list;
}

int main() {
	//test();
	std::cout << 7 / 4;
	std::cin.ignore();
	return 0;
}