// storeroom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myStoreroom.h"
#include "product.h"

//void add_object_to_storeroom(STOREROOM *sRoom);


int main()
{
	size_t elements;
	printf("Number of elements in your storeroom: ");
	scanf("%u", &elements);
	STOREROOM *sRoom = CreateElement(elements);
	
	//add_object_to_storeroom(sRoom);
	ProductInputAndPutData(sRoom);

	
    return 0;
}


