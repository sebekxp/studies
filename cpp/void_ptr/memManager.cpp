#include "stdafx.h"
#include <stdio.h>
#include "memManager.h"

static size_t TotalOccupedMem = 0;   //Ogólnie alokowana pamiêæ, B.
static size_t last = 0;              //pierwsza wolna pozycja w MemTab.
static size_t AllocCount = 0;

static MY_MEMORY_MANAGE *MemTab = NULL;

int MyMemInit() {

	MemTab = (MY_MEMORY_MANAGE*)malloc(5 * sizeof(MY_MEMORY_MANAGE));
	if (!MemTab) {
		printf("Memory allocation error\n");
		return 0;
	}
	memset(MemTab, 0, 5 * sizeof(MY_MEMORY_MANAGE));
}
void MyMemClose() {
	size_t size = _msize(MemTab) / sizeof(MY_MEMORY_MANAGE), it;

	for (it = 0; it < size; ++it) {
		if (MemTab[it].ptr != NULL) {
			printf("Memory leak, num alloc: %llu", MemTab[it].numAlloc);
			free(MemTab[it].ptr);
			MemTab[it].ptr = NULL;
		}
	}
	if (TotalOccupedMem == 0)
		printf("TotalOccupedMem is not equal to zero\n");
	free(MemTab);
	MemTab = NULL;
}
void * MyMemAlloc(size_t NoBytes)
{
	size_t noitems = _msize(MemTab) / sizeof(MY_MEMORY_MANAGE);

	if (last >= noitems)
	{
		MemTab = (MY_MEMORY_MANAGE *)realloc(MemTab, 2 * noitems * sizeof(MY_MEMORY_MANAGE));
		if (MemTab)
			memset(MemTab + noitems, 0, noitems * sizeof(MY_MEMORY_MANAGE));
	}

	MemTab[last].ptr = malloc(NoBytes);
	if (MemTab[last].ptr)
	{
		MemTab[last].numAlloc = AllocCount++;
		TotalOccupedMem += NoBytes;
	}

	return MemTab[last++].ptr;
}
void * MyMemRealloc(void *ptr, size_t NoBytes) {

	size_t noitems = _msize(MemTab) / sizeof(MY_MEMORY_MANAGE);
	for (size_t i = 0; i < noitems; ++i) {
		if (MemTab[i].ptr == ptr) {
			TotalOccupedMem -= _msize(MemTab[i].ptr);
			MemTab[i].ptr = realloc(MemTab[i].ptr, NoBytes);
			if (MemTab[i].ptr) {

			}
		}
	}

}
