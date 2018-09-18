#include <stdio.h>
void alumno(int*);
int main(void){
  int Sum = 0;
  for(int i = 0; i < 20; i++){
    alumno(&Sum);
  }
  printf("El promedio del grupo es %.2f", Sum/60.0);
}

void alumno(int* Sum){
  int c1, c2, c3;
  float prom;
  printf("Ingresar las 3 calificaciones del alumno: ");
  scanf("%d %d %d", &c1, &c2, &c3);
  prom = (c1+c2+c3)/3.0;
  printf("Tu promedio es %.2f\n", prom);
  *Sum += c1+c2+c3;
}
