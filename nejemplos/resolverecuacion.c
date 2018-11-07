#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
  char NombreArchivo[20];
  int a, b, c, i;
  float R1, R2;
  FILE* Archivo;
  printf("Dame el nombre del archivo con las ecuaciones: ");
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo, "rt");
  if (Archivo == NULL) {
    printf("No existe el archivo. Fin del programa\n");
    exit(0);
  }
  for(i = 1; i <= 5; i++){
    fscanf(Archivo, "%d, %d, %d", &a, &b, &c);
    R1 = (-b+sqrt(b*b-4*a*c)/(2*a));
    R2 = (-b-sqrt(b*b-4*a*c)/(2*a));
    printf("Para %dx^2+%dx+%d= 0, R1 = %.2f, R2 = %.2f\n", a, b, c, R1, R2);
  }
  fclose(Archivo);
}
