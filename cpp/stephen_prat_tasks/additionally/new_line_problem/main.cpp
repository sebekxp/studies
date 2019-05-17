#include <iostream>

using namespace std;

int main()
{
    cout << "W ktorym roku zbudowano twoj dom?\n";
    int year;
    cin>>year;
    cin.get();
    //(cin>>year).get()
    //cin.get(ch)
    /*W kolejce zostaje znak nowego wiersza wygenerowany przez Enter, nastepnie cin.getline() wczytuje znak nowego wiersza
    interpretujac to jako natkniecie sie na znak nowego wiersza, wiec tablicy adress przypisuje pusty wiersz-sam znak NUL
    rozwiazaniem jest dorzucenie znaku nowego wiersza przed wczytaniem adresu.3 sposoby pokazano powyzej*/
    cout<<"Przy jakiej ulicy mieszkasz?\n";
    char adres[80];
    cin.getline(adres,80);
    cout<<"Rok budowy: "<<year<<endl;
    cout<<"Adres: "<<adres<<endl;

    return 0;
}
