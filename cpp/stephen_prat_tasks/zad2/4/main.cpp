#include <iostream>

using namespace std;

int main()
{
    long double world, pol;
    cout << "Podaj liczbe ludnosci Swiata: ";
    cin>>world;
    cout << "Podaj liczbe ludnosci Polski: ";
    cin>>pol;
    double pop=pol*100/world;
    cout<<"Populacja Polski stanowi "<<pop<<" % populacji Swiata"<<endl;
    return 0;
}
