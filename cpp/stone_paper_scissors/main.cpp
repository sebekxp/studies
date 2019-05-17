#include "fun.h"

int main() 
{
		srand(time(0));
		int  PktComp = 0, PktTy = 0,sumawygranaTy=0, sumawygranaComp=0 ,sumaPktTy=0, sumaPktComp=0;
		char mojRuch, wybor;
		int sumaoldtypkt = 0, sumaoldcomppkt = 0, sumaWinY = 0, sumaWinC = 0, nrLini = 1;
		string x, y, z, v, b, linia;;
		cout << " KAMIEN, PAPIER, NOZYCE" << endl;
	

	
	do{
		cout << "Wybierz opcje:" << endl;
		cout << " [1] Nowa Gra " << endl;
		cout << " [2] Wyjscie " << endl;
		cout << " [3] Twoje wyniki " << endl;
		cin >> wybor;
		switch (wybor)
		{
		case '1':
		{
				cout << "                START" << endl;
				while ((PktComp) < 3 && (PktTy) < 3) {
				cout << "==================================" << endl;
				cout << "[1] Kamien  [2] Papier  [3] Nozyce" << endl;
				cin >> mojRuch;
				cout << endl;
				switch (mojRuch) {
				case '1':	logika(mojRuch, PktComp, PktTy);				break;
				case '2':	logika(mojRuch, PktComp, PktTy);				break;
				case '3':	logika(mojRuch, PktComp, PktTy);				break;
				default:	cout << "Nieprawidlowy znak :/ " << endl;		break;

								  }                    //switch
												 }    //while

				sumaPktTy += PktTy;
				sumaPktComp+= PktComp;


			if (PktTy == 3)
			{
				cout << "WYGRANA!" << endl;
				sumawygranaTy++;
			}
			else if (PktComp == 3)
			{
				cout << "PRZEGRANA :(" << endl;
				sumawygranaComp++;
			}

			PktTy = 0;
			PktComp = 0;

			wczytaniePliku(sumaWinY, sumaWinC, sumaoldtypkt, sumaoldcomppkt, nrLini, linia, sumawygranaTy, sumawygranaComp, sumaPktTy, sumaPktComp,x, y, z, b, v);// wywolanie funkcji wczytujacej plik

			sumaWinC += sumawygranaComp;
			sumaWinY += sumawygranaTy;
			sumaoldcomppkt += sumaPktComp;
			sumaoldtypkt += sumaPktTy;

			 x = "Liczba Twoich wygranych     : ";
			 y = "Liczba  wygranych Computera : ";
			 z = "Liczba twoich punktow       : ";
			 v = "Liczba punktow Computera    : ";
			 b = "==================================";

			 zapisywaniePliku(sumaWinY, sumaWinC, sumaoldtypkt, sumaoldcomppkt, x, y, z, b, v);

			break;
			} //case1
			case '2':
			return 0;
			break;
			case '3':
			{
			
				wczytaniePliku(sumaWinY, sumaWinC, sumaoldtypkt, sumaoldcomppkt, nrLini, linia, sumawygranaTy, sumawygranaComp, sumaPktTy, sumaPktComp, x, y, z, b, v);

				cout << b << endl;
				cout << x;
				cout<< sumaWinY << endl;
				cout << y;
				cout << sumaWinC << endl;
				cout << z;
				cout << sumaoldtypkt << endl;
				cout << v;
				cout << sumaoldcomppkt << endl;
				cout << b << endl;

				break;
			} //case 3
		
			} //switch wybor
			} while (wybor != 2);

			system("pause");
return 0;
}
