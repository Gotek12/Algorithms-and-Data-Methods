#include <iostream>
#include <stdio.h>
#include "listaTablicowa.cpp"
using namespace std;

void print(List l);

int main()
{
	List l;
	l.last = -1;
	Insert(100, First(l), l);
	print(l);

	for (int i = 0; i < 3; i++)
		Insert(i, First(l), l);
	print(l);

	Insert(20, Previous(END(l), l), l);
	print(l);
	Delete(Locate(20, l), l);
	print(l);

	//szukam 0 i  wstawiam 200 przed 0
	Insert(200, Locate(0, l), l);
	print(l);

	//moj test
	Insert(8, Locate(2, l), l);
	print(l);

	return 0;
}

void print(List l)
{
	position i = First(l);
	while (i != END(l))
	{
		printf("  %d,", Retrieve(i, l));
		i = Next(i, l);
	}
	printf("\n");
}