#include <iostream>
using namespace std;
int zmiana(int);
int main()
{   int cel;
    cout << "Podaj temperature w stopnach Celsjusza: ";
    cin>>cel;
    cout<<cel<<" stopni Celsjusza to "<<zmiana(cel)<<" stopni Farhenheita"<<endl;
    return 0;
}
int zmiana(int c)
{
    return 1.8*c+32;
}
