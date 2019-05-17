#pragma once
#include "point.h"
struct QUAD
{
	char title[64];
	POINT vert[4];
};
void QuadPutData(QUAD *qu, char *str, POINT v1, POINT v2, POINT v3, POINT v4);
void QuadInput(QUAD *qu);
void QUAD_Print(void *ptr);