#include "stdafx.h"
#include "myTab.h"

ELEMENT *CreateElement(size_t obj) {
	ELEMENT *newArray = (ELEMENT*)calloc(obj, sizeof(ELEMENT));
	//ELEMENT *myTablica = (ELEMENT*)malloc(obj*sizeof(ELEMENT));
	//memset((void*)myTablica, 0, obj * sizeof(ELEMENT));
	return newArray;
}