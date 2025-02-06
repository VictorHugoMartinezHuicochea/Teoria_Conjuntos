#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pila.h"

//Esta funcion establece las prioridades de la simbologia
int Prioridad(char simbolo){
	int regreso=0;
	switch(simbolo){
		case '(': regreso=0;
		break;
		case '+': regreso=1;
		break;
		case '-': regreso=1;
		break;
		case '*': regreso=2;
		break;
		case '%': regreso=2;
		break;
		case '^': regreso=3;
		break;
		case 'f': regreso=4;
		break;}
	return regreso;
}

//Esta funcion verifica si es operador
//nos regresa 1 si es un operador y 0 si no lo es
//Y 2 si es un parentesis de cierre 
int OP(char simbolo){
	if(simbolo== 'f' ||
	simbolo== '^' ||
	simbolo== '+' ||
	simbolo== '-' ||
	simbolo== '*' ||
	simbolo== '%' 
	) {return 1;
	}else if(simbolo == '('){
		return 2;
	}
	else if(simbolo== ')'){
		return 3;
	}else {return 0;}		
}

//Esta funcion comparara la prioridad de los operadores
//regresa 1 si sim1 tiene mayor o igual prioridad que sim2
//regresa 0 si es menor
int Compara(char sim1,char sim2){
	int valor1=Prioridad(sim1);
	int valor2=Prioridad(sim2);
	if(valor1>=valor2){
		return 1;
	}else{
	return 0;}
}	

char* Traduce(char *cadena){
	char A,B;
	int i=0,j=0,aux;
	char *salida;
	salida=(char*)malloc(sizeof(char)*100);
	Pila *pila=crear();
	//ciclo principal de la funcion
	while(i<strlen(cadena)){
		A=cadena[i]; //elemento a analizar
		i++;
		aux=OP(A);
		//condicional por si NO es un operador
		if(aux==0){
			salida[j]=A;
			j++;
		}else if(aux==1){ //condicional por si es operador
			if(!estaVacia(*pila)){//Si la pila no esta vacia
				int aux1;
				do{
				B=pop(pila); //sacamos el inmediato anterior de la pila y comparamos
				  if(Compara(B,A)){//Si la prioridad es mayor entonces lo pone en la salida
					 salida[j]=B;
				   	 j++;
					 aux1=1;
				}else{//en su defecto lo mete a la pila
					aux1=0;
					push(pila,B);
				}
			}while(!estaVacia(*pila) && aux1==1);
				
			}
			push(pila,A); //si es que esta vacia
		}else if(aux==2){
			push(pila,A);
		}
		else if(aux== 3){//Si el encontramos un parentesis de cierre
			B=pop(pila);// sacamos el inmediato anterior
			while(!estaVacia(*pila) && B!='('){ //Ponemos en la salida hasta encontrar el otro parentesis o se vacie la pila
				salida[j]=B;
				j++;
				B=pop(pila);
			}
		}
	}//vaciamos la pila
	while(!estaVacia(*pila)){
		B=pop(pila);
		salida[j]=B;
		j++;
	}
	salida[j]='\0';
	return salida;
}

char* Espacios(char* cadena){
	char* salida;
	salida=(char*)malloc(sizeof(char)*100);
	int i=0,j=0;
	int tam=strlen(cadena);
		while(cadena[i]){
			salida[j]=cadena[i];
			salida[j+1]=' ';
			i++;
			j+=2;
		}
		salida[j]= '\0';
		return salida;
}
	

