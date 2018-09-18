#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getDate(long*);
void getDay(long, int*);
void getMonth(long, int*);
void getYear(long, int*);
// Funcion principal
int main(void){
  long Fecha;
  int Dia, Mes, Anio;
  getDate(&Fecha);
  getDay(Fecha, &Dia);
  getMonth(Fecha, &Mes);
  getYear(Fecha, &Anio);
  printf("%d/%d/%d\n", Dia, Mes, Anio);
}

// Desarrollando las funciones
void getDate(long* Fecha){
  printf("Ingresar fecha en formato DDMMAA: ");
  scanf("%ld", Fecha);
}

void getDay(long Fecha, int* Dia) {
  *Dia = Fecha/10000;
}
void getMonth(long Fecha, int* Mes) {
  int R = Fecha%10000;
  *Mes = R/100;
}
void getYear(long Fecha, int* Anio){
  int R = Fecha%10000;
  *Anio = R%100;
}
