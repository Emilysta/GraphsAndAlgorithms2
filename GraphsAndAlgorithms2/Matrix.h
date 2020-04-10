#pragma once
#include <string>
#include <fstream>
template <typename T> //int,double, float
class Matrix
{
	int numberOfPoints;
	T* ** matrix;
public:
	Matrix();
	Matrix(int n);
	~Matrix();
	void show();
	void setElement(int row, int column, T* element);
	T* getElement(int row, int column) const;
};

template <typename T>
Matrix<T>::Matrix() {
	numberOfPoints = 0;
	matrix = nullptr;
}

template <typename T>
Matrix<T>::Matrix(int n) {
	numberOfPoints = n;
	matrix = new T ** [numberOfPoints];
	for (int i = 0; i < numberOfPoints; i++) {
		matrix[i] = new T*[numberOfPoints];
	}
	for (int i = 0; i < numberOfPoints; i++) {
		for (int j = 0; j < numberOfPoints; j++) {
			matrix[i][j] = nullptr;
		}
	}
}

template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < numberOfPoints; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

template <typename T> //to show edges that are saved
void Matrix<T>::show() {
	for (int i = 0; i < numberOfPoints; i++) {
		for (int j = 0; j < numberOfPoints; j++) {
			if (matrix[i][j] != nullptr) {
				matrix[i][j]->toShowInMatrix();
			}
			else {
				std::cout << "-----";
			}
			std::cout << "   ";
		}
		std::cout << std::endl;
	}
}

template <typename T>
void Matrix<T>::setElement(int row, int column, T* element) {
	matrix[row][column] = element;
}

template <typename T>
T* Matrix<T>::getElement(int row, int column) const {
	return matrix[row][column];
}