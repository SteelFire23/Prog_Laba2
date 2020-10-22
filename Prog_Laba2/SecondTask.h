#pragma once
class Fraction {
private:
	int a;
	int* array;
public:
	static int count;
	Fraction(int a, int* array);
	void printArray();

	int gcd(int x, int y);
	void reduce();

	void printAsFraction1(double fraction);
	void printAsFraction2(char* fraction);

	void addition(int a, int b);
	void subtraction(int a, int b);
	void multiplication(int a, int b);
	void division(int a, int b);
	void showCount();
};
