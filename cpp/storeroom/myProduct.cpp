#include "stdafx.h"
#include "myStoreroom.h"
#include "product.h"


static PRODUCT *sProduct = NULL;
static size_t lastPosition = 0;

PRODUCT *STRUCT_PRODUCT_Init(size_t obj) {
	if (!sProduct) {
		PRODUCT *sProduct = (PRODUCT*)calloc(obj, sizeof(PRODUCT));
		if (!sProduct)
			
		lastPosition = 0;
	}
	
}

int PRODECT_PUSH(PRODUCT product) {

	size_t maxPosition = _msize(sProduct) / sizeof(PRODUCT);
	if (lastPosition >= maxPosition) {
		maxPosition += maxPosition;
		sProduct = (PRODUCT*)realloc(sProduct, maxPosition * sizeof(PRODUCT));
	}
	
}