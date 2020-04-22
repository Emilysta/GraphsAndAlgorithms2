#pragma once
#include <string>
#include <time.h>
template <typename T>
void GenerateGraphsToFile() {
	std::srand((unsigned int)(time(NULL)));
	const int countOfInstances = 100;
	int countOfVertices[5] = { 10,50,100,500,1000 };
	int maxCountOfEdges[5] = { 45,1225,4950,124750,499500 }; // 0.5*n(n-1) where n is number of vertices 
	float density[4] = { 0.25,0.50,0.75,1.00 };
	const int types = 20;
	std::string names[types] = { "c10d25x","c10d50x","c10d75x" ,"c10d100x" , //c means count
							"c50d25x","c50d50x","c50d75x" ,"c50d100x" ,	 //d means density 
							"c100d25x","c100d50x","c100d75x" ,"c100d100x" , //sth after "x" means number of instancy
							"c500d25x","c500d50x","c500d75x" ,"c500d100x" ,
							"c1000d25x","c1000d50x","c1000d75x" ,"c1000d100x" };
	std::cout << "Generowanie grafow...";
	for (int i = 0; i < types; i++) { //to types
		for (int j = 0; j < countOfInstances; j++) {
			std::string nameOfFile = "E:\\Code\\Pliki\\";
			nameOfFile += names[i];
			nameOfFile += std::to_string(j + 1);
			nameOfFile += ".txt";
			std::cout << nameOfFile << std::endl;
			std::ofstream file;
			file.open(nameOfFile.c_str());
			if (file.good()) {
				int edges = (int)(density[i % 4] * maxCountOfEdges[i / 4]); //density of graph
				int startPoint = rand() % countOfVertices[i / 4];//start point from 0 to count-1
				file << edges << "\t" << countOfVertices[i / 4] << "\t" << startPoint << "\n";
				Matrix<int>* toSave = new Matrix<int>(countOfVertices[i / 4]);
				for (int k = 0; k < edges; k++) {
					if (density[i % 4] == 1.00) {
						for (int x = 0; x < countOfVertices[i / 4]; x++) {
							for (int y = 0; y < countOfVertices[i / 4]; y++) {
								if (x != y && toSave->getElement(x, y) == 0) {
									T weight = rand() % 100 + 1; //from 1 to 100
									file << x << "\t" << y << "\t" << weight << "\n";
									k++;
									toSave->setElement(x, y, 1);
									toSave->setElement(y, x, 1);
								}
							}
						}
						break;
					}
					//zapewnienie istnenia polaczen
					if (k == 0) {
						int randR = rand() % countOfVertices[i / 4];
						for (int z = 0; z < countOfVertices[i / 4]; z++) {
							T weight = rand() % 100 + 1; //from 1 to 100
							if (z != randR) {
								file << randR << "\t" << z << "\t" << weight << "\n";
								toSave->setElement(randR, z, 1);
								toSave->setElement(z, randR, 1);
								k++;
							}
						}
					}
					int startOfEdge = rand() % countOfVertices[i / 4];
					int endOfEdge = rand() % countOfVertices[i / 4];
					do {
						endOfEdge = rand() % countOfVertices[i / 4];
					} while (endOfEdge==startOfEdge);
					T weight = rand() % 100 + 1; //from 1 to 100
					if (toSave->getElement(startOfEdge, endOfEdge) == 0 && toSave->getElement(endOfEdge,startOfEdge) == 0) {
						file << startOfEdge << "\t" << endOfEdge << "\t" << weight << "\n";
						toSave->setElement(startOfEdge, endOfEdge, 1);
						toSave->setElement(endOfEdge, startOfEdge, 1);
					}
					else {
						do {
							startOfEdge = rand() % countOfVertices[i / 4];
							do {
								endOfEdge = rand() % countOfVertices[i / 4];
							} while (endOfEdge == startOfEdge);
						} while (toSave->getElement(startOfEdge, endOfEdge) == 1);
						file << startOfEdge << "\t" << endOfEdge << "\t" << weight << "\n";
						toSave->setElement(startOfEdge, endOfEdge, 1);
						toSave->setElement(endOfEdge, startOfEdge, 1);
					}
				}
				delete toSave;
			}
			file.close();
		}
	}
}