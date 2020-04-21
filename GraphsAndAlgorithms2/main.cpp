#include <iostream>
#include "Driver.h"
#include "Times.h"
#include "GenerateGraphs.h"

void menu() {
    std::cout << "1. Test dzialania grafu na macierzy.\n";
    std::cout << "2. Test dzialania grafu na liscie.\n";
    std::cout << "3. Test listy.\n";
    std::cout << "4. Test kolejki.\n";
    std::cout << "5. Test dzialania algorytmu Dijkstry\n";
    std::cout << "6. Testy czasow\n";
    std::cout << "7. Generowanie plikow z grafami\n";
    std::cout << "0. Koniec dzialania programu\n";
    std::cout << std::endl;
}

int main() {
    int exit;
    do {
        menu();
        std::cout << "Wybierz jedna z opcji:";
        std::cin >> exit;
        system("cls");
        switch (exit) {
            case 1: graphOnMatrixTest();
                break;
            case 2: graphOnListTest();
                break;
            case 3: testListOfVertices();
                break;
            case 4: priorityQueueTest();
                break;
            case 5: testDijkstra();
                break;
            case 6: timesTest();
                break;
            case 7: GenerateGraphsToFile<int>();
                break;
            case 0: {
                std::cout << "Konczenie dzialania programu...";
                break;
            }
            default: {
                std::cout << "Nieprawidlowa opcja! ";
                break;
            }
        }
    } while (exit != 0);
	return 0;
}