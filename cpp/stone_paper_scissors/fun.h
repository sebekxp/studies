#pragma once

#ifndef FUN_H

#define FUN_H 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

void logika(char mojRuchOld, int & PktComp, int & PktTy);
void wczytaniePliku(int &sumaWinY, int &sumaWinC, int &sumaoldtypkt, int &sumaoldcomppkt, int &nrLini, string linia, int &sumawygranaTy, int &sumawygranaComp, int &sumaPktTy, int &sumaPktComp, string& x, string &y, string &z, string &b, string &v);
void zapisywaniePliku(int &sumaWinY, int &sumaWinC, int &sumaoldtypkt, int &sumaoldcomppkt, string x, string y, string z, string b, string v);

#endif

