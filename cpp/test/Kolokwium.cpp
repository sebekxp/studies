// Kolokwium.cpp : Defines the entry point for the console application.

//Grupa13
//Paszyński Sebastian
//p15sebek@gmail.com

#include "stdafx.h"
#include <stdlib.h>

MY_BIKE * fun_create_array(int dim);
MY_BIKE * fun_add(int num, MY_BIKE *t1, MY_BIKE *t2);
void fun_print_tab(MY_BIKE *t, char *title);
void fun_free(MY_BIKE **t);
int main()
{	
	int dim_1, dim_2,num;

	printf("Podaj rozmiar tab_1 i rozmiar tab_2: ");
	scanf("%d%d", &dim_1, &dim_2);

	MY_BIKE *tab_1 = fun_create_array(dim_1);
	MY_BIKE *tab_2 = fun_create_array(dim_2);

	fun_print_tab(tab_1, (char*)"tab_1");
	fun_print_tab(tab_2, (char*)"tab_2");

	printf("Numer wiersza po ktorym wstawic tab_2: ");
	scanf("%d", &num);

	tab_1 = fun_add(num, tab_1, tab_2);
	fun_print_tab(tab_1, (char*)"tab_1 after add");

    return 0;
}

MY_BIKE * fun_create_array(int dim) {

	MY_BIKE *tab = (MY_BIKE*)calloc(dim, sizeof(MY_BIKE));
	if (!tab)
		return 0;

	size_t i, j;
	char symb = 'a';
	int year = 1997;

	for (i = 0; i < dim; ++i)
	{
		tab[i].year = year;

		for (j = 0; j < 4; ++j)
			tab[i].model[j] = symb;

		symb++;
		year += 1;
	}
	return tab;
}
void fun_print_tab(MY_BIKE *t, char *title)
{
	size_t i, j;
	size_t dim = _msize(t) / sizeof(MY_BIKE);
	printf("%s\n", title);
	for (i = 0; i < dim; ++i)
	{
		printf("Title: %s year: %d\n", t[i].model, t[i].year);
	}
}
void fun_free(MY_BIKE **t)
{
	if (*t)
	{
		free(*t);
		*t = NULL;
	}
}
MY_BIKE *fun_add(int num, MY_BIKE *t1, MY_BIKE *t2)
{
	size_t nElement_tab_1 = _msize(t1) / sizeof(MY_BIKE);
	size_t nElement_tab_2 = _msize(t2) / sizeof(MY_BIKE);

	t1 = (MY_BIKE *)realloc(t1, (nElement_tab_1 + nElement_tab_2) * sizeof(MY_BIKE));
	if (!t1)
		return NULL;
	
	num += 1;
	memmove(t1+num + nElement_tab_2, t1+num, (nElement_tab_1 - num) * sizeof(MY_BIKE));
	memcpy(t1+num, t2, nElement_tab_2 * sizeof(MY_BIKE));
	
	return t1;

}

