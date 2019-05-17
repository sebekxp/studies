#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

struct pudlo {
	char producent[40];
	string name;
	float wysokosc;
	float dlugosc;
	float szerokosc;
	float objetosc;
};
struct POD {
	double arr[4];
	const int size = 4;
};

const int SLEN = 30;
struct student{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
double sr(double a, double b);
void zad_1();
void showArr(const int* arr, int size);
double sredni(int *arr, int size);
int fillArray(int *arr, const int size);
void zad_2();

void showStruct(const pudlo obj);
void objetosc(pudlo* obj, int x);
void zad_3();

int findmax(const int * arr, int max);
double probability(int max,int b);
void zad_4();

long long factorial(long long x);
void zad_5();

int fill_array(double* arr, const int SIZE);
void show_array(const double* arr, const int size);
void reverse_array(double* arr, const int size);
void zad_6();

double* fill(double* begin, const double* end);
void show(double*begin, const double* end);
void revalue(double r, double* begin, double* end);
void zad_7();

void fillS(const char** seasons, double *arr, const int size);
void showS(const char** seasons, double *arr, const int size);
void showB(const char** seasons, POD* obj);
void fillB(const char** seasons, POD* obj);
void zad_8();

void display1(student pa);
void display3(const student *pa, int n);
int getinfo(student* pa, const int size);
void display2(const student *pa);
void zad_9();

double add(double x, double y);
double multi(double x, double y);
double diff(double x, double y);
double div(double x, double y);
typedef double (*funcPtr)(double x, double y);
double callculate(double x, double y, funcPtr add);
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
	zad_10();

	system("pause");
	return 0;
}
double sr(double a, double b) {
	return 2.0*a*b / (a + b);
}
void zad_1() {

	double a, b,sre;
	cout << "Podaj dwie liczby rozne od zera: ";
	cin >> a >> b;
	
	while (a != 0 && b != 0) {
		sre = sr(a, b);
		cout << "Srednia harmoniczna: " << sre << endl;
		cout << "Znow wczytaj dwie liczby :)" << endl;
		cin >> a >> b;
	}
	cout << "Wprowadziles 0 dlatego program przesta³ dzialac" << endl;
}

int fillArray(int *arr,const int size) {
	int i = 0,wynik;
	for (i; i < size; i++) {
		cout << "Wynik nr " << i + 1 << " :";
		cin >> wynik;

		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bledne dane, wprowadzanie danych przerwane :(" << endl;
			break;
		}
		else if (wynik < 0)
			break;
		
		arr[i] = wynik;
	}
	return i;
}
double sredni(int *arr,int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum / size;
}
void showArr(const int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout << i + 1 << " :" << arr[i] << endl;
}
void zad_2() {
	const int SIZE = 10;
	cout << "Podaj do 10 wynikow golfowych, liczba ujemna konczy wprowadzanie" << endl;
	int arr[SIZE];
	int size=fillArray(arr,SIZE);
	if (size <= 0) {
		cout << "Nie wczytano zadnych elementow :(" << endl;
	}
	else {
		double sr = sredni(arr, size);
		cout << "Sredni wynik: " << sr << endl;
		cout << endl;
		cout << "Your Array" << endl;
		showArr(arr, size);
	}

	void zad_3();
}

void showStruct(const pudlo obj) {
	cout << "Producent: "<<obj.producent << endl;
	cout << "Name: " << obj.name << endl;
	cout << "Dlugosc: " << obj.dlugosc << endl;
	cout << "Wysokosc: " << obj.wysokosc << endl;
	cout << "Szerokosc: " << obj.szerokosc << endl;
	cout << "Objetosc: " << obj.objetosc << endl;
}
void objetosc(pudlo* obj, int x) {
	obj->objetosc = x * x * x;
}
void zad_3() {

	pudlo obj;
	cout << "Podaj nazwe: ";
	cin.getline(obj.producent, 40);

	cout << "Podaj kolejna nazwe: ";
	getline(cin, obj.name);

	float a, b, c,d;
	cout << "Podaj 4 liczby: ";
	cin >> a >> b >> c >> d;

	obj.dlugosc = a;
	obj.wysokosc = c;
	obj.objetosc = b;
	obj.szerokosc = d;

	showStruct(obj);
	cout << endl;
	cout << endl;
	cout << "After change" << endl;
	objetosc(&obj, 2);
	showStruct(obj);
}

double probability(int max,int b) {
	double r = 1.0;
	int i, n;
	for(i=max,n=b;n>0;i--,n--)
		r = r * b / max;
	return r;
}
int findmax(const int * arr, int max) {
	int w = arr[0];
	for (int i = 0; i < max; i++) {
		if (arr[i] > w)
			w = arr[i];
	}
	return w;
}
void zad_4() {

	const int MAX = 5;
	int arr[MAX];
	int wyb;

	cout << "Podaj 4 liczby wieksze od 1 :" << endl;
	for (int i = 0; i < MAX - 1; i++) {
		cout << "Liczba nr" << i + 1<<": ";
		cin >> arr[i];
	}
	int max = findmax(arr, MAX);
	double first = probability(MAX, max);

	cout << "Podaj 1 liczbe wieksza od 1:";
	cin >> arr[MAX - 1];
	double second = probability(MAX, arr[MAX-1]);

	cout << first << endl;
	cout << second << endl;
	cout << first*second << endl;


}

long long factorial(long long x) {

	if (x == 0)
		return 1;
	else
		return x * factorial(x - 1);
}
void zad_5() {

	long long  fact;
	cout << "Wyliczanie silni" << endl;
	cout << "Podaj liczbe:";
	cin >> fact;
	while (true) {
		long long x=factorial(fact);
		cout << "Silna " << fact << " wynosi: " << x << endl;
		cout << "Podaj liczbe:";
		cin >> fact;

		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bledne dane, wprowadzanie danych przerwane" << endl;
			break;
		}
	}
}

int fill_array(double* arr, const int SIZE) {
	
	double x;
	int i = 0;
	for (i ; i < SIZE; i++) {
		cout << "Podaj liczbe nr " << i + 1 << " : ";
		cin >> x;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bledne dane :(" << endl;
			break;
		}
		arr[i] = x;
	}

	return i;
}
void show_array(const double* arr, const int size) {
	for (int i = 0; i < size; i++)
		cout <<"Wartosc nr "<<i+1<<": "<< arr[i] << endl;
}
void reverse_array(double* arr, const int size) {

	for (int i = 0; i != size/2; i++) {
		swap(arr[i], arr[size - 1 - i]);
	}
}
void zad_6() {

	const int SIZE = 10;
	double arr[SIZE];

	int size=fill_array(arr, SIZE);
	show_array(arr, size);
	reverse_array(arr, size);
	cout << "After swap" << endl;
	show_array(arr, size);

}

double* fill(double* begin, const double* end) {
	double temp;
	double* ptr=NULL;
	int i = 0;
	for (ptr = begin,i; ptr != end; ptr++,i++) {
		cout << "Podaj wartosc nr " << i + 1 << ": ";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bledne dane :(" << endl;
			break;
		}
		else if (temp < 0)
			break;
		*ptr = temp;
	}
	return ptr;
}
void show(double*begin, const double* end) {
	int i ;
	for (double* ptr = begin,i=1; ptr != end; ptr++,i++) {
		cout << "Nieruchomosci nr " << i<<": ";
		cout << *ptr << endl;
	}
}
void revalue(double r, double* begin, double* end) {
	for (double* ptr = begin; ptr != end; ptr++)
		*ptr = *ptr * r;
}
void zad_7() {

	const int Max = 5;
	double prop[Max];

	double* n= fill(prop, prop + Max);
	show(prop, n);
	cout << "Podaj czynnik zmiany wartosci: ";
	double factor;
	while (!(cin >> factor)) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Niepoprawna wartosc, podaj liczbe: ";
	}
	revalue(factor, prop, n);
	show(prop, n);

}

void fillS(const char** seasons, double *arr,const int size) {
	for (int i = 0; i < size; i++) {
		cout << "Podaj wydatki za okres " << seasons[i] << ": ";
		cin >> arr[i];
	}
}
void showS(const char** seasons, double *arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << "Wydatki za okres " <<seasons[i]<< ": " << arr[i] << endl;
	}
}
void fillB(const char** seasons, POD* obj) {
	for (int i = 0; i < obj->size; i++) {
		cout << "Podaj wydatki za okres " << seasons[i] << ": ";
		cin >> obj->arr[i];
	}
}
void showB(const char** seasons,POD* obj) {
	for (int i = 0; i < obj->size; i++) {
		cout << "Wydatki za okres " << seasons[i] << ": " << obj->arr[i] << endl;
	}
}
void zad_8() {
	const int size = 4;
	const char* seasons[] = { "Wiosna",
		"Lato" ,
		"Jesien",
		"Zima" };
	double podatki[size];

	//fillS(seasons, podatki, size);
	//cout << endl;
	//showS(seasons, podatki, size);

	POD pd;
	fillB(seasons, &pd);
	cout << endl;
	showB(seasons, &pd);
}

int getinfo(student* pa, const int size) {
	int i = 0;
	for (i ; i < size; i++) {
		cout << "Imie studenta nr " << i + 1 << ": ";
		cin.getline(pa[i].fullname, SLEN);
		if (strlen(pa[i].fullname) == 0)
			break;
		cout << "Hobby studenta nr " << i + 1 << ": ";
		cin.getline(pa[i].hobby, SLEN);
		pa[i].ooplevel = i +10*i;
	}

	return i;
}
void display1(student pa) {

	cout << "Imie: " << pa.fullname << endl;
	cout << "Hobby: " << pa.hobby << endl;
	cout << "Ooplevel: " << pa.ooplevel << endl;
 }
void display2(const student *pa) {
	cout << "Imie: " << pa->fullname << endl;
	cout << "Hobby: " << pa->hobby << endl;
	cout << "Ooplevel: " << pa->ooplevel << endl;
}
void display3(const student *pa, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Imie: " << pa[i].fullname << endl;
		cout << "Hobby: " << pa[i].hobby << endl;
		cout << "Ooplevel: " << pa[i].ooplevel << endl;
	}
 }
void zad_9() {

	cout << "Liczba studentow: ";
	int lstudent;
	cin >> lstudent;
	while (cin.get() != '\n')
		continue;

	student* pa = new student[lstudent];
	int entered = getinfo(pa, lstudent);
	for (int i = 0; i < entered; i++) {
		cout << "Display 1" << endl;
		display1(pa[i]);
		cout << endl;
		cout << "Display 2" << endl;
		display2(&pa[i]);
		cout << endl;
	}
	cout << "Display 3" << endl;
	display3(pa, entered);
	delete[] pa;
	cout << "Gotowe" << endl;
}

double add(double x, double y) {
	return x + y;
}
double callculate(double x, double y, funcPtr fun) {
	return fun(x, y);
}
double multi(double x, double y) {
	return x * y;
}
double diff(double x, double y) {
	return x - y;
}
double div(double x, double y) {
	return x / y;
}
void zad_10() {
	double q = callculate(2.5, 10.4, add);
	cout <<"Suma: "<< q << endl;
	double w = callculate(2, 2, multi);
	cout << "Multiplication: " << w << endl;
	double e = callculate(8, 2, diff);
	cout << "Difference: " << e << endl;
	double r = callculate(100, 2, div);
	cout << "Difference: " << r << endl << endl;

	funcPtr arr[4] = { add,multi,diff,div };

	for (int i = 0; i < 4; i++) {
		double w = callculate(8, 2, arr[i]);
		cout << w << endl;
	}
}
