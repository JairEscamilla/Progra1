#include <stdlib.h>
typedef struct defElemento{
  int dato;
  struct defElemento* siguiente;
}TipoElemento;
void InsertaInicio(TipoElemento** Inicio, int numero);

void InsertaInicio(TipoElemento** Inicio, int numero){
  TipoElemento* temp;
  temp = (TipoElemento*)malloc(sizeof(TipoElemento));
  temp->dato = numero;
  temp->siguiente = *Inicio;
  *Inicio = temp;
}
