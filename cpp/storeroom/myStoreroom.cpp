#include "myStoreroom.h"
#include "stdafx.h"
STOREROOM *CreateElement(size_t obj) {
	STOREROOM *sRoom = (STOREROOM*)calloc(obj, sizeof(STOREROOM));
	return sRoom;
}