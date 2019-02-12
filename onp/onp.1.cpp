#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

vector<char> rownanieTab;
vector<char> wyjscie;
//add to vector nazwa.push_back();
const int maxlegth = 50;
typedef char elementtype;
typedef int position;

class Stos
{
    char S[maxlegth];
    position Top; //szczyt stosu
  public:
    Stos();
    void Push(elementtype x); //dodaj el na szczyt
    void Pop(); //usuń el ze szczytu
    bool Empty(); //sprawdza czy pusty
    elementtype TopElem(); //el na wierzchu
    void Makenul(); //uczyń stos pustym
};

Stos::Stos()
{
    Top = -1;
}

elementtype Stos::TopElem()
{
    if (Stos::Empty())
    {
        cout << "Stos pusty" << endl;
    }
    else
    {
        return S[Top];
    }
}

void Stos::Push(elementtype x)
{
    if (Top > maxlegth)
    {
        cout << "Przepelnienie stosu" << endl;
    }
    else
    {
        Top = Top + 1;
        S[Top] = x;
    }
}
void Stos::Pop()
{
    if (Stos::Empty())
    {
        cout << "Stos pusty";
    }
    else
    {
        S[Top] = 0;
        Top = Top - 1;
    }
}
bool Stos::Empty()
{
    return (Top == -1);
}

void Stos::Makenul()
{
    Top = -1;
}

void test(){
    Stos s;
    //cout << "Czy empty: " << s.Empty() << endl;
    s.Push('+');
    //cout << "Po dodanie: Czy empty: " << s.Empty() << endl;
    //cout << "El na szczycie: " << s.TopElem() << endl;
    s.Push('-');
    //cout << "El na szczycie: " << s.TopElem() << endl;
    s.Push('*');
    //cout << "El na szczycie: " << s.TopElem() << endl;

    cout << endl << endl;
    //czytamy aż pusty
    while(s.Empty() == 0){
        cout << s.TopElem() << " ";
        s.Pop();
    }
}

int Priority(const char &c)
{
    if(c == '^')
    {
        return 3;
    }
    if(c == '*' || c == '/')
    {
        return 2;
    }
    if(c== '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool isOperator(const char &c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

//Konwersja wyrażenia z notacji  tradycyjnej do ONP 
void normalToOnp(){
    //int wielkosc = rownanieTab.size();
    int i = 0;
    //while(wielkosc != 0){
    while(rownanieTab[i]){
        //pobieramy el
        char el = rownanieTab[i];
        cout<< el << endl;
        
        i++;
        //wielkosc--;
    }
}

int main()
{
    string rownanie;
    //konwersja z notacji tradycyjnej do ONP
    cout << "Podaj rownanie w notacji tradycyjnej: " << endl;
    cout << ">";
    cin >> rownanie;

    //string to vector
    copy(rownanie.begin(), rownanie.end(), back_inserter(rownanieTab));
    
    
    //cout << rownanieTab.size();
    //czytamy rownanie
    /*
    for(int i=0; i < rownanieTab.size(); i++){
        cout << rownanieTab[i] << " ";
    }
    */

   normalToOnp();

    return 0;
}