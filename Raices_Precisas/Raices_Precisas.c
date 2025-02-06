#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

int main(){

    //Creamos el archivo de txt
    FILE* arch=fopen("raiz.txt","w+b");
    char* Numero = (char*)malloc(20000*3.321);


    mpf_set_default_prec(20000*3.321);
    int n,k,i,comparacion;
    
    //Declaraciones e inicializaciones de variables especiales para presicion
    mpf_t n_especial, condicion, x_1, x_0, aux1, aux2;
    mpf_init2(x_1,20000*3.321);
    mpf_init2(x_0,20000*3.321);
    mpf_init2(aux1,20000*3.321);
    mpf_init2(aux2,20000*3.321);
    mpf_init2(condicion,20000*3.321);
    mpf_init2(n_especial,20000*3.321);

    /* Establecemos la condicion de paro del programa, siendo que se acabara
     * cuando la diferencia entre el anterior y el nuevo sea menor a 
     * <1/(10^20000)*/
    mpf_set_d(aux1,1);
    mpf_set_d(aux2,10);
    mpf_pow_ui(aux2,aux2,20000);
    mpf_div(condicion,aux1,aux2);

    //Aqui metemos a K y N pendiente 
    printf("PROGRAMA PARA CALCULAR RAICES :D\n");
    printf("Ingrese el radicando:\n");scanf("%d",&n);
    printf("Ingrese el indice:\n");scanf("%d",&k);
    
    /*verificar que los numeros ingresados cumple k,n>1
    */
    if(k<1 || n<1){
    	printf("Los parametros ingresados no son validos");
    	exit(-1);
	}



    //Asignacion de variables especiales para inicio de programa
    mpf_set_d(x_1,n);
    mpf_set_d(n_especial,n);
    comparacion=10;

    //for(i=0;i<100000;i++){
    while(comparacion>=0){
        //Guardamos la sucesion anterior
        mpf_set(x_0,x_1);
        i++;
        
        //x_1=(1.0/k)*(x_1*(k-1)+(n/pow(x_1,k-1)));
        //    X^(k-1)
        mpf_pow_ui(aux1,x_1,k-1);
        //    n/aux
        mpf_div(aux1,n_especial,aux1);
        //    x*(k-1)
        mpf_mul_ui(aux2,x_1,k-1);
        //    aux2+aux1
        mpf_add(aux1,aux1,aux2);
        //    aux2=1
        mpf_set_d(aux2,1.0);
        //    1/k
        mpf_div_ui(aux2,aux2,k);
        //    aux2*aux1
        mpf_mul(x_1,aux1,aux2);

        //Obtenemos la resta del anterior con el nuevo
        mpf_sub(aux1,x_0,x_1);

        //Si la diferencia es menor a 1x10^-20000 entonces rompemos el ciclo
        comparacion=mpf_cmp(aux1,condicion);
        
        //Caso IF 10,000 iteraciones
        if(comparacion<0){
            break;
        }


    }


    // Imprimir el resultado
    mp_exp_t exponente;
    mpf_get_str(Numero,&exponente, 10, 20000*3.321, x_1);
    fprintf(arch, "%s\n", Numero);
    fclose(arch);







    //Finalizamos el programa
    gmp_printf("Resultado: %.6Ff\n", x_1);
    printf("\n Fin del programa :D");
    


    return 0;
}


