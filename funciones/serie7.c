#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getValues(int*, int*, int*);
void exchangeValues(int*, int*, int*);
// Funcion principal
int main(void){
  int A, B, C;
  getValues(&A, &B, &C);
  exchangeValues(&A, &B, &C);
  printf("A = %d\nB = %d\nC = %d\n ", A, B, C);
}

// Desarrollando las funciones
void getValues(int* A, int* B, int*  C){
    printf("Ingresar valores de A, B, C: ");
    scanf("%d %d %d", A, B, C);
}

void exchangeValues(int* A, int* B, int* C) {
  int Aux = *B, Aux2 = *C;
  *B = *A;
  *C = Aux;
  *A = Aux2;
}
