#include <stdio.h> // Incluyo librerias
// Prototipos de funciones
void getValues(int*);
void eval(int*, int*);
// Funcion principal
int main(void){
  int Number, May = -1;
  int Inc = 0;
  for(Inc = 0; Inc < 4; Inc++){
    getValues(&Number);
    eval(&Number, &May);
  }
  printf("El numero mayor es %d\n", May);
}
// Desarrollando las funciones
void getValues(int* Number){
  printf("Ingresar numero: ");
  scanf("%d", Number);
}

void eval(int* Number, int* May){
  if (*Number > *May) {
    *May = *Number;
  }
}
