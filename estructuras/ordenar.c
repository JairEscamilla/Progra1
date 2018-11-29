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
void ordenar(TipoDato** Inicio){
  TipoDato* anterior, *temp, *siguiente, *temp2;
  if (*Inicio != NULL) {
    anterior = *Inicio;
    temp2 = anterior;
    temp = anterior->siguiente;
    siguiente = temp;
    while (temp != NULL) {
      if(anterior->dato > temp->dato){
        if(*Inicio == anterior){
          *Inicio = temp;
          anterior->siguiente = temp->siguiente;
          temp2 = temp;
          temp->siguiente = anterior;
          temp = anterior->siguiente;
        }else{
          anterior->siguiente = temp->siguiente;
          temp->siguiente = anterior;
          temp2->siguiente = temp;
          temp = anterior->siguiente;
          temp2 = temp2->siguiente;
        }
      }else{
        temp = temp->siguiente;
      }
    }
    ordenar(&siguiente);
  }
}
