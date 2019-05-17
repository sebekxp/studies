#include "stdafx.h"
#include "studen.h"

void STUDENT_Print(void *ptr) {
	STUDENT *student = (STUDENT *)ptr;
	printf("%s\n", student->name);
	printf("%lf\n", student->score);
	printf("%d\n", student->year);
}
