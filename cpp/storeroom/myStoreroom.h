#pragma once
struct STOREROOM
{
	void *ptr;
	void(*printFun)(void*);
};
STOREROOM *CreateElement(size_t obj);
