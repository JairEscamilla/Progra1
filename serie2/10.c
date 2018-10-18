// Incluyo las librerias
#include <stdio.h>
// Prototipos de funciones
void valida(long, int*, int[], int*, int*, int*);
void calculo(int, int, int, int, int, int, int*);
// Funcion principal
int main(void){
  long F1, F2;
  int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int Flag = 0;
  int d, m, a;
  int dd, mm, aa;
  int Dt = 0;
  do {
    printf("Ingresar fecha 1(DDMMAAAA):");
    scanf("%ld", &F1);
    valida(F1, &Flag, dias, &d, &m , &a);
    printf("Ingresar fecha 2(DDMMAAAA):");
    scanf("%ld", &F2);
    valida(F2, &Flag, dias, &dd, &mm, &aa);
    if (aa < a) {
      Flag = 1;
    }
    if (aa == a) {
      if (mm < m) {
        Flag = 1;
      }
    }

    if (aa == a) {
      if (mm == m) {
        if (dd < d) {
          Flag = 1;
        }
      }
    }
    if (Flag == 1) {
      printf("Debes ingresar una fecha valida\n");
    }
  } while(Flag == 1);
  calculo(d, m, a, dd, mm, aa, &Dt);
  printf("Los dias entre una fecha y otra son: %d\n dias", Dt);
}

void valida(long Fecha, int* Flag, int dias[], int* d, int* m, int*a){
  *d = Fecha/1000000;
  *m = (Fecha%1000000)/10000;
  *a = Fecha%10000;
  if ((*m >= 1 && *m <= 12) && (*d > 0 && *d <= dias[*m-1])) {
    *Flag = 0;
  }else{
    *Flag = 1;
  }
}

void calculo(int d, int m, int a, int dd, int mm, int aa, int*dt){
  int aux1 = (aa*365)+(mm-1)*30+dd;
  int aux2 = (a*365)+(m-1)*30+d;
  *dt = aux1 - aux2;
  if (m == 2) {
    *dt = *dt -2;
  }
}
