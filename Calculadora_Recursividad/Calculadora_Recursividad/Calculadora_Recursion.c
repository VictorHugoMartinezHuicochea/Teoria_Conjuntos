#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Convertidor.h"
#include "Traductor.h"


int main(){
	//Creamos una ista para guardar resultados
	Datos* resultados=NULL;
	//Esta es para encontrar resultados
	Datos* busqueda=NULL;
	
	/**N es la maxima recursion, inicio es la cantidad de datos base e
	ies para for y saber en que recursion estamos**/
	int N,inicio,i;
	
	//C almacenara el elemento que se genera en f(x)
	long long int c;
	//Parafrase es la que se usara puesto que se modificara
	char ParaFrase[100];
	
	printf("Bienvenido a la funcion recursiva, por favor digite su funcion:\nReglas:\n1_Los numeros deben ser del 0 al 9\n");
	printf("2_Si desea llamar a una recursion anterior se debe usar f(i-r) Ej(sucesion de Fibonacci): f(i-1)+f(i-2) \n");
	printf("3_Operaciones Permitidas: +,-,*,%%,^\nEjemplo: 2(f(i-1)+5)+f(i-1)^2-3\n NOTA:Puede que la recursion escale demasiado, evite salirse del maximo entero long long int\n\n\n	f(i):");
	//ingresamos la cadena de caraceteres maximo 100
	//Parte para leer datos
	char entrada[100];
	scanf("%s",entrada);
	//hacemos la conversion a Notacion polaca inversa y metemos espacios
	char *Polaca=Traduce(entrada);
	char *Frase=Espacios(Polaca);
	
	
	//Pides cuantas bases se tienen
	printf("Por favor, digite cuantos elementos iniciales tendra (el 0 cuenta):\n");
	scanf("%d",&inicio);
	
	//Pides cuantas recursiones se haran
	printf("Por favor, digite hasta que elemento desea llegar\n N=");
	scanf("%d",&N);
	
	//Pides los datos de las bases
	for(i=0;i<inicio;i++){
		printf("Por favor, digite la base\n %d=",i);
		scanf("%lld",&c);
		agregar(&resultados,c,i);	
	}


	/**Iniciamos, i no es igual a 0 puesto que i representa la cantidad de recursiones hechas
	por lo que si se reinicia seria contraproducente**/
	for(i;i<=N;i++){
		//Copiamos la frase original a una "Parafrase" la cual se leera y se modificara en el proceso
		strcpy(ParaFrase,Frase);
		
		/**Convierte la parafrase en una notacion legible para la calculadora
		a su vez que la funcion Convertidor envia a funcion Calculadora para calcular el resultado**/
		c=Convertidor(ParaFrase,i,N,resultados);
		
		
		//Se agrega a la lista
		agregar(&resultados,c,i);	
	}
	
	
	//Buscamos el elemento N-esimo e imprimimos resultados
	for(i=0;i<=N;i++){
		busqueda=buscar(resultados,i);
		printf("En N=%d, el valor obtenido fue %lld\n",i,busqueda->valor);
	}
	
	
	return 0;
}
