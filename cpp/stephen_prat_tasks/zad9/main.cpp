#include <iostream>
#include <cstring>
#include <string>
#include "golf.h"
#include "salesFunc.h"

using std::cin;
using std::cout;
using std::endl;

struct chaf{
    char dross[20];
    int slag;
};

void zad_2();
void strcount(const std::string input);

void zad_3();

void zad_4();
double min(const double* arr,int n);
double max(const double* arr,int n);
double avg(const double* arr,int n);


int main() {
   /* golf ann, brat, jack, lara;
    setgolf(ann, "Ann BirdFree", 10);
    setgolf(brat, "Brat FreeN", 20);
    setgolf(jack, "Jack StopGlower", 30);
    setgolf(lara, "Lara Croft", 40);

    cout << endl;

    showgolf(ann);
    showgolf(brat);
    showgolf(jack);
    showgolf(lara);

    cout << endl;

    cout << "Po zmianie handicapu" << endl;
    handicap(ann, 1);
    handicap(brat, 2);
    handicap(jack, 3);
    handicap(lara, 4);

    cout << endl;

    showgolf(ann);
    showgolf(brat);
    showgolf(jack);
    showgolf(lara);

    cout << "Ilu jest graczy: ";
    int player;
    cin >> player;
    int temp = player;
    int temp2 = player;
    int temp3 = player;

    auto *arrPlayer = new golf[player];

    int i = 0;
    while (player--) {
        setgolf(arrPlayer[i]);
        i++;
    }
    i = 0;
    while (temp--) {
        showgolf(arrPlayer[i]);
        i++;
    }
    cout << endl;
    i = 0;
    cout << "Po zmianie handicapu" << endl << endl;
    while (temp2--) {
        handicap(arrPlayer[i], i);
        i++;
    }

    i = 0;
    while (temp3--) {
        showgolf(arrPlayer[i]);
        i++;
    }
*/
   //zad_2();
    // zad_3();
    zad_4();

    return 0;
}

void setgolf(golf &g, const char *name, int hc) {
    strcpy(g.fullname, name);
    g.handicap = hc;

}
void setgolf(golf &g) {
    cout << "Imie gracza: ";
    cin.ignore();
    char ch;
    cin.get(g.fullname, 40); //Konczy wczytywanie jesli wczytano 40 znakow lub napotkano '\n'
    while (!cin) {       //If wprowadzimy pusty wiersz cin przyjmie wartosc falszu czyli w whilu bedzie true i bedziemy wprowadzac doputy nie podamy czegos innego niz '\n'
        cout << "Wprowadziles pusty wiersz, sprobuj ponownie" << endl;
        cin.clear();
        cin.ignore();
        cin.get(g.fullname, 40, '\n');
    }
    cout << "Wartosc handicapu: ";
    cin >> g.handicap;
}
void handicap(golf &g, int hc) {
    g.handicap = hc;
}
void showgolf(const golf &g) {
    cout << "Name: " << g.fullname << ", Handicap: " << g.handicap << endl;
}

void zad_2() {
    std::string input;
    cout<<"Wprowadz wiersz: ";
    while(getline(cin,input) && input!="0"){
        strcount(input);
        cout<<"Wprowadz nastepny wiersz lub 0 aby wyjsc"<<endl;

    }

};
void strcount(const std::string input){
    static int total=0;
    int count=0;

    cout<<"\""<<input<<"\" zawiera ";
    int i=0;
    while(input[i++])
        count++;
    total+=count;
    cout<<count<<" znakow\n";
    cout<<"Lacznie "<<total<<" znakow"<<endl;

}

void zad_3(){
    char buff[50];
    const int arrSize=2;

    auto *arrOne=new (buff)chaf[arrSize];

        for(int i=0;i<arrSize;++i){
            cout<<"Podaj wiersz: ";
            cin.getline(arrOne[i].dross,20);
            arrOne[i].slag=i+i*(i+3)+10;
        }
        for(int i=0; i<arrSize;++i)
            cout<<"Name: "<<arrOne[i].dross<<", value: "<<arrOne[i].slag<<endl;
         delete[] arrOne;

         cout<<"Podaj liczbe osob: ";
         int o;
         cin>>o;
         auto *Buff=new char[o];
         auto *arrBuff=new (Buff) chaf[o];
    for(int i=0;i<o;++i){
        cout<<"Podaj wiersz: ";
        cin.ignore();
        cin.getline(arrBuff[i].dross,20);
        arrBuff[i].slag=i+i*(i+3)+10;
    }
    cout<<"Alokacja dynamiczna, rozmiar buffora taki sam jak rozmiar tablicy"<<endl;
    for(int i=0; i<o;++i)
        cout<<"Name: "<<arrOne[i].dross<<", value: "<<arrOne[i].slag<<endl;
    delete[] arrBuff;
}

void zad_4(){

    SALES::Sales ob1, ob2;
    double arr[SALES::QUARTERS] = {8.2, 2.7, 4.2, 1.9};

    setSales(ob1,arr,SALES::QUARTERS);
    showSales(ob1);

    setSales(ob2);
    showSales(ob2);

}
void setSales(SALES::Sales & s,const double arr[],int n){
    for(int i=0;i<SALES::QUARTERS;++i)
        s.sales[i]=arr[i];

    s.min=min(s.sales,SALES::QUARTERS);
    s.average=avg(s.sales,SALES::QUARTERS);
    s.max=max(s.sales,SALES::QUARTERS);

    for(int i=0;i<SALES::QUARTERS;++i)
        s.sales[i]=0;

}
void showSales(const SALES::Sales & s){
    cout<<"Adres struktury ob1: "<<&s<<endl;
    cout<<"Wartosc min: "<<s.min<<endl;
    cout<<"Wartosc avg: "<<s.average<<endl;
    cout<<"Wartosc max: "<<s.max<<endl;

}

void setSales(SALES::Sales & s){
    for(int i=0;i<SALES::QUARTERS;i++){
        cout<<"Podaj wartosc nr "<<i+1<<": ";
        while(!bool(cin>>s.sales[i])){
            cout<<"Podana wartosc nie jest liczba, sprobuj ponownie: ";
            cin.clear();
            cin.sync();
            cin.ignore();
        }
    };

    s.min=min(s.sales,SALES::QUARTERS);
    s.average=avg(s.sales,SALES::QUARTERS);
    s.max=max(s.sales,SALES::QUARTERS);

}
double min(const double* arr,int n){
    double min=arr[0];
    for(int i=1;i<SALES::QUARTERS;i++){
        if(arr[i]<min)
            min=arr[i];
    }
    return min;
};

double max(const double* arr,int n){
    double max=arr[0];
    for(int i=1;i<SALES::QUARTERS;i++){
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
};

double avg(const double* arr,int n){
    double avg=0;
    for(int i=0;i<SALES::QUARTERS;i++){
    avg+=arr[i];
    }
    return avg/SALES::QUARTERS;
};

