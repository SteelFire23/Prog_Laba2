// Prog_Laba2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include "FirstTask.h"
#include "SecondTask.h"
#include "ThirdTask.h"
using namespace std;
int main()
{
	A:
	setlocale(LC_ALL, "rus");
	int number = 0;
	cout << endl << "Выберите номер задания" << endl;
	cin >> number;
	switch (number) {
	case 1: {
		int i = 0, j = 0, num = 0;
		cout << "Введите число строк ";
		cin >> i;
		cout << "Введите число столбцов ";
		cin >> j;
		Matrix obj(i, j);
		Vector obj1(i, j);
		obj.fill2D();
		obj.print2D();
		i = 0, j = 0;
		cout << "Введите индекс i: ";
		cin >> i;
		cout << "Введите индекс j: ";
		cin >> j;
		cout << "Элемент под данным индексом: " << obj.at(i, j) << endl;
		cin.get(); cin.get();
		system("cls");
		i = 0, j = 0;
		cout << "Введите индекс i: ";
		cin >> i;
		cout << "Введите индекс j: ";
		cin >> j;
		cout << "Введите число ";
		cin >> num;
		obj.setAt(i, j, num);
		cout << "Элемент под данным индексом заменен на " << num << endl;
		obj.print2D();
		cin.get(); cin.get();
		system("cls");
		obj1.remakeArray(obj.firstArray);
		cout << "Двумерный массив" << endl;
		obj.print2D();
		cout << endl << "Одномерный массив" << endl;
		obj1.print1D();
		obj.~Matrix();
		obj1.~Vector();
	}
	case 2: {
		int a = 0, x = 0, y = 0;
		cout << "Сколько дробей? ";
		cin >> a;
		cout << "Введите пары чисел (числитель и знаменатель) " << endl;
		int* array = new int[a * 2];
		for (int i = 0; i < a * 2; i+=2) {
			cin >> x;
			cin >> y;
			array[i] = x;
			array[i + 1] = y;
		}
		system("cls");
		//Вывод введенных дробей
		//
		cout << "Дроби" << endl;
		Fraction obj(a, array);
		obj.printArray();
		cout << endl << "После сокращения" << endl;
		obj.reduce();
		obj.printArray();
		//
		cout << endl << "Введите десятичную дробь" << endl;
		double num = 0;
		cin >> num;
		/*char* s = new char[9];
		cin >> s;*/
		obj.printAsFraction1(num);
		//obj.printAsFraction2(s);
		// почему-то функция atof не возвращае число, а возвращает
		// все символы ДО точки в виде числа...
		cin.get(); cin.get();
		system("cls");
		x = 0, y = 0;
		cout << "Введите номера дробей" << endl;
		cin >> x;
		cin >> y;
		//Математически действия 
		//
		obj.addition(x, y);
		obj.subtraction(x, y);
		obj.multiplication(x, y);
		obj.division(x, y);
		//
		obj.showCount();
	}
	case 3: {
		Stadium* obj = new Stadium[2]();
		int* first = new int[4];
		int* second = new int[4];
		int* third = new int[4];
		for (int i = 0; i < 4; ++i) {
			first[i] = rand() % 42000;
			second[i] = rand() % 36540;
			third[i] = rand() % 78360;
			//cout << first[i] << " " << second[i] << " " << third[i] << " ";
		}
		float att1 = (float)(((first[0] + first[1] + first[2] + first[3]) / 42000) / 4);
		float att2 = (float)(((second[0] + second[1] + second[2] + second[3]) / 36540) / 4);
		float att3 = (float)(((third[0] + third[1] + third[2] + third[3]) / 78360) / 4);

		obj[0].setName("Spartac");
		obj[0].setAddress("Volokolamskoe highway 69");
		obj[0].setSectors(4);
		obj[0].setCapacity(42000);
		obj[0].setAttendance(att1);
		obj[0].setNumber(1);
		
		obj[1].setName("Dynamo");
		obj[1].setAddress("Leningradsky Prospect 36");
		obj[1].setSectors(4);
		obj[1].setCapacity(36540);
		obj[1].setAttendance(att2);
		obj[1].setNumber(2);
		
		Stadium obj2("Luzhniki", "st.Luzhniki 9A", 4, 78360, att3, 3);
		if (max(obj[0].getValue(), obj[1].getValue()) < obj2.getValue()) {
			obj2.printInfo();
			if (obj[0].getValue() > obj[1].getValue()) {
				obj[0].printInfo();
				obj[1].printInfo();
			}
			else {
				obj[1].printInfo();
				obj[0].printInfo();
			}
		}
		else {
			if(obj[0].getValue() > obj[1].getValue()) {
				obj[0].printInfo();
				if (obj[1].getValue() < obj2.getValue()) {
					obj2.printInfo();
					obj[1].printInfo();
				}
				else {
					obj[1].printInfo();
					obj2.printInfo();
				}
			}
			else {
			obj[1].printInfo();
			if (obj[0].getValue() < obj2.getValue()) {
				obj2.printInfo();
				obj[0].printInfo();
			}
			else {
				obj[0].printInfo();
				obj2.printInfo();
			}
			}
		}
		obj[0].serialize();
		obj[1].serialize();
		obj2.serialize();
		cout << endl;
		obj[0].serialize("D:\\1.txt");
		obj[1].serialize("D:\\2.txt");
		obj2.serialize("D:\\3.txt");
		cout << endl << "Результат чтения из файлов" << endl;
		obj[0].deserialize();
		obj[1].deserialize();
		obj2.deserialize();
		cout << endl;
		obj[0].deserialize("D:\\1.txt");
		obj[1].deserialize("D:\\2.txt");
		obj2.deserialize("D:\\3.txt");
	}
	case 4:break;
	default:
		goto A;
	}
}
