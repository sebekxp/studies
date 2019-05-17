#include "stdafx.h"
#include "point.h"
#include "Triangle.h"

void TriangPutData(TRIANGLE *tr, char *str, POINT v1, POINT v2, POINT v3) {
	strcpy_s(tr->title, sizeof(tr->title), str);
	tr->vert[0] = v1;
	tr->vert[1] = v2;
	tr->vert[2] = v3;
}
void TriangInput(TRIANGLE *tr) {

	printf("Enter title and three vertexes in format x, y\n");
	char str[64];
	POINT v1, v2, v3;
	printf("Title: ");
	scanf_s("%s", str, sizeof(str));
	
	int ch;
	while (ch=getchar() != '\n');

	printf("Vertexes 1: ");
	scanf_s("%lf%lf", &v1.x, &v1.y);

	printf("Vertexes 2: ");
	scanf_s("%lf%lf", &v2.x, &v2.y);

	printf("Vertexes 3: ");
	scanf_s("%lf%lf", &v3.x, &v3.y);
	TriangPutData(tr, str, v1, v2, v3);
}
void TRIANGLE_Print(void *ptr) {
	TRIANGLE *triangle = (TRIANGLE *)ptr;
	printf("%s\n", triangle->title);
	for (size_t i = 0; i < 3; ++i) {
		printf("Vertex %u x=%lf y=%lf\n",i+1,triangle->vert[i].x, triangle->vert[i].y);
	}
}