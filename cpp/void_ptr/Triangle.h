#pragma once
#include "point.h"
struct TRIANGLE
{
	char title[64];
	POINT vert[3];
};
void TriangPutData(TRIANGLE *tr, char *str, POINT v1, POINT v2, POINT v3);
void TriangInput(TRIANGLE *tr);
void TRIANGLE_Print(void *ptr);