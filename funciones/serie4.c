#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getNum(int*);
void eval(int*, int*);
// Funcion principal
int main(void){
  int Num = 0, Flag = 1;
  getNum(&Num);
  eval(&Num, &Flag);
  if (Flag)
    printf("No es un numero primo\n");
  else
    printf("Es un numero primo\n");
}

// Desarrollando las funciones
void getNum(int* Numero){
  printf("Ingresar numero: ");
  scanf("%d", Numero);
}

void eval(int* Num, int* Flag){
  for(int i = 1; i < *Num; i++){
    if (*Num % i != 0) {
      *Flag = 0;
      break;
    }
  }
}
