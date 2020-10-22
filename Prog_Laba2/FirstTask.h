#pragma once
class Matrix {
private:
	int a;
	int b;
public:
	int** firstArray;
	Matrix(int a, int b);
	void fill2D();
	void print2D();
	int at(int i, int j);
	void setAt(int i, int j, int n);
	~Matrix();
};
class Vector {
private:
	int a;
	int b;
	int* secondArray;
public:
	Vector(int a, int b);
	void remakeArray(int** firstArray);
	void print1D();
	~Vector();
};


