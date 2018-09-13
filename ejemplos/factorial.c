#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getNum(int*);
void calc(int, int*);
// Funcion principal
int main(void){
  int Num = 0, Res = 1;
  getNum(&Num);
  calc(Num, &Res);
  printf("El factorial es %d\n", Res);
}
// Desarrollando funciones
void getNum(int* Num){
  printf("Ingresar numero: ");
  scanf("%d", Num);
}

void calc(int Num, int* Res) {
  int n = 1;
  while (Num >= 1) {
    n*= Num;
    Num--;
  }
  *Res = n;
}
