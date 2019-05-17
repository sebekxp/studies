#include <iostream>

using namespace std;
const double ft =30.48;
const double cal=2.54;
int main()
{   int cm;
    cout << "Podaj wzrost w cm: ___\b\b\b";
    cin>>cm;
    cout<<"Twoj wzrost to "<<int(cm/ft)<< " stopy i "<<int(cm/cal)%12<<" cali"<<endl;

    return 0;
}
