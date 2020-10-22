#include <iostream>
#include "SecondTask.h"
#include <math.h>
using namespace std;
int Fraction::count = 0;
Fraction::Fraction(int a, int* array) {
	this->array = array;
	this->a = a;
	count = a;
}
void Fraction::printArray() {
	for (int i = 0; i < a * 2; i += 2) {
		cout << array[i] << "/" << array[i + 1] << "  ";
	}
}
int Fraction::gcd(int x, int y)
{
	while (y)
	{
		int temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}
void Fraction::reduce() {
	for (int i = 0; i < a * 2; i += 2) {
		int nod = gcd(array[i], array[i + 1]);
		array[i] /= nod;
		array[i + 1] /= nod;
	}
}
void Fraction::printAsFraction1(double fraction) {
	int test = (int)fraction;
	int tmp = 0;
	while (test != fraction) {
		tmp++;
		fraction *= 10;
		test = (int)fraction;
	}
	int nod = gcd(fraction, pow(10, tmp));
	int x = fraction / nod;
	int y = pow(10, tmp) / nod;
	cout << endl << x << "/" << y << endl;
	count++;
}
void Fraction::printAsFraction2(char* fraction) {
	char* p = strchr(fraction, '.');
	double x = 0.0;
	x = atof(fraction);
	int y = pow(10, strlen(p) - 1);
//далее алгоритм таков же, как и в 1 случае 
	count++;
}
void Fraction::addition(int a, int b) {
	if (a == 1) {
		a--;
	}
	if (b == 1) {
		b--;
	}
	int resultX = (array[a] * array[b + 1] + array[a + 1] * array[b]);
	int resultY = array[a + 1] * array[b + 1];
	cout << array[a] << "/" << array[a + 1] << " + ";
	cout << array[b] << "/" << array[b + 1] << " = ";
	cout << resultX << "/" << resultY << endl;
	count++;
}
void Fraction::subtraction(int a, int b) {
	if (a == 1) {
		a--;
	}
	if (b == 1) {
		b--;
	}
	int resultX = ((array[a] * array[b + 1]) - (array[a + 1] * array[b]));
	int resultY = array[a + 1] * array[b + 1];
	cout << array[a] << "/" << array[a + 1] << " - ";
	cout << array[b] << "/" << array[b + 1] << " = ";
	cout << resultX << "/" << resultY << endl;
	count++;
}
void Fraction::multiplication(int a, int b) {
	if (a == 1) {
		a--;
	}
	if (b == 1) {
		b--;
	}
	int resultX = array[a] * array[b];
	int resultY = array[a + 1] * array[b + 1];
	int nod = gcd(resultX, resultY);
	resultX /= nod;
	resultY /= nod;
	cout << array[a] << "/" << array[a + 1] << " * ";
	cout << array[b] << "/" << array[b + 1] << " = ";
	cout << resultX << "/" << resultY << endl;
	count++;
}
void Fraction::division(int a, int b) {
	if (a == 1) {
		a--;
	}
	if (b == 1) {
		b--;
	}
	int resultX = array[a] * array[b + 1];
	int resultY = array[a + 1] * array[b];
	int nod = gcd(resultX, resultY);
	resultX /= nod;
	resultY /= nod;
	cout << array[a] << "/" << array[a + 1] << " * ";
	cout << array[b] << "/" << array[b + 1] << " = ";
	cout << resultX << "/" << resultY << endl;
	count++;
}
void Fraction::showCount() {
	cout << endl << "Создано " << count << " дробей";
}