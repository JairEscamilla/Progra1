#include <stdio.h> // Incluyo libreria
// Declaracion de prototipos
void getNumber(int*);
void comp(int*, int*);
// Funcion principal
int main(void){
  int number = 0;
  int mayor = 0;
  do {
    getNumber(&number);
    comp(&number, &mayor);
  } while(number >= 0);
  printf("El numero mayor es %d\n", mayor);
}

// Desarrollo de las funciones
void getNumber(int* numero){
  printf("Ingresar siguiente numero: ");
  scanf("%d", numero);
}

void comp(int* number, int* mayor){
  if (*number > *mayor) {
    *mayor = *number;
  }
}
