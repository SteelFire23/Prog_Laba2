#include "ThirdTask.h";
#include <iostream>;
#include <fstream>;
using namespace std;

Stadium::Stadium() {

}
Stadium::Stadium(string name, string address, int sec, int cap, float att, int num) {
	name_ = name;
	address_ = address;
	sectors_ = sec;
	capacity_ = cap;
	attendance_ = att;
	i = num;
}
void Stadium::setName(string name) {
	name_ = name;
}
void Stadium::setAddress(string address) {
	address_ = address;
}
void Stadium::setSectors(int sec) {
	sectors_ = sec;
}
void Stadium::setCapacity(int cap) {
	capacity_ = cap;
}
void Stadium::setAttendance(float att) {
	attendance_ = att;
}
void Stadium::setNumber(int num) {
	i = num;
}
double Stadium::getValue() {
	return attendance_;
}
void Stadium::printInfo() {
	cout << name_ << " " << address_ << " " << sectors_ << " " << capacity_ << " " << attendance_ << endl;
}
void Stadium::serialize() {
	string name;
	if (i == 1) { name = "1.txt"; }
	if (i == 2) { name = "2.txt"; }
	if (i == 3) { name = "3.txt"; }
	ofstream myFile;
	myFile.open(name);
	myFile << name_ << " " << address_ << " " << sectors_ << " " << capacity_ << " " << attendance_ << endl;
}
void Stadium::deserialize() {
	string name;
	if (i == 1) { name = "1.txt"; }
	if (i == 2) { name = "2.txt"; }
	if (i == 3) { name = "3.txt"; }
	ifstream myFile(name);
	char buff[100];
	myFile.getline(buff, 100);
	myFile.close();
	cout << buff << endl;
}
void Stadium::serialize(const string& filename) {
	ofstream myFile;
	myFile.open(filename);
	myFile << name_ << " " << address_ << " " << sectors_ << " " << capacity_ << " " << attendance_ << endl;
}
void Stadium::deserialize(const string& filename) {
	ifstream myFile(filename);
	char buff[100];
	myFile.getline(buff, 100);
	myFile.close();
	cout << buff << endl;
}
