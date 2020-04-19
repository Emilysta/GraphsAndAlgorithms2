#pragma once
#include <string>
#include <iostream>
#include "GraphOnMatrix.h"
#include "GraphOnList.h"
#include "DijkstraAlgorithm.h"

void timesTest() {
	const int countOfInstances = 100;
	const int types = 20;
	std::string names[types] = { "c10d25x","c10d50x","c10d75x" ,"c10d100x" , //c means count
							"c50d25x","c50d50x","c50d75x" ,"c50d100x" ,	 //d means density 
							"c100d25x","c100d50x","c100d75x" ,"c100d100x" , //sth after "x" means number of instancy
							"c500d25x","c500d50x","c500d75x" ,"c500d100x" ,
							"c1000d25x","c1000d50x","c1000d75x" ,"c1000d100x" };
	float density[4] = { 0.25,0.50,0.75,1.00 };
	int countOfVertices[5] = { 10,50,100,500,1000 };
	std::ofstream file;
	file.open("Czasy.csv");
	if (file.good()) {
		file << "Liczba wierzcholkow;Gestosc;Macierz[micros];Lista[micros]\n";
		for (int i = 0; i < types; i++) {
			GraphOnMatrix<int> arrayMatrix[countOfInstances];
			GraphOnList<int> arrayList[countOfInstances];
			for (int j = 0; j < countOfInstances; j++) { //wczytanie do tablic 100 instancji danego typu
				std::string nameOfFile = "E:\\Code\\Pliki\\";
				nameOfFile += names[i];
				nameOfFile += std::to_string(j + 1);
				nameOfFile += ".txt";
				arrayMatrix[j].fillGraph(nameOfFile);
				arrayList[j].fillGraph(nameOfFile);
			}
			double timeMatrix = 0;
			double timeList = 0;
			double time = 0;
			for (int j = 0; j < countOfInstances; j++) { //wczytanie do tablic 100 instancji danego typu
				Dijkstra(&arrayMatrix[j], time);
				timeMatrix += time;
				Dijkstra(&arrayList[j], time);
				timeList += time;
			}
			file << countOfVertices[i / 4] << ";" << density[i % 4] << ";" << timeMatrix << ";" << timeList << "\n";
		}
	}
	else
	{
		std::cerr << "Nie mo¿na utworzyæ/otworzyæ pliku" << std::endl;
	}
}