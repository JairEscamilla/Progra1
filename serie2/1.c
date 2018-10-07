#include <stdio.h>
// Prototipos de funciones
void calcula(int[]);
void despliega(int[]);
// Funcion principal
int main(void){
  int Cuadrados[99];
  calcula(Cuadrados);
  despliega(Cuadrados);
}

// Desarrollando las funciones

void calcula(int Cuadrados[]){
  for(int i = 1; i <= 100; i++){
    Cuadrados[i-1] = i*i; // Calculamos todos los cuadrados
  }
}

void despliega(int Cuadrados[]){
  // Dibujando el encabezado de la tabla
  for(int i = 0; i< 43; i++){
    printf("*");
  }
  printf("\n");
  printf("*       Numero       *     Cuadrado       *\n");
  for(int i = 0; i< 43; i++){
    printf("*");
  }
  // Fin del encabezado

  printf("\n");
  // Dibujando el cuerpo de la tabla
  for(int i = 0; i < 100; i++){
    printf("*%10d          *%10d          *\n", i+1, Cuadrados[i]);
    for(int i = 0; i< 43; i++){
      printf("*");
    }
    printf("\n");
  }

  // Fin del cuerpo de la tabla
  printf("\n");
}
