#include <iostream>
#include <cstdio>
using namespace std;

typedef int elementtype;
struct celltype
{
    elementtype element;
    celltype *next;
    celltype *position;
};
typedef celltype *position;

class Lista
{

  protected:
    position l; // wskaźnik do głowy listy
  public:
    Lista();  //konstruktor
    ~Lista(); //destruktor
    void Insert(elementtype x, position p);
    void Delete(position p);
    elementtype Retrieve(position p);
    position Locate(elementtype x);
    position First();
    position Next(position p);
    position Previous(position p);
    position END();
    void print();
    void Duplicate();
    void DuplicateDel();
};

void Lista::Duplicate()
{
    position pocz = First();

    while (pocz != END())
    {
        elementtype el = Retrieve(pocz);
        //pocz -> next
        position tmp = pocz->next;
        pocz->next = new celltype;
        pocz->next->element = el;
        pocz->next->next = tmp;
        pocz = pocz->next->next;
    }
}

void Lista::DuplicateDel()
{
    position pocz = First();

    while (pocz != END())
    {
        elementtype el = Retrieve(pocz);
        elementtype el2 = Retrieve(pocz->next);
        position po2 = pocz->next;

        //cout << el << " ";
        //cout << Retrieve(pocz->next) << " ";

        if (el == el2)
        {
            Delete(po2);
            pocz = pocz->next;
        }
        else
        {
            pocz = pocz->next->next;
        }
    }
}

Lista::Lista()
{
    l = new celltype();
    l->next = NULL;
}

position Lista::First()
{
    return l;
}

position Lista::Next(position p)
{
    return p->next;
}

elementtype Lista::Retrieve(position p)
{
    if (p->next != NULL)
    {
        return p->next->element;
    }
}

//delete
void Lista::Delete(position p)
{
    position tmp;
    tmp = p->next;
    p->next = p->next->next;
    delete tmp;
}

//previous
position Lista::Previous(position p)
{
    position tmp;
    tmp = l;
    while (tmp->next != p)
    {
        tmp = tmp->next;
    }
    return tmp;
}

//locate
position Lista::Locate(elementtype x)
{
    position tmp;
    tmp = l;
    while (tmp->next != NULL)
    {
        if (tmp->next->element == x)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

//END
position Lista::END()
{
    position p = l;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

void Lista::Insert(elementtype x, position p)
{
    //dziala ale tak nie powninno byc
    /*position tmp = l;
    p->next = new celltype;
    p->next->element = x;
    p->next->next = tmp;
    */
    position tmp = p->next;
    p->next = new celltype;
    p->next->element = x;
    p->next->next = tmp;
}

void Lista::print()
{
    position i = First();
    while (i != END())
    {
        printf("  %d,", Retrieve(i));
        i = Next(i);
    }
    printf("\n");
}

//destruktor
Lista::~Lista()
{
    while (First() != NULL)
    {
        Delete(First());
    }
}

int main()
{
    /*
    Lista l;
    l.Insert(5, l.First());
    cout << l.Retrieve(l.First()) << endl;
    cout << "Pierwszy: " << l.Retrieve(l.First()) << endl;
    cout << endl;

    l.Insert(2, l.First());

    cout << "Pierwszy: " << l.Retrieve(l.First()) << endl;
    cout << "Drugi: " << l.Retrieve(l.Next(l.First())) << endl;
    cout << endl;

    l.Insert(1, l.First());
    cout << "Pierwszy: " << l.Retrieve(l.First()) << endl;
    cout << "Drugi: " << l.Retrieve(l.Next(l.First())) << endl;
    cout << "Trzeci: " << l.Retrieve(l.Next(l.Next(l.First()))) << endl;
    */

    Lista l;
    l.Insert(100, l.First());
    //l.print();

    for (int i = 0; i < 3; i++)
        l.Insert(i, l.First());
    //l.print();

    l.Insert(20, l.Previous(l.END()));
    //l.print();

    l.Delete(l.Locate(20));
    //l.print();

    l.Insert(200, l.Locate(0));
    l.print();

    //wstawianie i usuwanie dunplikatow
    l.Duplicate();
    l.print();

    l.DuplicateDel();
    l.print();
    return 0;
}