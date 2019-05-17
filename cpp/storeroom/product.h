#pragma once
#include "Color.h"
struct PRODUCT
{
	char title[64];
	enum COLOR color;
	double price;
	double weight;
};

void ProductInputAndPutData(STOREROOM *sRoom);
int STRUCT_PRODUCT_Init(size_t obj);
