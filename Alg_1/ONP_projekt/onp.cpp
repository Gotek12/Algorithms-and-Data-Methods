#include "stos.cpp"
vector<string> rownanieTab;
vector<string> wyjscie;
vector<string> onp;

class Onp{
    private:
        bool sprOperator(string &znak);
        bool sprOpZnawiasami(string &znak);
        int priorytet(const string &znak);
    public:
        vector<string> tmpWyjscie;
        Onp(){}
        void normalToOnp();
        elementtype onpCount();        
};

bool Onp::sprOperator(string &znak)
{
    return (znak == "+" || znak == "-" || znak == "*" || znak == "/" || znak == "^");
}

bool Onp::sprOpZnawiasami(string &znak)
{
    bool znakSpr = false;
    for(int i = 0; i < znak.size(); i++)
    {
        char tmpZnak = znak[i];
        string tmp;
        tmp = tmpZnak;

        if(sprOperator(tmp) || tmp == "(" || tmp == ")")
        {
            znakSpr = false;
        }
        else
        {
            znakSpr = true;
        }
    }
    return znakSpr;
}

int Onp::priorytet(const string &znak)
{
    if(znak == "^")
    {
        return 3;
    }
    if(znak == "*" || znak == "/")
    {
        return 2;
    }
    if(znak == "+" || znak == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Konwersja wyrażenia z notacji  tradycyjnej do ONP 
void Onp::normalToOnp(){
    Stos s;
    int wielkosc = rownanieTab.size();
    int i = 0;
    while(wielkosc != 0){
        //pobieramy el
        string el = rownanieTab[i];
        if(sprOpZnawiasami(el)){
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
        if(sprOperator(el) == true)
        {
            while(!s.Empty() && priorytet(s.TopElem()) >= priorytet(el))
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
    copy(wyjscie.begin(), wyjscie.end(), back_inserter(tmpWyjscie));

}

elementtype Onp::onpCount(){
    Stos s;
    double wynik;
    int length = onp.size();
    for (int i = 0; i < length; i++) { 
       if(sprOperator(onp[i])){
            string znak1 = s.TopElem();   
            double char1 = atoi(znak1.c_str());
            s.Pop(); 
            string znak2 = s.TopElem();   
            double char2 = atoi(znak2.c_str());
            s.Pop(); 
            
            if(onp[i] == "*"){
                wynik = char2*char1;
            }
            if(onp[i] == "+"){
                wynik = char2+char1;
            }
            if(onp[i] == "/"){
                wynik = char2/char1;
            }
            if(onp[i] == "-"){
                wynik = char2-char1;
            }
            if(onp[i] == "^"){
                wynik = pow(char2, char1);
            }
            
            ostringstream ss;
            ss << wynik;
            string tmp = ss.str();
            s.Push(tmp); 
        }else{
            s.Push(onp[i]); 
        } 
    }
    return s.TopElem();
}