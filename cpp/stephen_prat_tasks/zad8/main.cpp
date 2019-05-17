#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

struct Batonik {
    char prodc[50];
    double waga;
    int kcal;
};

struct Stringy {
    char* str;
    int ct;
};

struct debts{
    char name[50];
    double amount;
};
void zad_1();
int showStr(char* str, int ile = 0);

void zad_2();
void showandSetStruct(Batonik & ptr,  const char* str = "Milenium Munch", double waga = 2.85, int kcal = 350);

void zad_3();
void toUp(string & str);

void  zad_4();
void set(Stringy & obj, char* test = {"Default parameters"});
void show(const Stringy  & obj, int ile=1);
void show(const char* str={"It's work"}, int ile=1);

void zad_5();
template <typename T>
T max(T *arr);

void zad_6();
template <typename T>
T maxn(T* arr,int size);
template <typename T>
int maxn(T* arr[],int size);

void zad_7();
template <typename  T>
T sumArray(T* arr[],int n);
template <typename  T>
T sumArray(T* arr,int n);

int main() {

    //zad_1();
    //zad_2();
    //zad_3();
    //zad_4();
    //zad_5();
    //zad_6();
    zad_7();

    system("pause");
    return 0;
}
void zad_1() {

    char str[80];
    cout << "Podaj napis: ";
    cin.getline(str,80);
    char wyb;
    int ile = 0;
    do {
        ile += showStr(str, ile);
        cout << "Wywowalc koljeny raz t - tak, n - nie" << endl;
        cin >> wyb;
    } while (wyb != 'n');
}
int showStr(char* str, int ile) {
    if (ile == 0)
        cout << "Zerowe wywolanie funkcji nie pokazemy napisu :(" << endl;
    else {
        cout << "Wywolanie nr:" << ile << endl;
        while (ile--) {
            cout <<" --> "<< str << endl;
        }
    }
    return 1;
}

void zad_2() {

    Batonik ptr;

    cout << "Wywowalnie  z parametrami domyślnymmi" << endl;
    showandSetStruct(ptr);
    cout << endl;

    cout << "Wywowalnie  z parametrami nadanymi" << endl;
    showandSetStruct(ptr, "Liga");
    cout << endl;

    cout << "Wywowalnie  z parametrami nadanymi" << endl;
    showandSetStruct(ptr, "Liga",3.14);
    cout << endl;

    cout << "Wywowalnie  z parametrami nadanymi" << endl;
    showandSetStruct(ptr, "Liga",3.14,500);
    cout << endl;

}
void showandSetStruct(Batonik & ptr, const char* str, double waga , int kcal){

    strcpy(ptr.prodc, str);
    ptr.waga = waga;
    ptr.kcal = kcal;

    cout << "Producent: " << ptr.prodc << endl;
    cout << "Waga: " << ptr.waga << endl;
    cout << "Kalorie: " << ptr.kcal << endl;
}

void zad_3() {

    string str;
    cout << "Podaj lancuch (q aby zakonczyc): ";
    getline(cin, str);
    while (str != "q") {
        toUp(str);
        cout<<"Nastepny lancuch (q aby zakonczyc): ";
        getline(cin, str);
    }
}
void toUp(string & str) {
    for (int i = 0; i < str.length(); i++)
        cout << (char)toupper(str[i]);
    cout << endl;

    //std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    //cout << str << endl;
}

void  zad_4() {
    Stringy beany;
    char testing[] = { "Rzeczywistosc to juz nie to, co kiedys" };
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Gotowe!");
    show();

}
void set(Stringy & obj,char* test) {

    obj.ct = strlen(test) + 1;
    obj.str = new char[obj.ct];		//Alokacja dla obiektu typu T
    strcpy(obj.str, test);		   //Skopiowanie danych
}
void show(const Stringy & obj, int ile) {
    while (ile--) {
        cout << obj.str << endl;
    }
}
void show(const char* str, int ile) {
    while (ile--) {
        cout << str << endl;
    }
}

void  zad_5(){
    int arr[5]={1,2,3,4,5};
    double tab[5]={3.14,2.7,3.8,4.23,5.32};

    int max2=max(arr);
    double max1=max(tab);
    cout<<"Int Max: "<<max2<<endl;
    cout<<"Double Max: "<<max1<<endl;
}
template <typename T>
T max(T *arr){
    T x=arr[0];
    for(int i=1;i<5;i++){
        if(arr[i]>x)
            x=arr[i];
    }
    return x;
}

void zad_6(){
    int arr[5]={5,42,53,23,8};
    double tab[4]={3.20,5.3,15.8,5.2};
    char* Array[]={"ab", "Ko"};

    cout<<"Max Int: "<<maxn(arr,5)<<endl;
    cout<<"Max Double: "<<maxn(tab,4)<<endl;
    cout<<"Max Char: "<<maxn(Array,2)<<endl;

}
template <typename T>
T maxn(T* arr, int size){
    T x=arr[0];
    for(int i=1;i<size;i++) {
        if (arr[i]>x)
            x = arr[i];
    }
    return x;
}
template <typename T>
int maxn(T* arr[],int size){
    int x=strlen(arr[0]);
    for(int i=1;i<size;i++) {
        if (strlen(arr[i])>x)
            x = strlen(arr[i]);
        else if (strlen(arr[i])==x)
            break;
    }
    return x;
}

void zad_7(){
    int things[6]={13,31,103,301,310,130};

    struct debts mr_E[3]={
            {"Ima Wolfe",2400.0},
            {"Ura Foxe", 1300.0},
            {"Iby Stout",1800.0}
    };
    double* pd[3];
    for(int i=0 ;i<3; i++)
        pd[i]=&mr_E[i].amount;

    cout<<"Wyliczanie rzeczy pana E.: "<<sumArray(things,6)<<endl;
    cout<<"Wyliczanie dlugow pana E.: "<<sumArray(pd,3)<<endl;
}

template <typename  T>
T sumArray(T* arr,int n){
    T sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
        return sum;
}
template <typename  T>
T sumArray(T* arr[],int n){
    T sum=0;
    for(int i=0; i<n; i++){
        sum+=*arr[i];
    }
    return sum;
}