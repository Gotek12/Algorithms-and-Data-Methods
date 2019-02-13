#include <iostream>
#include <string>

using namespace std;
const int maxlegth = 150;
typedef string elementtype;
typedef int position;

class Stos
{
  private:
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