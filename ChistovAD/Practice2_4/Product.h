#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <string>
#include "ReceiptLine.h"
using namespace std;

class Product : public ReceiptLine
{
public:
	long code;
	string name;
	double cost;
};

#endif