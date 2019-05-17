#include "fun.h"

//namespace {

	void logika(char mojRuchOld, int & PktComp, int & PktTy) {
		int mojRuch = (mojRuchOld - 48);
		string tab[3] = {
			"Kamien",			//0
			"Papier",			//1
			"Nozyce"			//2
		};
		int arr[3] = { 2,0,1 };	//warunki mojej wygranej
		int ruchKomputera = (rand() % 3) + 1;
		cout << "Twoj ruch :" << tab[mojRuch - 1] << endl;
		cout << "Computer  :" << tab[ruchKomputera - 1] << endl;
		cout << endl;

		if (mojRuch == ruchKomputera) {
			cout << "Remis :( " << endl;
			cout << endl;
		}
		else
		{
			if ((ruchKomputera - 1) == arr[mojRuch - 1])
			{
				PktTy++;
				cout << "Twoja wygrana :)" << endl;
				cout << endl;
			}

			else {
				PktComp++;
				cout << "Wygyrwa Computer :(" << endl;
				cout << endl;
			}
			cout << "Punkty Computera :" << PktComp << endl;
			cout << "Twoje Punkty     :" << PktTy << endl;
			cout << endl;

		}
	}
	void wczytaniePliku(int &sumaWinY, int &sumaWinC, int &sumaoldtypkt, int &sumaoldcomppkt, int &nrLini, string linia, int &sumawygranaTy, int &sumawygranaComp, int &sumaPktTy, int &sumaPktComp, string& x, string &y, string &z, string &b, string &v)
	{
		fstream plik;
		plik.open("statystyka_gry.txt", ios::in);
		if (plik.good() == false)
		{
			cout << "Plik nie istnieje" << endl;
			exit(0);
		}

		while (getline(plik, linia))
		{

			switch (nrLini)
			{
			case 1: b = linia; break;
			case 2: x = linia; break;
			case 3: sumaWinY = atoi(linia.c_str()); break;
			case 4: y = linia; break;
			case 5: sumaWinC = atoi(linia.c_str()); break;
			case 6: z = linia; break;
			case 7: sumaoldtypkt = atoi(linia.c_str()); break;
			case 8: v = linia; break;
			case 9: sumaoldcomppkt = atoi(linia.c_str()); break;
			case 10: b = linia; break;
			}//switch z linia
			nrLini++;
		}//while

		plik.close();


	}
	void zapisywaniePliku(int &sumaWinY, int &sumaWinC, int &sumaoldtypkt, int &sumaoldcomppkt, string x, string y, string z, string b, string v)
	{

		fstream dane;
		dane.open("statystyka_gry.txt", ios::out);
		dane << b << endl;
		dane << x << endl;
		dane << sumaWinY << endl;
		dane << y << endl;
		dane << sumaWinC << endl;
		dane << z << endl;
		dane << sumaoldtypkt << endl;
		dane << v << endl;
		dane << sumaoldcomppkt << endl;
		dane << b << endl;

		dane.close();

	}

//}//namespace