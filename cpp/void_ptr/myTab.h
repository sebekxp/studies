#pragma once
struct ELEMENT
{
	void *ptr;
	void(*printFun)(void*);
};

ELEMENT *CreateElement(size_t obj);