#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Structs.h"



long long int Calcular(char Frase[],Datos* resultados);

long long int Calcular(char Frase[],Datos* resultados){
 	//Inicializaamos Una pila
	struct Nodo *Numeros=NULL;
	
	//F es el operador de busqueda
	char Operadores[][2]={"+","-","*","%","^","f"};
	
	//Elementos a operar
	long long int a,b,c;
	int i,error;
	error=0;
	
	//Delimitador
	char delimitador[]=" ";
	
	//Obtenemos el primer elemento (Debe ser un valor entero)
	
	char *elemento=strtok(Frase,delimitador);
	
	//Obtenemos las particiones del string
	while(elemento!=NULL){
		//si es un numero, convertimos a numero y lo agregamos a la pila
		if(isdigit(elemento[0])){
			a=atol(elemento);
			poner(&Numeros,a);
		}
		//Si es un operador, se quitan los ultimos dos elementos de la cola y se  operan
		else{
			//Si es suma
			if(strcmp(elemento,Operadores[0])==0){
				/**Obtenemos los ultimos dos numeros de la pila y realizamos la operacion
				a su vez los sacamos puesto que los vamos a operar**/
				a=Numeros->valor;
				sacar(&Numeros);
				b=Numeros->valor;
				sacar(&Numeros);
				
				//Obtenemos su operacion
				c=a+b;

				//La agregamos a la pila
				poner(&Numeros,c);
			}
			
			
			//Si es resta
			if(strcmp(elemento,Operadores[1])==0){
				/**Obtenemos los ultimos dos numeros de la pila y realizamos la operacion
				a su vez los sacamos puesto que los vamos a operar**/
				a=Numeros->valor;
				sacar(&Numeros);
				b=Numeros->valor;
				sacar(&Numeros);
				
				//Obtenemos su operacion
				c=b-a;
				
				//La agregamos a la pila
				poner(&Numeros,c);
			}
			
			//Si es multiplicacion
			if(strcmp(elemento,Operadores[2])==0){
				/**Obtenemos los ultimos dos numeros de la pila y realizamos la operacion
				a su vez los sacamos puesto que los vamos a operar**/
				a=Numeros->valor;
				sacar(&Numeros);
				b=Numeros->valor;
				sacar(&Numeros);
				
				//Obtenemos su operacion
				c=a*b;
				
				//La agregamos a la pila
				poner(&Numeros,c);
			}
			
			
			
			
			//Si es modulo
			if(strcmp(elemento,Operadores[3])==0){
				/**Obtenemos los ultimos dos numeros de la pila y realizamos la operacion
				a su vez los sacamos puesto que los vamos a operar**/
				a=Numeros->valor;
				sacar(&Numeros);
				b=Numeros->valor;
				sacar(&Numeros);
				if(a==0){
					error=1;
					break;
				}
				else{
				//Obtenemos su operacion
				c=b%a;	
				//La agregamos a la pila
				poner(&Numeros,c);
				}

			}
			
			//Si es potencia
			if(strcmp(elemento,Operadores[4])==0){
				/**Obtenemos los ultimos dos numeros de la pila y realizamos la operacion
				a su vez los sacamos puesto que los vamos a operar**/
				a=Numeros->valor;
				sacar(&Numeros);
				b=Numeros->valor;
				sacar(&Numeros);
				
				//Obtenemos su operacion
				
				c=pow(b,a);
				
				//La agregamos a la pila
				poner(&Numeros,c);
			}
			
			//Si es buscar funcion
			if(strcmp(elemento,Operadores[5])==0){
				/**Obtenemos el ultimo numero de la pila y busco a cual 
				corresponde, luego lo saco puesto que se va a cambiar**/
				a=Numeros->valor;
				sacar(&Numeros);
				//buscamos
				Datos* imagen=NULL;
				imagen=buscar(resultados,a);
				c=imagen->valor;
				
				
				//La agregamos a la pila
				poner(&Numeros,c);
			}
			
			
			
			
		}
		
		elemento=strtok(NULL,delimitador);
	}
	
	
	
	//Enviamos lo calculado
	if(error==1){
		printf("Error, modulo 0");
	}
	else{
		c=Numeros->valor;
		return c;
	}
	
	return 0;
	
}

