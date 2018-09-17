#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void read(int*, int*);
void powd(int, int, int*);
// Funcion principal
int main(void){
  int Num;
  int Potencia;
  int Res = 1;
  read(&Num, &Potencia);
  powd(Num, Potencia, &Res);
  printf("El resultado de la potencia es %d\n", Res);
}

void read(int* Num, int* Potencia){
  printf("Ingresar numero: ");
  scanf("%d", Num);
  printf("Ingresar potencia: ");
  scanf("%d", Potencia);
}

void powd(int Num, int Potencia, int* Res){
  int x = 1;
  while (x <= Potencia) {
    x++;
    *Res *= Num;
  }
}
