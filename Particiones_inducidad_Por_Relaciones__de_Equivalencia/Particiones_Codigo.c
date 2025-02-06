#include <stdio.h>
#include <stdlib.h>


//Creamos nodos para pila
typedef struct Nodo{
	int valor;
	struct Nodo* sig;
}Nodo;


void poner(Nodo **p,int v);

void sacar(Nodo **p);

int vacio(Nodo* p);
 
struct Nodo *Camino=NULL;
struct Nodo *Elementos=NULL;


int main(int argc, char *argv[]) {
	//Declaracion de variables
	int i,j,n,a,b,TamanoParticion,CondicionParo,Pos;
	a=1;
	b=1;
	
	//Pedimos los datos para generar la mariz
	printf("Ingrese el tamaño del conjunto A:\n"); 
	scanf("%d",&n);
	
	int matriz[n][n];
	//llenamos la matriz de 0 para inicializarla
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matriz[i][j]=0;
		}
	}
	i=0;
	
	//Ingreso de las relaciones binarias para deter ingresar (-1,-1)

	while(a>0 || b>0){
			printf("Ingrese las relacion #%d separadas por espacio(digite [-1 -1] para acabar): \n",i+1); 
			scanf("%i %i",&a,&b);
			printf("a= %i, b=%i\n",a,b);
			if(a>0 ||b>0){
				matriz[a-1][b-1]+=1;
			}
			i++;
	}
	
	
	//Hago simetria para evitar bugs
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matriz[i][j]!=0){
				matriz[j][i]=matriz[i][j];
			}
		}
	}

	/*Una vez obtenida nuestra matriz de adyecencia
	empezamos el algoritmo de particionamiento, iniciando
	por crear una variable para almacenar los lugares por donde pasamos*/
	int Revision[n];
	for(i=0;i<n;i++){
		Revision[i]=0;
	}
	
	//Nuestros indices y condiciones de paro
	int I=0;	
	CondicionParo=0;
	
	
	printf("El particionamiento de A es: \n");
	
	
	//Iniciamos el particionamiento
	while(CondicionParo==0){
		CondicionParo=1;
		
		/*Si el elemento no ha sido visitado (Es decir,
		que no se encuentra en una particion) Lo añadimos,
		ademas creamos un camino del que fuimos recorriendo y
		lo marcamos como visitado*/
		if(Revision[I]==0){
			Revision[I]=1;
			poner(&Elementos,I);
			poner(&Camino,I);
			TamanoParticion=1;
			Pos=I;
		
		/*Puede ser que el camino tenga otras vias,
		se debe corroborar que todos los caminos fueron
		visitados*/
		while(vacio(Camino)!=1){
			
			for(j=0;j<n;j++){
				/*Si esta conectado, no es el mismo y no ha sido visitado*/
				if(matriz[Pos][j]!=0 && Pos!=j && Revision[j]==0){
					/*Marcamos el lugar a visitar como revisado,
					lo agregamos a la particion y al camino*/
					Revision[j]=1;
					poner(&Elementos,j);
					poner(&Camino,j);
					TamanoParticion+=1;
					
					/*Seguimos al nuevo camino y reseteamos j
					para que siga el camino desde el inicio*/
					Pos=j;
					j=-1;
				}
			}
			
			/*Si acabamos el camino, regresamos para 
			asegurarnos que no omitimos otro camino*/
			if(vacio(Camino)!=1){
				sacar(&Camino);
				/*Nuestra Posicion cambia al camino anterior*/
				if(vacio(Camino)!=1){
					Pos=Camino->valor;
				}
			}
		}
		
		//Imprimimos la particion
		printf("{");
		for(i=0;i<TamanoParticion;i++){
			printf("%d, ",Elementos->valor+1);
			sacar(&Elementos);
		}
		printf("},");

		}
					
		/*Verificamos que todos los caminos
		hayan sido visitados, en caso de que no
		repetimos hasta visitarlos a todos*/
		for(j=0;j<n;j++){
			if(Revision[j]==0){
				CondicionParo=0;
			}
		}
		I+=1;
	}
	
	
	
	
	
	
	
	//Finalizamos
	printf("\n Fin del programa :D");
	
	
	
	
	
	
	
	return 0;
}



//Operaciones de pilas
void poner(Nodo**p, int v){
	Nodo* nuevo=(Nodo*)malloc(sizeof(Nodo));
	nuevo->valor=v;
	nuevo->sig=*p;
	*p=nuevo;
}

void sacar(Nodo**p){
	Nodo* aux=*p;
	int ret=aux->valor;
	
	*p=aux->sig;
	free(aux);
}

int vacio(Nodo* p){
	return p==NULL;
}



