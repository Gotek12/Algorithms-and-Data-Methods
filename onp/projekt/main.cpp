#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>
#include <windows.h> 
#include "onp.cpp"

using namespace std;
string rownanie;

void tradycyjnaToOnp(Onp on);
void wyliczOnp(Onp on);
void liczymy(Onp on);
void clear();
void menu(Onp on);

int main()
{
    Onp on;
    menu(on);
    return 0;
}

void tradycyjnaToOnp(Onp on){
    cout << "Podaj rownanie w notacji tradycyjnej (kazdy el oddzielony spacja) " << endl;
    cout << ">";
    getline(cin, rownanie);

    //string to vector
    istringstream iss(rownanie);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        rownanieTab.push_back(s);
    }

    on.normalToOnp();
    for(int i = 0; i < wyjscie.size(); i++)
    {
        cout<<wyjscie[i];
    }
}

void wyliczOnp(Onp on){
    cout << "Podaj rownanie w onp (kazdy el oddzielony spacja)" << endl;
    cout << ">";
    getline(cin, rownanie);
    
    //string to vector
    istringstream iss(rownanie);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        onp.push_back(s);
    }

    //onpTonormal();
    cout << on.onpCount();
}

void liczymy(Onp on){
    cout << "Podaj rownanie w notacji tradycyjnej (kazdy el oddzielony spacja) " << endl;
    cout << ">";
    getline(cin, rownanie);

    //string to vector
    istringstream iss(rownanie);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        rownanieTab.push_back(s);
    }
    on.normalToOnp();
    copy(on.tmpWyjscie.begin(), on.tmpWyjscie.end(), back_inserter(onp));
    cout << on.onpCount();
    
}

void clear(){
    Sleep(3000);
    system("CLS");
    rownanieTab.clear();
    wyjscie.clear();
    onp.clear();
}

void menu(Onp on){
    int n;
    for(;;){
        cout << endl << "MENU GLOWNE" << endl << endl;
        cout << "1. Konwersja z notacji tradycyjnej do ONP" << endl;
        cout << "2. Obliczanie za pomoca ONP" << endl;
        cout << "3. Obliczanie w ONP podajac dzialanie w notcji tradycyjnej" << endl;
        cout << "4. koniec " << endl << endl;

        cout << ">";
        cin >> n;
        cin.ignore();

        switch(n){
            case 1:
                system("CLS");
                tradycyjnaToOnp(on);
                clear();
                break;
            case 2:
                system("CLS");
                wyliczOnp(on);
                clear();
                break;
            case 3:
                system("CLS");
                liczymy(on);
                clear();
                break;
            case 4:
                system("CLS");
                exit(0);
                break;
            default:
                system("CLS");
                cout << "Blad" << endl;
                clear();
                break;
        }
    }
}