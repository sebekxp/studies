#include <iostream>
#include <cctype>
#include <array>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const int strsize = 20;
struct zpdw {
	char imie[strsize];
	char stanowisko[strsize];
	char pseudozpwd[strsize];
	int preferencje;
};

struct Sponsorzy
{
	string name;
	double kwota;
};

void zad_1();
void zad_2();
void zad_3();
void zad_4();
void zad_5();
void zad_6();
void zad_7();
void zad_8();
void zad_9();

int main() {

	srand(time(NULL));

	//zad_1();
	//zad_2();
	//zad_3();
	//zad_4();
	//zad_5();
	//zad_6();
	//zad_7();
	//zad_8();
	//zad_9();

	system("pause");
	return 0;
}
void zad_1() {

	cout << "Wczytaj dane z klawiatury, @ - konczy wpisywanie" << endl;
	char ch;

	while (cin.get(ch) && ch != '@')
		if (isalpha(ch))
			putchar(toupper(ch));
}
void zad_2() {

	array<double, 10> tab;
	double sum=0;
	int i;

	for ( i = 0; i < 10; i++) {
		tab[i] = 0 + rand() % 11;
		cout << tab[i] << " ";
		sum += tab[i];
	}
	cout << endl;

	double sr = sum / i;
	cout <<"Srednia = "<< sr << endl;
	for (int j = 0; j < 10; j++) {
		if (tab[j] > sr)
			cout << tab[j] << " ";
	}
	cout << endl;

}
void zad_3() {
	char ch;
	do {
		cout << " r) roslinozerca			p) pianista" << endl;
		cout << " d) drzewo			        g) gra" << endl;

		cout << "Prosze podac litere r, p, t lub g: ";
		cin >> ch;
		switch (ch) {
		case 'p':	cout << "Pianista to bardzo dobry film" << endl;	break;
		case 'r':	cout << "Dinozaury to roslinozercy" << endl;		break;
		case 'g':	cout << "Gry sa bardzo fajne" << endl;				break;
		case 'd':	cout << "Klon jest drzewem" << endl;				break;

		}
	} while (ch != 'p' && ch != 'r' && ch != 'd' && ch != 'g');
}
void zad_4() {
	int ile;
	cout << "Ilu programistow jest w zakonie: ";
	cin >> ile;

	zpdw* arr = new zpdw[ile];

	cin.ignore();

	for (int i = 0; i < ile; ++i) {

		cout << "Programista nr " << i + 1 << endl;
		cout << "Imie: ";
		cin.getline(arr[i].imie, strsize);
		cout << "Stanowisko: ";
		cin.getline(arr[i].stanowisko, strsize);
		cout << "Pseudonim w zakonie: ";
		cin.getline(arr[i].pseudozpwd, strsize);
		arr[i].preferencje = i%3;
		cout << endl;
	}
	char wyb;
	do {
		cout << "Zakon programistow dobrej woli" << endl;
		cout << "a) Lista wg imion			b) Lista wg stanowisk " << endl;
		cout << "c) Lista wg pseudinimow			d) Lista wg preferencji " << endl;
		cout << "q) Koniec" << endl;

		cin >> wyb;

		switch (wyb)
		{
		case 'a': {
			cout << "Lista wg imion" << endl;
			for (int i = 0; i < ile; i++)
				cout << arr[i].imie << endl;
			break;
		}
		case 'b': {
			cout << "Lista wg stanowisk" << endl;
			for (int i = 0; i < ile; i++)
				cout << arr[i].stanowisko << endl;
			break;
		}
		case 'c': {
			cout << "Lista wg pseudinimow" << endl;
			for (int i = 0; i < ile; i++)
				cout << arr[i].pseudozpwd << endl;
			break;
		}
		case 'd': {
			cout << "Lista wg preferencji" << endl;
			for (int i = 0; i < ile; i++) {
				if (arr[i].preferencje == 0)
					cout << arr[i].imie << endl;
				else if (arr[i].preferencje == 1)
					cout << arr[i].stanowisko << endl;
				else if (arr[i].preferencje == 2)
					cout << arr[i].pseudozpwd << endl;
			}
			break;
		}
		default:
			cout << "Brak odpowiedniej opcji :(" << endl;
			break;
		}

	} while (wyb != 'q');
	cout << "Do zobaczenia!" << endl;
	delete[] arr;
}
void zad_5() {
	int twarp,temp;

	cout << "Ile twarpow zarabiasz: ";
	while (cin>>twarp && twarp >= 0) {

		if ( twarp <= 5000 )
			cout << "Naleznosc podatkowa " << twarp * 0.0 << " twarpow" << endl;
		else if( twarp>5000 && twarp<=15000 )
			cout << "Naleznosc podatkowa " << twarp * 0.10 << " twarpow" << endl;
		else if( twarp>15000 && twarp<=35000 )
			cout << "Naleznosc podatkowa " << twarp * 0.15 << " twarpow" << endl;
		else if (twarp > 35000) {
			temp = twarp - 35000;
			cout << "Naleznosc podatkowa " << 5000*0.0+10000*0.1+20000*0.15+temp*0.2<< " twarpow" << endl;
		}
		cout << "Ile twarpow zarabiasz: ";
	}

}
void zad_6() {
	cout << "TOWARZYSTWO NA RZECZ ZACHOWANIA DOBRYCH WPLYWOW" << endl;
	cout << "Liczba wplacajacych: ";
	int ile;
	cin >> ile;

	Sponsorzy* arr = new Sponsorzy[ile];

	cin.ignore();
	for (int i = 0; i < ile; i++) {
		cout << "Imie: ";
		getline(cin, arr[i].name);

		int size = arr[i].name.length();
		char lastchar = arr[i].name[size - 1];//lastcharacet if a- female

		if (lastchar == 'a')
			cout << "Jaka kwote Pani wplaca: ";
		else
			cout << "Jaka kwote Pan wplaca: ";

		cin >> arr[i].kwota;
		cin.ignore();
	}

	cout << "Nasi wspaniali sponsorzy" << endl;
	for (int i = 0; i < ile; i++) {
		if (arr[i].kwota >= 10000) {
			if (isblank(arr[i].name[0]))
				cout <<"Imie: "<<"Brak"<< " - " << arr[i].kwota << endl;
			else
				cout <<"Imie: "<< arr[i].name << " - " << arr[i].kwota << endl;
		}
	}
	cout << endl;
	cout << "Nasi sponsorzy" << endl;
	for (int i = 0; i < ile; i++) {
		if (arr[i].kwota < 10000) {
			if (isblank(arr[i].name[0]))
				cout <<"Imie: "<< "Brak" << " - " << arr[i].kwota << endl;
			else
				cout <<"Imie: "<< arr[i].name << " - " << arr[i].kwota << endl;
		}
	}
}
void zad_7() {
	/* Wczytano znaki az do napotkania znaku q, pierwszy znak ustawionojako spacje zeby spelnic warunki zadania, 
	i ostatni znak ustawiono na koniec tablicya, przejechano po rablicy jezeli wczesniejszy znak byl spacja to
	sprawdzalo sie nastepny znak czy litera jesli tak to wrzucalo sie go do odpowiedniej kategorii (samoglowska,spolgloska) lub inne*/
	cout << "Podawaj slowa (pojedyncze q konczy)" << endl;
	
	char ch;
	int other = 0;
	int samogloski = 0;
	int spolgloski = 0;
	int whitesigns = 0;
	vector<char> tab;

	tab.push_back(' ');
	while (cin.get(ch) && ch != 'q') {
		tab.push_back(ch);
	}
	tab.push_back('\0');

	for (int i = 1; tab[i] != '\0'; i++) {
		if (tab[i-1] == ' ' || tab[i - 1] == '\n') {
			if (isalpha(tab[i])) {
				switch (tab[i]) {
				case 'A':
				case 'a':
				case 'E':
				case 'e':
				case 'Y':
				case 'y':
				case 'I':
				case 'i':
				case 'O':
				case 'o':
				case 'U':
				case 'u':
					samogloski++;
					break;
				default:
					spolgloski++;
					break;
				}
			}
			else
				other++;
		}
	}
	cout << spolgloski<< " slow zaczyna sie od spolglosek." << endl;
	cout << samogloski << " slow zaczyna sie od samoglosek." << endl;
	cout << other << " slow nie zalicza sie do zadnej z tych kategorii." << endl;

}
void zad_8() {
	const int SIZE = 60;

	char fileName[SIZE];
	char str[SIZE];
	ifstream inFile;

	/* Jezeli trzeba cos zapisac
	ofstream outFile;
	outFile.open("text.txt");
	cin.getline(str, SIZE);
	outFile << str << endl;
	outFile.close();
	*/

	cout << "Podaj nazwe pliku z danymi: ";
	cin.getline(fileName, SIZE);

	//otwieranie pliku

	inFile.open(fileName);
	if (!inFile.is_open()){
		cout << "Otwieranie pliku nie powiodlo sie :(" << endl;
		cout << "Program zostanie zakonczony :(" << endl;
		exit(EXIT_FAILURE);
		}

		char ch;
		int count = 0;

		while (inFile>>ch && inFile.good()) {
			count++;
		}
		if (inFile.eof())
			cout << "Koniec pliku" << endl;
		else if (inFile.fail())
			cout << "Wczytywanie danych przerwane - blad" << endl;
		else
			cout << "Wczytywanie danych przerwane, przyczyna nieznana" << endl;
		if (count == 0)
			cout << "Nie przetworzono zadnych danych" << endl;
		else {
			cout << "Wczytanych znakow: " << count << endl;
		}
		inFile.close();
}
void zad_9() {
	const int SIZE = 60;

	char fileName[SIZE];
	char str[SIZE];
	ifstream inFile;
	ofstream outFile;
	outFile.open("text.txt");

	cout << "TOWARZYSTWO NA RZECZ ZACHOWANIA DOBRYCH WPLYWOW" << endl;
	cout << "Liczba wplacajacych: ";
	int ile;
	cin >> ile;

	outFile << ile << endl;

	Sponsorzy* arr = new Sponsorzy[ile];

	cin.ignore();
	for (int i = 0; i < ile; i++) {
		cout << "Imie: ";
		getline(cin, arr[i].name);
		outFile << arr[i].name << endl;

		int size = arr[i].name.length();
		char lastchar = arr[i].name[size - 1];//lastcharacet if a- female

		if (lastchar == 'a')
			cout << "Jaka kwote Pani wplaca: ";
		else
			cout << "Jaka kwote Pan wplaca: ";

		cin >> arr[i].kwota;
		outFile << arr[i].kwota << endl;

		cin.ignore();
	}

	cout << "Wprowadz nazwe pliku: ";
	
	cin.getline(fileName, SIZE);

	//otwieranie pliku

	inFile.open(fileName);
	if (!inFile.is_open()) {
		cout << "Otwieranie pliku nie powiodlo sie :(" << endl;
		cout << "Program zostanie zakonczony :(" << endl;
		exit(EXIT_FAILURE);
	}
	char ch[SIZE];
	while (inFile.getline(ch,SIZE) && inFile.good()) {
		cout << ch << endl;
	}
	
}