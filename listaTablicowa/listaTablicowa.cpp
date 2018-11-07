typedef int elementtype, position ;
const int maxlength = 10;
struct List{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l){ 
	return l.last + 1;
}

position First(List l) {
	return 0;
}

position Next(position p,List l){
	if(p < END(l)){
		return p + 1;
	}else{
		return -1;
	}
}
 
 
position Previous(position p,List l) {
	if((p <= First(l)) || (p > END(l))){
		return -1;
	}else{
		return p - 1;
	} 
}
 
 
 
position Locate(elementtype x, List l) { //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
	for(int i = 0; i < END(l); i++){
		if(l.elements[i] == x){
			return i;
		}		
	}
	return END(l);
}
 

elementtype Retrieve(position p, List l) {
	if((p >= 0) || p <= END(l)){
		return l.elements[p];
	}else{
		return -1000;
	}
}

bool Insert(int x, position p, List &l){
	if((p < 0) || (p > END(l))){
		return false;
	}

	if(p <= END(l)){
		if(p != END(l)){
			for(position koniec = END(l); koniec > p; koniec--){
				l.elements[koniec] = l.elements[koniec - 1];
			}
		}
		l.elements[p] = x;
		l.last = l.last + 1;
		return true;
	}

	return false;
}

bool Delete(position p, List &l){

	while (p < END(l) - 1){
        l.elements[p] = l.elements[p + 1];
        p++;
    }
    l.last--;

    return false;
}
