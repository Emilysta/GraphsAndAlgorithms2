#pragma once
#include <string>
#include <iostream>
#include "GraphOnMatrix.h"
#include "GraphOnList.h"
#include "DijkstraAlgorithm.h"

void timesTest() {
	const int countOfInstances = 100;
	const int types = 20;
	std::string names[types] = { "c10d25x","c10d50x","c10d75x" ,"c10d100x" , //c oznacza ilosc wierzcho�k�w od "count"
							"c50d25x","c50d50x","c50d75x" ,"c50d100x" ,	//d oznacza gesto�� od "density"  
							"c100d25x","c100d50x","c100d75x" ,"c100d100x" , //numer po "x" oznacza numer insatncji
							"c500d25x","c500d50x","c500d75x" ,"c500d100x" ,
							"c1000d25x","c1000d50x","c1000d75x" ,"c1000d100x" };
	std::string density[4] = { "0,25","0,50","0,75","1,00" }; //g�sto�ci
	int countOfVertices[5] = { 10,50,100,500,1000 }; //ilosci wierzcho�k�w
	std::ofstream file;
	double timeMatrix = 0;
	double timeList = 0;
	file.open("Czasy.csv");
	if (file.good()) {
		file << "Liczba wierzcholkow;Gestosc;Macierz[micros];Lista[micros]\n";
		for (int i = 0; i < types; i++) {
			for (int j = 0; j < countOfInstances; j++) { //wczytanie do tablic 100 instancji danego typu
				std::string nameOfFile = "E:\\Code\\Pliki\\";
				nameOfFile += names[i];
				nameOfFile += std::to_string(j + 1);
				nameOfFile += ".txt";
				GraphOnMatrix<int> arrayMatrix;
				GraphOnList<int> arrayList;
				arrayMatrix.fillGraph(nameOfFile);
				arrayList.fillGraph(nameOfFile);
				std::cout << "..1\n";
				double time = 0;
				Dijkstra(&arrayMatrix, time, false);
				timeMatrix += time;
				Dijkstra(&arrayList, time, false);
				timeList += time;
			}
			file << countOfVertices[i / 4] << ";" << density[i % 4] << ";" << timeMatrix << ";" << timeList << "\n";
			std::cout << i << " typ.\n";
		}
	}
	else
	{
		std::cerr << "Nie mo�na utworzy�/otworzy� pliku" << std::endl;
	}
	file.close();
}