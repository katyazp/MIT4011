#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>

typedef struct tCell {
	int payload;
	void* next;
}Cell;

Cell* agregar (Cell *root, int numero){
	Cell *nuevo_nodo;
	nuevo_nodo = (Cell*)malloc(sizeof(Cell));
	nuevo_nodo->payload= numero;
	nuevo_nodo->next= NULL;
	Cell *cursor = root;
	while (cursor->next != NULL){
		cursor = (Cell*)cursor->next;
	}
	cursor->next = (void*)nuevo_nodo;
 	return root;
}
Cell *Buscar(Cell *root, int encontrar){
	Cell *X;
	bool nodo= true;
	X =root;
	while((X->payload) != encontrar && nodo== true){
		if(X->next != NULL){
			X= (Cell*) X->next;
		}else{
			nodo= false;
		}
	}
	if(nodo== false){
		printf("No se encontro nodo");
	}else{
		printf("Nodo encontrado");
	}
	return root;
}
Cell *Insertar(Cell *root, int insertar, int nuevonodo){
	Cell *M;
	bool nodo= true;
	M = root;
	while((M->payload) != insertar && nodo == true){
		if(M->next != NULL){	
			M = (Cell*)M->next;
		}else{
			nodo = false;
		}
	}
	if(nodo == false){
		printf("No se encontro nodo\n");
	}else{
		M->payload = nuevonodo;
	}
	return root;
}
Cell *Eliminar (Cell *root, int eliminarnu) {
	Cell *Y;
	Cell *A;
	bool nodo= true;
	Y = root;
	while((Y->payload) != eliminarnu && nodo == true){
		if(Y->next != NULL){
			A = Y;	
			Y = (Cell*)Y->next;
		}else{
			nodo = false;
		}
	}
	if(nodo == false){
		printf("No se encontro nodo");
	}else{
		if(root == Y)
			root = (Cell*)Y->next;
		else
			A->next = Y->next;
		free((void*)Y);
	}
   return root;
}   
void imprimelaLista (Cell *root){
	printf ("x");
	while ((root = ((Cell*)root->next )) !=NULL){
		printf ("-->%d ",  root->payload);
	printf("\n");
	}
}
Cell *pop(Cell *root){
	Cell *cursor = root;
	if(root->next == NULL) return root;
	while(((Cell*)cursor->next)->next != NULL){
		cursor = (Cell*)cursor->next;
	}
	free(cursor->next);
	cursor->next = NULL;
	return root;
}
Cell *erase( Cell *root){
	while(root->next != NULL)
		pop(root);
	return root;
}
int menu(){
		int opcion;
		printf ("Menu: \n 0: Agrega nodo \n 1: Borrar ultimo numero \n 2: Imprime la lista \n 3: Borra \n 4: Editar nodo \n 5: Buscar \n 6: Salir \n Selecciona opción:");
		scanf ("%d", &opcion);
	return opcion;
}

int main(int argc, char* argv[]){
	Cell root;
	int numero_nuevo, eliminarno, nodito, encontrar, insertar;
	root.payload = -1;
	root.next= NULL;
	int opcion = menu();
	while( opcion != 6){
		if(opcion ==0){
			printf ("Dame un numero:");
			scanf ("%d", &numero_nuevo);
			agregar(&root, numero_nuevo);
			printf("\n");
		}else if (opcion ==1){
			pop (&root);
		}else if (opcion ==2){
			imprimelaLista(&root);
		}else if (opcion ==3){
			printf("Que nodo deseas borrar:\n");
			scanf("%d", &eliminarno);
			Eliminar(&root, eliminarno);
			
		}else if (opcion ==4){
			
			printf("Que nodo deseas cambiar:\n");
			scanf("%d", &insertar);
			printf("Que nodo deseas poner\n");
			
			scanf("%d", &nodito);
			Insertar(&root, insertar, nodito);
		}else if (opcion ==5){
			
			printf("Que nodo deseas buscar:\n");
			scanf("%d", &encontrar);
			Buscar(&root, encontrar);
		}
		printf("\n");
		opcion= menu();
	} 
	erase(&root);
	return 0;
}