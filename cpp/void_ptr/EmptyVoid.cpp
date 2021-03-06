#include "stdafx.h"
#include "data.h"
#include "Triangle.h"
#include "Quad.h"
#include "myTab.h"
#include "studen.h"

//void addObject(ELEMENT *myTab);
//void addObjecttoFigure(ELEMENT *myTab);
//static ELEMENT **myTablica;
//Zrobic oblusge myTablica w osobnym pliku
//Push Free Create element



void addObject(ELEMENT *myTab){	
	STUDENT *pStudent;
	pStudent = (STUDENT*)calloc(1, sizeof(STUDENT));

	myTab[0].ptr = pStudent;
	myTab[0].printFun = STUDENT_Print;
	printf("Enter name: ");
	scanf("%s", pStudent->name);
	pStudent->year = 1997;
	pStudent->score = 3.14;

}
void addObjecttoFigure(ELEMENT *myTab){
	TRIANGLE *tr;
	tr = (TRIANGLE*)calloc(1, sizeof(TRIANGLE));
	
	TriangInput(tr);

	myTab[0].ptr = tr;
	myTab[0].printFun = TRIANGLE_Print;

	QUAD *qu;
	qu = (QUAD*)calloc(1, sizeof(QUAD));

	QuadInput(qu);

	myTab[1].ptr = qu;
	myTab[1].printFun = QUAD_Print;
}

int main()
{
	ELEMENT *myTab = CreateElement(3);
	//addObject(myTab);
	addObjecttoFigure(myTab);
	for (int i = 0; i < 3; ++i) {
		if (myTab[i].ptr != NULL)
			myTab[i].printFun(myTab[i].ptr);
	}
	return 0;
}
