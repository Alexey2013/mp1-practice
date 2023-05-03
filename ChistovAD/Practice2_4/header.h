#ifndef  HEADER_H
#define _HEADER_H
#include <string>
using namespace std;

template <typename T>
class Container {
private:
	T *elements;
	int max_size;
	int size:
	int step;
	int pas;
public:
	Container(int max_size, int step);
	~Container();
	void Add(T _elements);
	void Del(T _elements);

};

class Product : public Recipline
{
public:
	long code;
	string name;
	double cost;
};

string get_path();

class Receipt : public Container
{
public:
	float number;
	Date date;
	Time time;
	Container products;
};

class ReceiptLine : public Container
{
public:
	int count; 
	double sum;
	Product* product;
};

class Date {
public:
	int year;
	int month;
	int day;
};

class Time {
public:
	int hour;
	int minute;
	int second;
};
#endif 
