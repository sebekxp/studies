#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

#define subinterval 100000
#define n 10000000


double f1(double x)
{
	return x;
}
double f2(double x)
{
	double y;
	y = x / (x*x*x + 1);
	return y;
}
double f3(double x)
{
	return sin(2 * x)*x;
}
double f4(double x) {

	return 1. / 2 * x*x - 2;
}
double random(double start, double end)
{
	
	double a = rand();
	
	a /= (1.0)*RAND_MAX;
	a *= (end - start);
	a += start;
	return a;

}
double findMAX(double(*f)(double), int start, int end)
{	
	double MAX = 0;
	double step = (1.0*(end - start)) / (1.*subinterval);
	for (double i = start; i < end; i += step)
	{
		double score = (*f)(i);
		if (score > MAX)
			MAX = score;
	}
	return MAX;
}
double findMIN(double(*f)(double), int start, int end)
{
	double MIN = 0;
	double step = (1.0*(end - start)) / subinterval;
	for (double i = start; i < end; i += step)
	{
		double score = (*f)(i);
		if (score < MIN)
			MIN = score;

	}
	return MIN;
}
double rectangle(double(*f)(double),int start,int end)
{
	double step, x, sum = 0;
	step = (1.0*(end - start)) / subinterval;
	for (x = start; x < end; x += step) 
		sum += (*f)(x)*step;
	return sum;
}
double trapeze(double(*f)(double), int start, int end)
{
	double step, x, sum = 0;
	step = (1.0*(end - start)) / subinterval;
	sum = 0.5*((*f)(start)+(*f)(end));
	for (x = start + step; x < end; x += step)
		sum += (*f)(x);
	sum *= step;
	return sum;
}
double MonteCarlo(double(*f)(double), int start, int end)
{
	srand(time(NULL));

	double x, y, hit = 0, integral, stepX, stepY;
	int i;

	double MAX = findMAX(f, start, end);
	double MIN = findMIN(f, start, end);

	stepX = (end - start);
	stepY = (MAX - MIN);

	for (i = 0; i < n; i++)
	{ 
	x = random(start, end);
	y = random(MIN, MAX);

	if (y > 0 && (*f)(x) > y)
		hit++;

	else if ((*f)(x) < y && y < 0)
		hit--;
	}
	integral = hit*stepX*stepY / n;

	return integral;
}
int main()
{	
	int start, end;
	printf("Poczatek przedzialu: ");
	scanf("%d", &start);
	printf("Koniec przedzialu: ");
	scanf("%d", &end);
	printf("\n");

	printf("Calka oznaczona funkcji jednej zmiennej w przedziale <%d, %d> obliczona\nmetodami: prostokatow, trapezow oraz Monte Carlo dla 4 roznych funkcji\n\n",start,end);

	printf("Wyniki dla funkcji f(x)=x\n\n");
	printf("Wynik prostokaty:  %lf\n", rectangle(f1, start, end));
	printf("Wynik trapezy:  %lf\n",trapeze(f1, start, end));
	printf("Wynik Monte Carlo:  %lf\n\n", MonteCarlo(f1, start, end));


	printf("Wyniki dla funkcji f(x)=x/(x*x*x+1)\n\n");
	printf("Wynik prostokaty:  %lf\n",rectangle(f2, start, end));
	printf("Wynik trapezy:  %lf\n",trapeze(f2, start, end));
	printf("Wynik Monte Carlo:  %lf\n\n", MonteCarlo(f2, start, end));

	printf("Wyniki dla funkcji f(x)=sin(2*x)*x\n\n");
	printf("Wynik prostokaty:  %lf\n",rectangle(f3, start, end));
	printf("Wynik trapezy:  %lf\n",trapeze(f3, start, end));
	printf("Wynik Monte Carlo:  %lf\n\n", MonteCarlo(f3, start, end));

	printf("Wyniki dla funkcji f(x)=1. / 2 * x*x-2\n\n");
	printf("Wynik prostokaty:  %lf\n",rectangle(f4, start, end));
	printf("Wynik trapezy:  %lf\n",trapeze(f4, start, end));
	printf("Wynik Monte Carlo:  %lf\n\n", MonteCarlo(f4, start, end));
    return 0;
}

