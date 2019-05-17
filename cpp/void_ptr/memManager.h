#pragma once
struct MY_MEMORY_MANAGE
{
	void * ptr;			//wskaznik typu void *
	size_t numAlloc;            //kolejny numer alokowania
};

int MyMemInit();
void MyMemClose();
void * MyMemAlloc(size_t NoBytes);
void * MyMemRealloc(void *ptr, size_t NoBytes);
void MyMemFree(void *ptr);
size_t MyGetOccupedMem();
