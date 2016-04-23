#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>

typedef struct tCell{
	int payload;
	struct tCell *next;
}Cell;

Cell* agrega (Cell *root, int numero){
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
void ImprimeLista (Cell *root){
	printf("Katya Rules---->");
	while((root=(Cell*)root->next) !=NULL){
		printf("%d ->",root->payload);
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
Cell limpiar(Cell *celda){
	while(celda->next !=NULL)
		pop(celda);
	return *celda;
}
Cell menu(Cell *root){
	int opcion=0;
	bool ev=false;
	int num;
	while(ev==false){
		printf("Dame una opción; \n 0: Agrega nodo \n 1: Borra ultimo nodo \n 2: Imprime Lista \n 3: Salir\n");
		scanf("%d", &opcion);
		if(opcion==0){
			printf("Dame un numero\n");
			scanf("%d", &num);
			agrega(root, num);

		} else if(opcion ==1){
			pop(root);
		} else if(opcion == 2){
			ImprimeLista(root);
		} else if(opcion ==3){
			limpiar(root);
			ev=true;
		}else {
			printf("Ingresa una opcion correcta \n");
		}
	}
	return *root;
}

int main(int argc, char* argv[]){
	Cell *root;
	root = (Cell*)malloc(sizeof(Cell));
	root->next=NULL;
	root->payload = 0;
	menu(root);
	return 0;
}