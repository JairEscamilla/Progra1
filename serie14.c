#include <stdio.h>
int main(){
  long fecha;
  int dia, mes, anio;
  int rest;
  printf("Ingresar fecha con formato DDMMAA: ");
  scanf("%ld", &fecha);
  dia = fecha/10000;
  rest = fecha%10000;
  mes = rest/100;
  anio = rest%100;

  if (((dia == 31) && (mes%2 != 0 || mes == 8)) || ((dia == 30) && (mes%2 == 0 && mes != 0))) {
    dia = 1;
    mes += 1;
  }else{
    if (dia == 31 && mes == 12) {
      dia = 1;
      mes = 1;
    }else{
      dia++;
    }
  }
  return 0;
}
