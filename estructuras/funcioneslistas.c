#include <stdlib.h>
#include <stdio.h>
typedef struct defElemento{
  int dato;
  struct defElemento* siguiente;
}TipoElemento;
void InsertaInicio(TipoElemento** Inicio, int numero);
void imprime(TipoElemento* Inicio);
void BorrarLista(TipoElemento* Inicio);
void InsertaDerecha(TipoElemento**, int);
float calcularPromedio(TipoElemento*);
int buscar(int, TipoElemento*);

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

int buscar(int numero, TipoElemento* Inicio){
  TipoElemento* aux = Inicio;
  int flag = 0;
  while (aux != NULL) {
    if(aux->dato == numero){
      flag = 1;
      aux = NULL;
    }else
      aux = aux->siguiente;
  }
  return flag;
}
float calcularPromedio(TipoElemento* Lista){
  TipoElemento* Aux = Lista;
  float counter = 0, counter2 = 0;
  float promedio;
  while (Aux != NULL) {
    counter += Aux->dato;
    counter2++;
    Aux = Aux->siguiente;
  }
  promedio = counter/counter2;
  return promedio;
}

void InsertaDerecha(TipoElemento** Inicio, int numero) {
  TipoElemento* temp;
  TipoElemento* temp2;
  temp = (TipoElemento*)malloc(sizeof(TipoElemento));
  temp->dato = numero;
  temp->siguiente = NULL;
  if (*Inicio != NULL) {
    temp2 = *Inicio;
    while (temp2->siguiente != NULL) {
      temp2 = temp2->siguiente;
    }
    temp2->siguiente = temp;
  }else
    *Inicio = temp;
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
  int num;
  printf("Inserte numeros, letra para terminar: ");
  while (scanf("%d", &valor) == 1) {
    InsertaInicio(&lista, valor);
  }
  printf("Los valores introducidos son: \n");
  imprime(lista);
  printf("\n");
  printf("El promedio es %f\n", calcularPromedio(lista));
  printf("Ingresar numero a buscar: ");
  __fpurge(stdin);
  scanf("%d", &num);
  if (buscar(num, lista)) {
    printf("El numero si se encuentra en la lista\n");
  }else{
    printf("El numero NO se encuentra en la lista\n");
  }
  BorrarLista(lista);
}
