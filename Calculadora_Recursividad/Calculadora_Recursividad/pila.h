#include <stdlib.h>
#define MAX_ELEMENTOS 50
typedef struct pila{
      int indice;
      int total;
      char datos[MAX_ELEMENTOS];
}Pila;

Pila * crear(){
	Pila *p;
	p=(Pila *)malloc(sizeof(Pila));
	p->indice=0;
	p->total=0;
	return p;
}

int estaVacia(Pila pila){
	if(pila.total==0){
		return 1;
	}else{
		return 0;
	}
}

int estaLlena(Pila pila){
	if(pila.total==MAX_ELEMENTOS){
		return 1;
	}else{
		return 0;
	}
}

int push(Pila *pila, char dato){
	if(pila->total<MAX_ELEMENTOS){
		pila->datos[pila->indice]=dato;
		pila->indice++;
		pila->total++;
		return 1;
	}else{
		return 0;
	}
}

char pop(Pila *pila){
	int aux;
	if(pila->total>0){
		aux=pila->datos[pila->indice-1];
		pila->indice--;
		pila->total--;
		return aux;
	}else{
		return -1;
	}	
}
