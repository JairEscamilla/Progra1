#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getCof(int*, int*);
void calc(int, int, float*);
// Funcion principal
int main(void){
  int B = 0, H = 0;
  float R;
  getCof(&B, &H);
  calc(B, H, &R);
  printf("El resultado del area del triangulo es %.2f\n", R);
}
// Desarrollando las funciones
void getCof(int* A, int* B){
  printf("Ingresar base y altura: ");
  scanf("%d %d", A, B);
}

void calc(int A, int B, float* R) {
  *R = (B*A)/2.0;
}
