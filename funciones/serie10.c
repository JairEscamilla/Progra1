#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void pares(int*);
void impares(int*);
// Funcion principal
int main(void){
  int Pares = 0, Impares = 0;
  pares(&Pares);
  impares(&Impares);
  printf("La suma de los pares es %d\n", Pares);
  printf("La suma de los impares es %d\n", Impares);
}
// Desarrollando las funciones
void pares(int* Pares){
  for(int i = 1; i <= 200; i++){
    if (i%2 == 0) {
      *Pares += i;
    }
  }
}

void impares(int* Impares){
  for(int i = 1; i <= 200; i++){
    if (i%2!= 0) {
      *Impares += i;
    }
  }
}
