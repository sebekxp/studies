#include <iostream>
using namespace std;

int metry(int);

int main()
{   int mila;
    cout << "Podaj odleglosc w milach :";
    cin>>mila;
    cout<<"Ta sama odleglosc w metrach to :"<<metry(mila)<<endl;

    return 0;
}

int metry(int mila)
{
    return mila*1852;
}
