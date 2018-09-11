#include <stdio.h> // Incluyo libreria
// Declaracion de prototipos
void getNumber(int*);
void comp(int*, int*);
// Funcion principal
int main(void){
  int Number = 0;
  int Mayor = 0;
  do {
    getNumber(&Number);
    comp(&Number, &mMayor);
  } while(Number >= 0);
  printf("El numero mayor es %d\n", Mayor);
}

// Desarrollo de las funciones
void getNumber(int* Numero){
  printf("Ingresar siguiente numero: ");
  scanf("%d", Numero);
}

void comp(int* Number, int* Mayor){
  if (*Number > *Mayor) {
    *Mayor = *Number;
  }
}
