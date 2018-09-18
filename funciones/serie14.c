#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getDate(long*);
void getDay(long, int*);
void getMonth(long, int*);
void getYear(long, int*);
void esBisiesto(int, int*);
void tomorrow(int*, int*, int*, int*);
// Funcion principal
int main(void){
  long Fecha;
  int Dia, Mes, Anio;
  int Bisiesto = 0;
  getDate(&Fecha);
  getDay(Fecha, &Dia);
  getMonth(Fecha, &Mes);
  getYear(Fecha, &Anio);
  esBisiesto(Anio, &Bisiesto);
  tomorrow(&Dia, &Mes, &Anio, &Bisiesto);
  printf("La fecha de mañana es %d/%d/%d\n", Dia, Mes, Anio);
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

void esBisiesto(int Anio, int* Bisiesto){
  if (Anio % 4 == 0 && Anio % 100 != 0 || Anio % 400 == 0 ) {
    *Bisiesto = 1;
  }
}

void tomorrow(int* Dia, int* Mes, int* Anio, int* Bisiesto){
  if (*Dia == 30 && *Mes % 2 == 0 && *Mes != 8 && *Mes != 12 && *Mes != 2) {
    *Dia = 1;
    *Mes = *Mes + 1;
  }else{
    if (*Dia == 31 && (*Mes %2 != 0 || *Mes == 8)) {
      *Dia = 1;
      *Mes = *Mes + 1;
    }else{
      if (*Dia == 31 && *Mes == 12) {
        *Dia = 1;
        *Mes = 1;
        *Anio = *Anio + 1;
      }else{
        if (*Dia == 29 && *Mes == 2 && Bisiesto) {
          *Dia = 1;
          *Mes = *Mes + 1;
        }else{
          if (*Dia == 28 && *Mes == 2 && Bisiesto == 0) {
            *Dia = 1;
            *Mes = *Mes + 1;
          }else{
            *Dia = *Dia + 1;
          }
        }
      }
    }
  }
}
