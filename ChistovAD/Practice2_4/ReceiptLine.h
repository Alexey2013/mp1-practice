#ifndef _RECIPTLINE_H
#define _RECIPTLINE_H
#include <string>
#include "Container.h"
using namespace std;

class ReceiptLine : public Container
{
public:
	Product* product;
	int count;
	double sum;
};

#endif _RECIPTLINE_H