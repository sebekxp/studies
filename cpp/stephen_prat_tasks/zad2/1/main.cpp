#include <iostream>

using namespace std;

const double ft =30.48;
const double cal=2.54;
const double lb=2.204;
const double funt=0.0254;

int main()
{
    int call,ftt,lbb;
    cout << "Podaj wzrost w stopach i calch oraz wage w funtach"<<endl;
    cout<<"Stopy: ";
    cin>>ftt;
    cout<<"Cale: ";
    cin>>call;
    cout<<"Waga: ";
    cin>>lbb;
    double height=(ftt*ft+call*cal)/cal;
    height*=funt;
    int weight= lbb/lb;
    cout<<"BMI: "<<weight/(height*height)<<endl;

    return 0;
}
