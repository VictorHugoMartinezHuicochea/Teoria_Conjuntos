#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(){
    int i,Cifr,May;
    int n,k,Ub,P;
    char *Res;
    long long int N;

    char Frase[100];

    //ingresamos la cadena de caraceteres maximo 100
    printf("Bienvenido al codificador, por favor digite su frase:\n");
    fgets(Frase,sizeof(Frase),stdin);
	
    //Parte para leer datos
    printf("\nPor favor digite un numero n:");
    scanf("%d",&n);
    printf("\nPor favor digite un numero k:");
    scanf("%d",&k);
    
    
    //Encontramos el tamano de la frase
    int tamano=strlen(Frase);

    //El alfabeto guarda todas las posiciones de las letras
    char Alfabeto[40]="abcdefghijklmnopqrstuvwxyz0123456789";
    
    //Recorremos el array de la frase
    for(i=0;i<tamano;i++){
        printf("Caracter a Verificar: %c \\\\ \n",Frase[i]);
        //Reseteamos los indicadores
        May=0;
        Cifr=0;

        //Vemos si es un elemento del alfabeto
        if(isalpha(Frase[i])){
            Cifr=1;
            //Identificamos si es mayuscula o no
            if(isupper(Frase[i])){
                May=1;
                //Lo convertimos a minuscula
                Frase[i]=tolower(Frase[i]);
            }
        }

        //Vemos si es digito
        if(isdigit(Frase[i])){
            Cifr=1;
        }

        //Si se necesita modificar se modifica
        if(Cifr==1){
            //Obtenemos la ubicacion, esto mediante la comparacion del caracter con el alfabeto
            Res=strchr(Alfabeto,Frase[i]);
            Ub=Res-Alfabeto;
            printf("Ubicacion: %d \\\\ \n n=%d \\\\ \nk=%d \\\\\n",Ub+1,n,k);
            //Para concordar con lo asignado
            Ub=(Ub+1)%36;

            //Obtenemos P
            P=((n*Ub)+k)%36;
            printf("P= %d*%d+%d$\\equiv$%d mod 36\\\\\n",n,Ub,k,P);
            //Si P resulta ser negativo, lo devolvemos a los naturales
            if(P<0){
                P=36-P;
            }

            //A la raiz primitiva se eleva a P y se extrae su modulo
            int Cagada;
            N=pow(2,P);
            Cagada=N%37;
            printf("N=$2^{%d}=%d\\equiv %d$ mod 36\\\\\n",P,N,Cagada);
            N=N%37;
            //Se prepara para la siguiente recursion n adquiere el valor de K y K adquiere el valor de la ubicacion intercambiada
            n=k;
            k=N;

            //Si N=0 se vuelve 37
            if(N==0){
                N=37;
            }

            //El elemento del array se modifica con su alfabeto correspondiente en el cifrado
            Frase[i]=Alfabeto[N-1];

            printf("Nuevos: n=k=%d,  k=N=%d\\\\\n",n,k);
            printf("Caracter final: %c \\\\ \n",Frase[i]);
            if(May==1 && isalpha(Frase[i])){
                printf("Como antes la letra era may\\\'uscula, se pone en may\\\'uscula \\\\\n\n");
            }
        }
        else{
            printf("Como no es un car\\\'acter alfanum\\\'erico, entonces se deja igual \\\\\n");
        }


        //Convertimos a Mayusculas
        //Si resulta que el caracter era mayuscula y al cambiar sigue siendo leta
        if(May==1 && isalpha(Frase[i])){
            //Se convierte a Mayuscula
            Frase[i]=toupper(Frase[i]);
        }


        printf("\n\n");
    }

    printf("\n\n Frase encriptada: %s\n\n",Frase);

    printf("Fin del programa :D");
    return 0;
}

