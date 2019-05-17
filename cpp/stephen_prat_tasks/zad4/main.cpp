#include <iostream>
#include <string>
#include <array>

struct Batonik {
	std::string marka;
	double waga;
	int liczbaKalori;
};

struct Pizza{
	std::string name;
	double œrednica;
	int waga;
};

void zadanie_1();
void zadanie_2();
void zadanie_3();
void zadanie_4();
void zadanie_5();
void zadanie_6();
void zadanie_7();
void zadanie_8();
void zadanie_9();
void zadanie_10();




int main() {

	//zadanie_1();
	//zadanie_2();
	//zadanie_3();
	//zadanie_4();
	//zadanie_5();
	//zadanie_6();
	//zadanie_7();
	//zadanie_8();
	//zadanie_9();
	//zadanie_10();

	system("pause");
	return 0;
}


void zadanie_1() {
	using namespace std;
	string name, st;
	int obj, obj1;

	cout << "Jak masz na imie: ";
	getline(cin, name);
	cout << "Jak sie nazywasz: ";
	getline(cin, st);
	cout << "Na jaka ocene zaslugujesz: ";
	cin >> obj1;
	cout << "Ile masz lat: ";
	cin >> obj;

	cout << "Nazwisko: " << st << ", " << name << endl;
	cout << "Ocena: " << obj1-1 << endl;
	cout << "Wiek: " << obj << endl;

}
void zadanie_2() {
	using namespace std;
	string name, dessert;

	cout << "Podaj swoje imie: ";
	getline(cin, name);
	cout << "Podaj swoj ulubiony deser: ";
	getline(cin, dessert);
	cout << "Mam dla Ciebie " << dessert << ", " << name << endl;


}
void zadanie_3() {
	using namespace std;
	char name[20], surname[20], sumstr[50];

	cout << "Podaj swoje imie: ";
	cin.getline(name, 20);


	cout << "Podaj swoje nazwisko: ";
	cin.getline(surname,20);

	strcpy(sumstr, name);
	strcat(sumstr, ",");	
	strcat(sumstr," ");
	strcat(sumstr, surname);//strcat do³¹cza na koniec tablicy dlatego takie uzycie

	cout << "Oto informacje zestawione w jeden napis: " << sumstr << endl;

}
void zadanie_4() {
	using namespace std;
	string name, surname, sumstr;

	cout << "Podaj swoje imie: ";
	getline(cin, name);

	cout << "Podaj swoje nazwisko: ";
	getline(cin, surname);

	sumstr = name + ',' + ' ' + surname;
	cout <<"Oto informacje zestawione w jeden napis: "<< sumstr << endl;
}
void zadanie_5() {
	using namespace std;

	Batonik snack = {
		"Mocha Munch",
		2.3,
		350
	};
	cout << "Marka: " << snack.marka << endl;
	cout << "Waga: " << snack.waga << endl;
	cout << "Liczba kalori: " << snack.liczbaKalori << endl;
}
void zadanie_6() {
	using namespace std;
	Batonik snack[3] = {
		{ "Mocha Munch", 2.3, 350 },
		{ "Sneakers", 1.5, 550 },
		{ "Twix", 4.3, 1250 },
	};

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " Batonik dane techniczne" << endl;
		cout << "Marka: " << snack[i].marka << endl;
		cout << "Waga: " << snack[i].waga << endl;
		cout << "Liczba kalori: " << snack[i].liczbaKalori << endl;
		cout << endl;

	}
}
void zadanie_7() {
	using namespace std;
	Pizza pica;
	
	cout << "Podaj nazwe pizzy: ";
	getline(cin, pica.name);
	cout << "Podaj srednice pizzy: ";
	cin >> pica.œrednica;
	cout << "Podaj wage pizzy: ";
	cin >> pica.waga;

	cout << "=====================\n";
	cout << "Nazwa: " << pica.name << endl;
	cout << "Srednica: " << pica.œrednica << endl;
	cout << "Waga: " << pica.waga << endl;
	cout << "=====================\n";
}
void zadanie_8() {
	using namespace std;

	Pizza *pica = new Pizza;

	cout << "Podaj srednice pizzy: ";
	cin >> pica->œrednica;
	cin.ignore();
	cout << "Podaj nazwe pizzy: ";
	getline(cin, pica->name);
	cout << "Podaj wage pizzy: ";
	cin >> pica->waga;

	cout << "=====================\n";
	cout << "Srednica: " << pica->œrednica << endl;
	cout << "Nazwa: " << pica->name << endl;
	cout << "Waga: " << pica->waga << endl;
	cout << "=====================\n";
}
void zadanie_9() {
	using namespace std;
	
	int n;
	cout << "Ile batonikow: ";
	cin >> n;

	Batonik *snk = new Batonik[n];//to nie wskaznik tylko tablica
	
	for (int j = 0; j < n; j++) {
		cout << "Batonik nr " << j + 1 << endl;
		cin.ignore();
		cout << "Podaj marke batonika: ";
		getline(cin, snk[j].marka);
		cout << "Podaj wage batonika: ";
		cin >> snk[j].waga;
		cout << "Podaj liczbe kalori batonika: ";
		cin >> snk[j].liczbaKalori;
		cout << endl;
	}


	for (int i = 0; i < n; i++) {
		cout << i + 1 << " Batonik dane techniczne" << endl;
		cout << "Marka: " << snk[i].marka << endl;
		cout << "Waga: " << snk[i].waga << endl;
		cout << "Liczba kalori: " << snk[i].liczbaKalori << endl;
		cout << endl;

	}
}
void zadanie_10() {
	using namespace std;
	array<double, 3> time;

	for (int i = 0; i < 3; i++) {
		cout << "Podaj " << i + 1 << " czas na 100 metrow: ";
		cin >> time[i];
	}
	for (int j = 0; j < 3; j++)
		cout << j + 1 << " czas wynosi: " << time[j] << endl;

	cout << "Twoja srednia wynosi: " << double(time[0] + time[1] + time[2]) / 3 << endl;
}



