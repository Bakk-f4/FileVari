#include <iostream>
#include <string>
#include <vector>

typedef int Elem;

struct cell{
	Elem info;
	cell*next;
};

typedef cell*list;

void tailInsert(list &, Elem );



int main(){

}


void tailInsert(list & t, Elem nuovoCampo){		
	
	cell *aux = t;				//cella aux per scorrere
	cell *newCell = new cell;		//cella da inserire
	newCell->info = nuovoCampo;
						//t = [] 
						//	   aux
	if(aux == nullptr){			//t = [][][]
		t = newCell;
		newCell->next = nullptr;	//se lista vuota inserisco in testa
	}
	else{					
		while(aux->next != nullptr){	//senno scorro fino all ultimo e inserisco
			aux = aux->next;
		}
		aux->next = newCell;
		newCell->next = nullptr;
	}
}

void insertNewBook(list &l, Elem b){		//inserimento in coda ricorsivo

	cell* newCell = new cell;
	newCell->info = b;
	newCell->next = nullptr;			
	
	if(l == nullptr){				
		l = newCell;
		return;
	}
	else if(l->next == nullptr){	
		
		l->next = newCell;
		return;
	}	
	insertNewBook(l->next, b);
}


void headInsert(list &l, std::string s){			//head insert
	
	cell* aux = new cell;
	
	aux->info = s;
	aux->next = l;
	
	l = aux;
	
}

void headRemove(list &s){					//cancello l elemento in testa alla lsita
	if(s == nullptr){
		std::string err = "The stack is empty\n";
		throw err;
	}
	cell *aux = new cell;					// creo un aux per tenere traccia dell elemento
	aux = s;
	s = s->next;						//scorro la lista in avanti e
	delete aux;						// e cancello il primo elemento
}


void convDateTime(STRUCT CON UNA DATA E ORA DA MODIFICARE &){	//06 06 20
	int newDate = r.date;
	r.aaaa = (newDate % 100)+2000;
	r.mm = (newDate / 100) % 100;
	r.gg = (newDate / 10000);
	
	int newTime = r.time;						//HH MM SS
	r.s = newTime%100;
	r.m = (newTime/100)%100;
	r.h = (newTime/10000);
}

void sort(list & c){			

	if(c == nullptr) return;	//se vuota ritorno
	cell *scorri = c->next;	//cella per scorrere (qui sto confrontando l elem successivo al primo!!!)
					//senno faccio semplicemente !!cell*scorri = c;!!
	while(scorri != nullptr){
		cell *min = scorri;		//cella da tenere in considerazione
		cell *jmin = scorri->next;	//cella successiva da confrontare con la prima
		while(jmin != nullptr){
			if(compare(min->info, c->info) > compare(jmin->info, c->info))	//qui faccio il confronto
				min = jmin;		//se trovo che jmin e' minore di min allora assegno jmin a min
			jmin = jmin->next;			
		}
		swapGprmc(scorri->info, min->info);		//faccio la swap SOLO DEL CONTENUTO! NIENTE CELLE
		scorri = scorri->next;
	}
	return;
}

void deleteElem(list &s, std::string a){ 	//cancello elemento che trovo tramite stringa
	
	if(isEmpty(s)){
		std::string err = "The stack is empty\n";
		throw err;
	}
	cell *prev = s;
	cell *curr = s;
	
	while(curr != nullptr){
		if(curr->info.modello == a)
			break;
		prev = curr;
		curr = curr->next;	
	}
	if(curr == s){
		s = s->next;
		delete curr;
	}
	else{
		prev->next = curr->next;
		delete curr;
	}	
}

bool isIn(list &s, std::string nome){	//is in bool di ricerca tramite stringa in lista
	cell *newCell = s;
	while(newCell != nullptr){
		if(newCell->info.modello == nome){
			return true;
			break;
		}
		newCell = newCell->next;
	}
	return false;	
}

bool is_in(list& l, int x){		//is in ricorsiva che ricerca un int x
	if(l == nullptr)
		return false;
	if(l->info == x)
		return true;
	return is_in(l->next, x);
}

int length(list& l){			//luinghezza lista ricorsiva
	if (l == nullptr)
		return 0;
	return 1+length(l->next);
}


bool isEmpty(list &s){			//bool che verifica se lista e' vuota o no
	return (s == nullptr);
}


void enqueue(queue& q, Elem e){	// Inserisco in coda nelle queue
	cell *aux = new cell;
	aux->head = e;
	aux->next = nullptr;
	
	if(q.tail == nullptr){
		q.head = aux;
		q.tail = aux;
	} 
	else {
		q.tail->next = aux;
		q.tail = aux;
	}
}

void dequeue(queue& q){		//elimino elemento dalla testa
	if(q.tail == nullptr){
		std::string err = "DEQUEUE: Empty queue\n";
		throw err;
	}
	cell* temp = q.head;
	q.head = q.head->next;
	delete temp;
	if(q.head == nullptr)
		q.tail = nullptr;
}


void reverse(vector<int>& v, int begin, int end){	//reverse di un vector di int ricorsiva
	if (v.size()/2 == begin) return;
	int temp = begin;
	v.at(begin) = v.at(end);
	v.at(end) = temp;
	return reverse(v, begin+1, end-1);
}

bool palindromo(vector<int> v, int begin, int end){		//palindromo rec su vector di int
	if(v.size()%2 == 1 && v.size()/2 == begin) return true;
	else if (v.size()/2 == begin) return (v.at(begin) == v.at(begin+1));
	return v.at(begin) == v.at(end) && palindromo(v, begin+1, end-1);
}









