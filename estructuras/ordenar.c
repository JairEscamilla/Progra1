#include <stdio.h>
#include <stdlib.h>
// Defino la estructura
typedef struct defDato{
  int dato;
  struct defDato* siguiente;
}TipoDato;
// Prototipos de funciones
void agregar(TipoDato**, int);
void imprimir(TipoDato*);
void ordenar(TipoDato**);
// Funcion principal
int main(){
  TipoDato* Lista = NULL;
  int num;
  printf("Ingresar numeros, letra para terminar: ");
  while (scanf("%d", &num) == 1) {
    agregar(&Lista, num);
  }
  ordenar(&Lista);
  imprimir(Lista);
}
// Desarrollo de las funciones
void agregar(TipoDato** lista, int numero){
  TipoDato* temp = (TipoDato*)malloc(sizeof(TipoDato));
  temp->dato = numero;
  temp->siguiente = NULL;
  TipoDato* temp2 = *lista;
  if (*lista == NULL) {
    *lista = temp;
  }else{
    while (temp2->siguiente != NULL) {
      temp2 = temp2->siguiente;
    }
    temp2->siguiente = temp;
  }
}
void imprimir(TipoDato* Lista){
  TipoDato* aux = Lista;
  while (aux != NULL) {
    printf("%d, ", aux->dato);
    aux = aux->siguiente;
  }
}
void ordenar(TipoDato** Lista){
  TipoDato* aux, *aux2, *aux3;
  aux = *Lista;
  aux2 = *Lista;
  if(aux->siguiente != NULL){
    aux3 = aux->siguiente;
  }
  while (aux != NULL) {
    if(aux->siguiente != NULL && aux->dato > aux3->dato){
        aux->siguiente 
    }
    aux = aux->siguiente;
  }
    aux = aux->siguiente;
    ordenar(&aux);
  }
}
