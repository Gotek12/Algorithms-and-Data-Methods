#include <iostream>
#include <cstdio>
using namespace std;

const int maxlegth = 20;
typedef int elementtype;
typedef int position;

class Stos
{
    int S[maxlegth];
    position Top; //szczyt stosu
  public:
    Stos();
    void Push(elementtype x);
    void Pop();
    bool Empty();
    elementtype TopElem();
    void Makenul();
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

int main()
{
    Stos s;
    cout << "Czy empty: " << s.Empty() << endl;
    s.Push(1);
    cout << "Po dodanie: Czy empty: " << s.Empty() << endl;
    cout << "El na szczycie: " << s.TopElem() << endl;
    cout << "Czy empty: " << s.Empty() << endl;

    s.Pop();
    cout << "Po Pop: Czy empty: " << s.Empty() << endl;

    s.Push(2);
    s.Push(3);
    cout << "Po 2xPush: El na szczycie: " << s.TopElem() << endl;
    s.Makenul();
    cout << "Po makenul: Czy empty: " << s.Empty() << endl;

    return 0;
}