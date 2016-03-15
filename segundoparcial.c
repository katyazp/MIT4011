#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <math.h> 


void imprimir(int arreglo[], int tamano){
	int i;
	i=0;
	while (i<tamano)
		{printf("%d ",arreglo[i]);
	printf("\n ");
i=i+1;
}


}
void quickS(int arreglo[],int inicial,int tamano){
	int cero = inicial, ultimo = tamano; 
	int pivote, aux, promedio;
	promedio =(cero+ultimo)/2;
	pivote = arreglo[promedio];
	cero = inicial;
	ultimo = tamano;
	do{
		while(cero<tamano && arreglo[cero]<pivote){
			cero=cero+1;
		}
		while(ultimo > inicial && pivote<arreglo[ultimo]){
			ultimo=ultimo-1;
		}
		if(cero <=ultimo){
			//swap
			aux = arreglo[ultimo];
			arreglo[ultimo]=arreglo[cero];
			arreglo[cero]=aux;
			ultimo=ultimo-1;
			cero=cero+1;
		}
	}while(cero<=ultimo);
	if(inicial<ultimo)
		quickS(arreglo,inicial,ultimo);
	if(tamano>cero)
		quickS(arreglo,cero,tamano);
}
int main (int argc, char* argv[]){
int arreglo [6] = {6,35,4,13,82,1};
int tamano;
tamano= sizeof(arreglo)/ sizeof(int);
quickS(arreglo,0,tamano-1);
imprimir(arreglo, tamano);
printf("\n");
printf("\n Katya Zehenny es la mejor \n");
return 0;
}//endmain

