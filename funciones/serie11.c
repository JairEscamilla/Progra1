#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void read(int*);
void may(int, int*);
// Funcion principal
int main(void){
  int Num;
  int May = -1;
  do {
    read(&Num);
    if (Num <= 0 && Num != -99) {
      printf("Debes de ingresar valores positivos distintos de 0\n");
    }else{
      may(Num, &May);
    }
  } while(Num != -99);
  printf("El numero mayor de la serie fue %d\n", May);
}

// Desarrollando las funciones
void read(int* Num){
  printf("Ingresar numero: ");
  scanf("%d", Num);
}

void may(int Num, int* May){
  if (Num > *May) {
    *May = Num;
  }
}
