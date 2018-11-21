#include <stdio.h>
#include <stdlib.h>
typedef struct defDato{
  int dato;
  struct defDato* siguiente;
}TipoDato;

void ordenar(TipoDato**, int);
void imprimir(TipoDato*);

int main(){
  int num;
  TipoDato* lista = NULL;
  printf("Ingresar un numero, letra para terminar: ");
  while (scanf("%d", &num) == 1) {
    ordenar(&lista, num);
  }
  imprimir(lista);
}

void ordenar(TipoDato** Lista, int numero){
  TipoDato* aux, *aux2, *anterior;
  aux = (TipoDato*)malloc(sizeof(TipoDato));
  aux->dato = numero;
  aux->siguiente = NULL;
  aux2 = *Lista;
  int Flag = 0;
  if (*Lista == NULL) {
    *Lista = aux;
  }else{
    while (aux2 != NULL && Flag == 0) {
      if (aux2->siguiente == NULL && numero > aux2->dato){
        aux2->siguiente = aux;
        Flag = 1;
      }
      if(aux2->siguiente == NULL && numero < aux2->dato){
         aux->siguiente = aux2;
         Flag = 1;
       }
       if(aux2 == *Lista && numero < aux2->dato){
         aux->siguiente = aux2;
         *Lista = aux;
         Flag = 1;
       }
      anterior = aux2;
      aux2 = aux2->siguiente;
      if(anterior->dato < numero && numero < aux2->dato){
        anterior->siguiente = aux;
        aux->siguiente = aux2;
        Flag = 1;
      }
    }
  }
}
void imprimir(TipoDato* Lista){
  TipoDato* temp = Lista;
  while (temp != NULL) {
    printf("%d, ", temp->dato);
    temp = temp->siguiente;
  }
  printf("\n");
}
