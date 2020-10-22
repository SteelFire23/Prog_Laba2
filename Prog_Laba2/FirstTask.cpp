#include <iostream>
#include <iomanip>
#include "FirstTask.h"
using namespace std;
int Factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * Factorial(n - 1);
	}
}
Matrix::Matrix(int a, int b) {
	this->a = a;
	this->b = b;
	firstArray = new int* [a];
	for (int count = 0; count < a; ++count) {
		firstArray[count] = new int[b];
	}
}
void Matrix::fill2D() {
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			firstArray[i][j] = Factorial(i) + Factorial(j);
		}
	}
}
void Matrix::print2D() {
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << setw(8) << firstArray[i][j];
		}
		cout << endl;
	}
}
int Matrix::at(int i, int j) {
	return firstArray[i][j];
}
void Matrix::setAt(int i, int j, int n) {
	firstArray[i][j] = n;
}
Matrix::~Matrix() {
	for (int i = 0; i < a; ++i) {
		delete[]firstArray[i];
	}
	delete[]firstArray;
}
Vector::Vector(int a, int b) {
	this->a = a;
	this->b = b;
	secondArray = new int[a / 2 * b];
}
void Vector::remakeArray(int** firstArray) {
	int count = 0;
	for (int i = 0; i < a; ++i) {
		if ((i + 1) % 2 == 0) {
			for (int j = 0; j < b; ++j) {
				secondArray[count] = (int)firstArray[i][j];
				count++;
			}
		}
	}
}
void Vector::print1D() {
	for (int i = 0; i < (a / 2 * b); i++) {
		cout << secondArray[i] << " ";
	}
}
Vector::~Vector() {
	delete[]secondArray;
}