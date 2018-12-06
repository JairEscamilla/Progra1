#include <stdio.h>
#include <stdlib.h>
// Definicion de la estructura
typedef struct defDato{
  int numero;
  struct defDato* siguiente;
  struct defDato* anterior;
}TipoDato;
// Prototipos de las funciones
void InsertaInicio(TipoDato**, int);
void InsertaFin(TipoDato**, int);
void Imprimir(TipoDato*);
void ImprimirAlrevez(TipoDato*);
// Funcion principal
int main(){
  TipoDato* Inicio = NULL;
  int numero;
  printf("Ingresar numeros(letra para terminar):\n");
  while (scanf("%d", &numero) == 1) {
    InsertaFin(&Inicio, numero);
  }
  printf("Los numeros en orden son: ");
  Imprimir(Inicio);
  printf("Los numeros volteados son: ");
  ImprimirAlrevez(Inicio);
  return 0;
}

// Desarrollando las funciones
void InsertaInicio(TipoDato** Inicio, int numero){
  TipoDato* temp;
  temp = (TipoDato*)malloc(sizeof(TipoDato));
  temp->numero = numero;
  temp->anterior = NULL;
  temp->siguiente = *Inicio;
  if(*Inicio != NULL)
    (*Inicio)->anterior = temp;
  *Inicio = temp;
}

void InsertaFin(TipoDato** Inicio, int numero){
  TipoDato* temp, *temp2;
  temp = (TipoDato*)malloc(sizeof(TipoDato));
  temp->numero = numero;
  temp->siguiente = NULL;
  if (*Inicio != NULL) {
    temp2 = *Inicio;
    while(temp2->siguiente != NULL)
      temp2 = temp2->siguiente;
    temp2->siguiente = temp;
    temp->anterior = temp2;
  }else{
    temp->anterior = NULL;
    *Inicio = temp;
  }
}
void Imprimir(TipoDato* Inicio){
    TipoDato* temp;
    temp = Inicio;
    while (temp != NULL) {
      printf("%d, ", temp->numero);
      temp = temp->siguiente;
    }
    printf("\n");
}

void ImprimirAlrevez(TipoDato* Inicio){
  TipoDato* temp = Inicio;
  while(temp->siguiente != NULL)
    temp = temp->siguiente;
  while (temp != NULL) {
    printf("%d, ", temp->numero);
    temp = temp->anterior;
  }
  printf("\n");
}
