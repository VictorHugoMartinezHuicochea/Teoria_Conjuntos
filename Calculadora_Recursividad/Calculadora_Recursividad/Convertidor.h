#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Calculadora.h"


long long int Convertidor (char Frase[],int i,int N, Datos* resultados);

//Convierte las i y N en elementos legibles para el programa
long long int Convertidor (char Frase[],int i,int N, Datos* resultados){
	//Cambiaremos la frase, por lo que ocupamos un auxiliar, donde realizaremos los cambios
	char Nueva[100]=" ";
	//Numero nos servira para convertir un int a un char
	char numero[30];
	int op;
	long long int c;
	
	op=0;
	//Obtenemos delimitadores
	char delimitador[]=" ";
	
	//Obtenemos el primer elemento (Debe ser un valor entero)
	char *elemento=strtok(Frase,delimitador);
	
	
	
	//Obtenemos las particiones del string
	while(elemento!=NULL){
		//Si es una i, entonces adquiere el valor actual de i, aqui decimos que detectamos el operador 1
		if(strchr(elemento,'i')){
			op=1;
		}
		//Si es una N adquiere el valor de N, aqui decimos que detectamos el operador 2
		if(strchr(elemento,'N')){
			op=2;
		}
		
		
		switch(op){
			//Si se detecto una i cambiarlo por su valor
			case 1:
				sprintf(numero, "%d", i);
				//Se agrega al auxiliar el numero
				strcat(Nueva,numero);
				break;
			//Si se detecto un N cambiarlo por su valor
			case 2:
				sprintf(numero, "%d", N);
				//Se agrega al auxiliar el numero
				strcat(Nueva,numero);
				break;
			default:
				//Si resulta que no era i o N entonces se agrega el que estaba sin ningun cambio
				strcat(Nueva,elemento);
		}
		//Reiniciamos op
		op=0;
		//Se le agrega el separador
		strcat(Nueva," ");
		//Siguiente particion
		elemento=strtok(NULL,delimitador);
	}

	
	//Calculamos
	c=Calcular(Nueva,resultados);
	
	return c;
	
	
}
