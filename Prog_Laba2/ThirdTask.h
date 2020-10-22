#pragma once
#include <string>
using namespace std;
class Stadium {
private:
	string name_;
	string address_;
	int sectors_, capacity_;
	float attendance_;
	int i;
public:
	Stadium();
	Stadium(string name, string address, int sec, int cap, float att, int num);

	void setName(string name);
	void setAddress(string address);
	void setSectors(int sec);
	void setCapacity(int cap);
	void setAttendance(float att);
	void setNumber(int num);

	double getValue();

	void printInfo();

	void serialize();
	void deserialize();
	void serialize(const string& filename);
	void deserialize(const string& filename);
};
