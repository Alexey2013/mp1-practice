#ifndef _RECEIPT_H
#define _RECEIPT_H
#include <string>
#include "Container.h"
using namespace std;

struct Data {
	int year;
	int month;
	int day;
};

struct Time {
	int hour;
	int minute;
	int seconds;
};

class Receipt : public Container
{
public:
	long number;
	Data date;
	Time time;
	Container products;
};
#endif 