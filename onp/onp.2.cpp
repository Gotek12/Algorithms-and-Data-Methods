#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> rownanieTab;
vector<string> wyjscie;
//add to vector nazwa.push_back();
const int maxlegth = 50;
typedef string elementtype;
typedef int position;

class Stos
{
    string S[maxlegth];
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
        S[Top] = "0";
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
    s.Push("+");
    //cout << "Po dodanie: Czy empty: " << s.Empty() << endl;
    //cout << "El na szczycie: " << s.TopElem() << endl;
    s.Push("-");
    //cout << "El na szczycie: " << s.TopElem() << endl;
    s.Push("*");
    //cout << "El na szczycie: " << s.TopElem() << endl;

    cout << endl << endl;
    //czytamy aż pusty
    while(s.Empty() == 0){
        cout << s.TopElem() << " ";
        s.Pop();
    }
}

bool isOperator(const string &c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}

bool TryParse(const string &symbol)
{
    bool isNumber = false;
    for(unsigned int i = 0; i < symbol.size(); i++)
    {
        char a = symbol[i];
        string tmp;
        tmp = a;

        if(isOperator(tmp) || tmp == "(" || tmp == ")")
        {
            isNumber = false;
        }
        /*if(!isdigit(symbol[i]))
        {
            isNumber = false;
        }*/

        else
        {
            isNumber = true;
        }
    }
    return isNumber;
}
int Priority(const string &c)
{
    if(c == "^")
    {
        return 3;
    }
    if(c == "*" || c == "/")
    {
        return 2;
    }
    if(c== "+" || c == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//Konwersja wyrażenia z notacji  tradycyjnej do ONP 
void normalToOnp(){
    Stos s;
    int wielkosc = rownanieTab.size();
    int i = 0;
    while(wielkosc != 0){
        //pobieramy el
        string el = rownanieTab[i];
        if(TryParse(el)){
            wyjscie.push_back(el);
        }
        if(el == "(")
        {
            s.Push(el);
        }
        if(el == ")")
        {
            while(!s.Empty() && s.TopElem() != "(")
            {
                wyjscie.push_back(s.TopElem());
                s.Pop();
            }
            s.Pop();
        }
        if(isOperator(el) == true)
        {
            while(!s.Empty() && Priority(s.TopElem()) >= Priority(el))
            {
                wyjscie.push_back(s.TopElem());
                s.Pop();
            }
            s.Push(el);
        }

        i++;
        wielkosc--;
    }

    while(!s.Empty())
    {
        wyjscie.push_back(s.TopElem());
        s.Pop();
    }

    for(unsigned int i = 0; i < wyjscie.size(); i++)
    {
        cout<<wyjscie[i];
    }

}

size_t split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

int main()
{
    string rownanie;
    //konwersja z notacji tradycyjnej do ONP
    cout << "Podaj rownanie w notacji tradycyjnej oddzielając kazdy el spacja: " << endl;
    cout << ">";

    getline(cin, rownanie);
    //rownanie = "1 - ( 2 * 3 ) + ( 4 / 2 ) ^ 2";

    //string to vector
    //copy(rownanie.begin(), rownanie.end(), back_inserter(rownanieTab));
    istringstream iss(rownanie);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        rownanieTab.push_back(s);
    }

    normalToOnp();

    return 0;
}