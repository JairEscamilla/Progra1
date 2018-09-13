#include <stdio.h>
// Prototipos de funciones
void getNumber(int*);
void compareNumber(int*, int*);
// Funcion principal
int main(void) {
  int Number = 0;
  int Cont = 0;
  do{
    getNumber(&Number);
    compareNumber(&Number, &Cont);
  }while (Number != 0);
  printf("Los numeros leidos distintos de 0 son %d\n", Cont);
}

// Desarrollo de las funciones
void getNumber(int* Number){
  printf("Ingresar numero: ");
  scanf("%d", Number);
}

void compareNumber(int* Number, int* Cont) {
  if (*Number != 0) {
    printf("%d\n", *Number);
    *Cont+= 1;
  }
}
