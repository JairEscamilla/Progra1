#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void read(int*);
void compare(int*, int*, int*, int*, int);
void calcMedia(int, int, float*);
// Funcion principal
int main(void){
  int Par = 0, Impar = 0;
  int Cpar = 0, Cimpar = 0;
  int Num;
  float Media = 0.0;
  for(int i = 0; i < 10; i++){
    read(&Num);
    compare(&Par, &Impar, &Cpar, &Cimpar, Num);
  }
  calcMedia(Impar, Cimpar, &Media);
  printf("Pares:\nSuma de los pares: %d\nCantidad de numeros pares: %d\n", Par, Cpar);
  printf("Impares:\nMedia aritmetica de los impares: %.2f\nCantidad de numeros impares: %d\n", Media, Cimpar);
}

// Desarrollando las funciones
void read(int* Num){
  printf("Ingresar numero: ");
  scanf("%d", Num);
}

void compare(int* Par, int* Impar, int* Cpar, int* Cimpar, int Num){
  if (Num % 2 == 0) {
    *Par += Num;
    *Cpar += 1;
  }else{
    *Impar += Num;
    *Cimpar += 1;
  }
}

void calcMedia(int Sumatoria, int Cantidad, float* Media){
  *Media = (float)Sumatoria/Cantidad;
}
