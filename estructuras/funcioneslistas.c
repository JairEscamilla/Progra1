#include <stdlib.h>
#include <stdio.h>
typedef struct defElemento{
  int dato;
  struct defElemento* siguiente;
}TipoElemento;
void InsertaInicio(TipoElemento** Inicio, int numero);
void imprime(TipoElemento* Inicio);
void BorrarLista(TipoElemento* Inicio);

void InsertaInicio(TipoElemento** Inicio, int numero){
  TipoElemento* temp;
  temp = (TipoElemento*)malloc(sizeof(TipoElemento));
  temp->dato = numero;
  temp->siguiente = *Inicio;
  *Inicio = temp;
}

void imprime(TipoElemento* Inicio){
  TipoElemento* temp = Inicio;
  while (temp != NULL) {
    printf("%d, ", temp->dato);
    temp = temp->siguiente;
  }
}

void BorrarLista(TipoElemento* Inicio){
  TipoElemento* temp;
  temp = Inicio;
  while (temp != NULL) {
    Inicio = Inicio->siguiente;
    free(temp);
    temp = Inicio;
  }
}

int main(){
  TipoElemento* lista = NULL;
  int valor;
  printf("Inserte numeros, letra para terminar: ");
  while (scanf("%d", &valor) == 1) {
    InsertaInicio(&lista, valor);
  }
  printf("Los valores introducidos son: \n");
  imprime(lista);
  printf("\n");
  BorrarLista(lista);
}
