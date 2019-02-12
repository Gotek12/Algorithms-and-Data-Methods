#### ONP

3+4     3 4 +  
sinx    x sin  
cos(x+y)    x y + cos  

stosujemy w teori jezykow - np piszac kompilator  
w poniektorych jezykach  

Obliczanie wartosci wyrazenia z onp:

        while (nie_koniec_danych){
            pobierz_kolejny_element;
            if (element_jest_operandem)
                wstaw_wartość_operanda_na_stos; //operacja PUSH
            else //element jest operatorem{
                pobierz_ze_stosu_potrzebne_argumenty; //operacje TOP i POP
                wykonaj_działanie;
                wstaw_wynik_na_stos; //operacja PUSH
            }
        } //wartość wyrażenia jest na szczycie stosu;

np. a b c * - d b 2 / ^ +  

s: a b c   
s: a b*c  
s: (a - b*c)
s: (a - b*c) d b 2  
s: (a - b*c) d b/2  
s: (a - b*c) d^(b/2)  
s: (a - b*c) + d^(b/2)  

minus unarny bierze 1 argument "~";
np. b ~ b 2 ^ 4 a + c + - sqrt - 2 a * /

krótka dokumentacja do projektu

Konwersja wyrażenia z notacji  tradycyjnej do ONP 

        while (nie_koniec_danych){
            weź_kolejny_element;
            if (element_jest_operandem) dopisz_element_na_wyjście;
            Else //element jest_operatorem_lub_nawiasem{
                if (element_jest_operatorem)
                while (proirytet_operatora_na_stosie>=priorytet_elementu)
                    przepisz_operator_ze_stosu_na_wyjście;
                wstaw_operator_na_stos;// operacja PUSH
            }
            Else
                If (element=”(„ ) wstaw_element_na_stos;
                Else
                If (element=”)„ ) //zdejmuj ze stosu aż do „)”
                while (na_stosie_operator)
                     przepisz_operator_ze_stosu_na_wyjście; //op. POP
                zdejmij_ze_stosu_”(„ //operacja POP
        }
        while (nie_pusty_stos)
            przepisz_operator_ze_stosu_na_wyjście;
    
##### Kolejka
dodajemy na koniec i sciągamy z poczatku

Kolejka - lista FIFO(first in first out)

Operacje:
1. MAKENULL(Q) – czyni kolejkę pustą
2. FRONT(Q) – zwraca pierwszy element kolejki
3. ENQUEUE(x,Q) – wstaw x do kolejki
4. DEQUEUE(Q) – usuwa pierwszy element z kolejki
5. EMPTY(Q) – zwraca true gdy kolejka jest pusta, w przeciwnym wypadku zwraca false

mozna dodac wskaznik na koniec aby wszystkioperacje byly O(1)

###### Reprezentacja tablicowa 
stosujemy kolejke cykliczna 
przy usuwaniu zmieniamy front aby nie przesowac wszystkich el np Front = 1 po usunieciu 1 el itp  

wiec zakrzywiamy nasza tablice tak, że po ostatnim el w tablicy jest el 0-tablicy  

funkcja addone - zwraca wartosc o 1 wieksza

        int AddOne(int i){
            return ((i+1)%maxLength);
        }

kolejka pusta to rear- ostatnia komorka tablicy, a front = 0
gdy dodamy 1 el to rear zwiekszamy i wskazuje na ten sam el co front

kolejka pełna - bedzie miala tez wskazniki na tym samym el wiec mamy problem
wiec mamy jednowiec należy pamietać  n-1 el