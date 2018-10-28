/*
    Wojciech Ładyga
    25.10.18
*/
//sortowanie przez scalanie (merge sort)
//z ciagiem bitonicznym

//zrodla
//https://pl.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/overview-of-merge-sort
//https://www.geeksforgeeks.org/find-bitonic-point-given-bitonic-sequence/
//https://4programmers.net/Forum/Newbie/243816-ciag_bitoniczny_


#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
//tablica wielkosci ilosc do posortowania
const int ilosc = 10;
int tab[ilosc] = {10, 1, 3, 0, 5, 6, 2, 9, 8, 7};

void bitSort(int l, int srodek, int koniec);
void merge(int l, int p);

int main(){
    //tablica do posortowania
    int n = ilosc;
    //koordynany początku i końca tablicylicy, prawy skraj tablicy(jej koniec)
    int l = 0, p = n-1;

    cout << "Przed sortowaniem" << endl;
    for(int i = 0; i <= p; i++){
        cout << tab[i] << " ";
    }
    merge(l, p); 

    //wynik
    cout << endl << "Po posortowaniu" << endl;
    for(int i = 0; i <= p; i++){
        cout << tab[i] << " ";
    }
    return 0;
}

//funkcja dostająca małe skrawki tablicy i sortująca je po wielkosci
void bitSort(int l, int srodek, int koniec){
    int pom[koniec];

    //tworze tablice pomocniczą w postaci ciagu bitonicznego
    for(int i= 0; i <= srodek; i++){
        pom[i] = tab[i];
    }
    for(int i = srodek+1; i <= koniec; i++){
        pom[i] = tab[koniec + srodek + 1 - i];
    }
    
    //teraz sortujemy
    int i = l, j = koniec;
    for(int q = i; q <= koniec; q++){
        if(pom[j] < pom[i]){
            tab[q] = pom[j];
            j--;
        }else {
            tab[q] = pom[i];
            i++;
        }
    }

}

//funkcja dzieli tablice na częsci
void merge(int l, int p){
    int srodek;

    //działamy do momętu gdy prawy koniec jest większy od lewego
    //czyl dzielimy do momętu jak w tablicy będzie 1 el
    if(p > l){
        srodek = floor((p+l)/2); //znajdujemy srodek tablicy
        merge(l, srodek); //dzielimy na poł 
        merge(srodek + 1, p); //dzielimy na poł
        bitSort(l, srodek, p); //sortujemy
    }
}