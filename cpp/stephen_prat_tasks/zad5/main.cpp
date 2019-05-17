#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

struct Car
{
	string marka;
	int year;
};

struct Car1
{
	char *marka;
	int year;
};

void zad_1();
void zad_2();
void zad_3();
double zysk(double kwotaInwest, double opp);
void zad_4();
void zad_5();
void zad_6();
void zad_7();
void zad_8();
void zad_9();
void zad_10();


int main() {

	//zad_1();
	//zad_2();
	//zad_3();
	//zad_4();
	//zad_5();
	//zad_6();
	//zad_7();
	//zad_8();
	//zad_9();
	//zad_10();



	system("pause");
	return 0;
}

void zad_1() {
	int a, b, sum = 0;
	cout << "Podaj 2 liczby: ";
	cin >> a >> b;
	for (int i = a; i <= b; ++i)
		sum += i;
	cout << "Suma wynosi: " << sum << endl;
}
void zad_2() {
	const int arSize = 101;

	array<long double, 101> factorial;

	factorial[0] = factorial[1] = (long double)1;
	for (int i = 2; i < arSize; ++i)
		factorial[i] = i * factorial[i - 1];

	for (int i = 0; i < arSize; ++i)
		cout << i << "! = " << factorial[i] << endl;
}
void zad_3() {
	int liczba, sum = 0;
	cout << "Podawaj liczby, 0 - konczy dzialanie programu" << endl;
	cin >> liczba;
	while (liczba != 0) {
		sum += liczba;
		cout << "Suma wprowadzonych liczb: " << sum << endl;
		cin >> liczba;
	}
}
double zysk(double kwotaInwest,double opp) {

	double zysk = 0;

	zysk = opp * kwotaInwest;
	kwotaInwest += zysk;

	return  kwotaInwest;
}
void zad_4() {

	static char* name[2] = {
		(char*)"Dafne",
		(char*)"Cleo"
	};

	double zyskDafne, zyskCleo,kwotaDafne,kwotaCleo;
	int year;

	cout << name[0] << " ile chcesz zainwestowac: ";
	cin >> kwotaDafne;
	cout << name[1] << " ile chcesz zainwestowac: ";
	cin >> kwotaCleo;
	cout << "Na ile lat inwestujecie ";
	cin >> year;
	
	int count = 1;
	do{
		zyskDafne = zysk(kwotaDafne,0.10);
		zyskCleo = zysk(kwotaCleo, 0.05);
		cout << "Inwestycje " << name[0] << " : " << zyskDafne<<" za "<<count<<" rok"<< endl;
		cout << "Inwestycje " << name[1] << " : " << zyskCleo <<" za "<<count<< " rok"<<endl;
		kwotaDafne = zyskDafne;
		kwotaCleo = zyskCleo;
		count++;
		year--;
	}while (year!=0);

}
void zad_5() {
	static char* msc[] = {
		(char*)"Styczniu",
		(char*)"Lutym",
		(char*)"Marcu",
		(char*)"Kwietniu",
		(char*)"Maju",
		(char*)"Czerwcu",
		(char*)"Lipcu",
		(char*)"Sierpniu",
		(char*)"Wrzesniu",
		(char*)"Pazdzierniku",
		(char*)"Listopadzie",
		(char*)"Grudniu",
	};

	vector<int> arr;
	int sum = 0;
	cout << "Podawaj miesieczna liczbe sprzedazy (w sztukach): " << endl;
	for (int i = 0; i < 12; ++i) {
		int sztuki;
		cout << "Liczba sprzedanych sztuk w " << msc[i] << ":\t";
		cin >> sztuki;
		arr.push_back(sztuki);
		sum += arr[i];
	}
	cout << "Laczna sprzedaz lacznie wynosi: " << sum << " sztuk" << endl;
}
void zad_6() {
	static char* msc[] = {
		(char*)"Styczniu",
		(char*)"Lutym",
		(char*)"Marcu",
		(char*)"Kwietniu",
		(char*)"Maju",
		(char*)"Czerwcu",
		(char*)"Lipcu",
		(char*)"Sierpniu",
		(char*)"Wrzesniu",
		(char*)"Pazdzierniku",
		(char*)"Listopadzie",
		(char*)"Grudniu",
	};

	int arr[6][6];
	int sum = 0,sztuki;
	cout << "Podawaj miesieczna liczbe sprzedazy (w sztukach): " << endl;
	for (int i = 0; i <3; ++i) {
		for (int j = 0; j < 12; j++) {
			cout << "Liczba sprzedanych sztuk w " << msc[j] << " w " << i + 1 << " roku" << ":\t";
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	cout << "Laczna sprzedaz lacznie wynosi: " << sum << " sztuk" << endl;
}
void zad_7(){
	int ile;
	cout << "Ile aut chcesz skatalogowac: ";
	cin >> ile;

	int tmp = ile;
	Car* car = new Car[ile];
	int i = 0;
	while (ile) {
		cout << "Samochod #" << i+1 << ":" << endl;
		cin.ignore();
		cout << "Prosze podac marke: ";
		getline(cin, car[i].marka);
		cout << "Rok produkcji: ";
		cin >> car[i].year;
		ile--;
		i++;
	}

	for (int j = 0; j < tmp; ++j) {
		cout << car[j].year << " " << car[j].marka << endl;
	}
}
void zad_8() {
	const int arrSize = 15;
	char name[arrSize];
	int count = 0;

	cout << "Podawaj slowa (kiedy skonczysz, napisz \"gotowe\") " << endl;
	cin >> name;
	while (strcmp(name,"gotowe")) {
		count++;
		cin >> name;
	}
	cout << "Podano " << count << " slow" << endl;
}
void zad_9() {
	int ile;
	cout << "Ile aut chcesz skatalogowac: ";
	cin >> ile;

	int tmp = ile;
	Car1* car = new Car1[ile];
	int i = 0;
	char temp[128];
	while (ile) {
		cout << "Samochod #" << i + 1 << ":" << endl;
		cin.ignore();

		cout << "Prosze podac marke: ";
		cin.getline(temp,128);
		size_t lenght = strlen(temp);
		car[i].marka = new char[lenght + 1];//alokacja pamieci dla marki
		strcpy(car[i].marka, temp);

		cout << "Rok produkcji: ";
		cin >> car[i].year;

		ile--;
		i++;
	}

	for (int j = 0; j < tmp; ++j) {
		cout << car[j].year << " " << car[j].marka << endl;
	}
}
void zad_10() {
	int ile;
	cout << "Podaj liczbe wierszy: ";
	cin >> ile;

	for (int i = 0; i < ile; i++) {
		for (int j = 0; j < ile; j++) {
			if (j < (ile - i - 1))
				cout << ". ";
			else
				cout << "* ";
		}
		cout << endl;
	}
}
