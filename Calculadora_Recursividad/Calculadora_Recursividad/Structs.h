#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



/**Creamos Elementos de lista (Imagen de la funcion)
Almacenara la imagen de la funcion recursiva en n**/
typedef struct Datos{
	//Valor es la imagen f(x)
	long long int valor;
	//posicion es la recursion
	int posicion;
	
	struct Datos* sig;
}Datos;

/**Creamos elementos de nodo (Estos son para Pilas)
Este se utiliza en calculadora para calcular**/
typedef struct Nodo{
	//Guarda valores de calculadora
	long long int valor;
	struct Nodo* sig;
}Nodo;





//Elementos de Lista
void agregar(Datos **p,long long int v,int n);

Datos* buscar(Datos* p, int n);


//Elementos de Pila
void poner(Nodo **p,int v);

void sacar(Nodo **p);

int vacio(Nodo* p);









//Operaciones de pilas
//Pone un elemento en la pila
void poner(Nodo**p, int v){
	Nodo* nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->valor=v;
	nuevo->sig=*p;
	*p=nuevo;
}
//Quita el elemento de la pila
void sacar(Nodo**p){
	Nodo* aux=*p;
	*p=aux->sig;
	free(aux);
}
//Devuelve si esta vacio
int vacio(Nodo* p){
	return p==NULL;
}









//Operaciones de listas

//Agrega un elemento
void agregar(Datos** p,long long int v,int n){
	//Creamos nuevo datos
	Datos *nuevo=(Datos*)malloc(sizeof(Datos));
	nuevo->valor=v;
	nuevo->posicion=n;
	nuevo->sig=NULL;
	
	//Si la lista esta vacia, entonces p apunta al nuevo nodo
	if(*p==NULL){
		*p=nuevo;
	}
	else{
		Datos* aux=*p;
		
		//Recorremos la lista hasta el final
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		
		
		//Agregamos el nuevo nodo
		aux->sig=nuevo;
		
	}
}


//Busca un elemento
Datos* buscar(Datos* p,int n){
	Datos* aux=p;
	while((aux!=NULL) && (aux->posicion!=n)){
		aux=aux->sig;
	}
	
	return aux;
}

