#include "stdafx.h"
#include "point.h"
#include "Quad.h"

void QuadPutData(QUAD *qu, char *str, POINT v1, POINT v2, POINT v3, POINT v4) {
	strcpy_s(qu->title, sizeof(qu->title), str);
	qu->vert[0] = v1;
	qu->vert[1] = v2;
	qu->vert[2] = v3;
	qu->vert[3] = v4;

}
void QuadInput(QUAD *qu) {

	printf("Enter title and three vertexes in format x, y\n");
	char str[64];
	POINT v1, v2, v3, v4;
	printf("Title: ");
	scanf_s("%s", str, sizeof(str));

	int ch;
	while (ch = getchar() != '\n');

	printf("Vertexes 1: ");
	scanf_s("%lf%lf", &v1.x, &v1.y);

	printf("Vertexes 2: ");
	scanf_s("%lf%lf", &v2.x, &v2.y);

	printf("Vertexes 3: ");
	scanf_s("%lf%lf", &v3.x, &v3.y);
	
	printf("Vertexes 4: ");
	scanf_s("%lf%lf", &v4.x, &v4.y);

	QuadPutData(qu, str, v1, v2, v3, v4);
}
void QUAD_Print(void *ptr) {
	QUAD *quad = (QUAD*)ptr;
	printf("%s\n", quad->title);
	for (size_t i = 0; i < 4; ++i) {
		printf("Vertex %u x=%lf y=%lf\n", i + 1, quad->vert[i].x, quad->vert[i].y);
	}
}