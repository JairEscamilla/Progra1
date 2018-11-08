#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
  FILE* Archivo;
  char NombreArchivo[200], Modo[3], Opcion;
  int a, b, c;
  float R1, R2;
  int MatrizCoef[3][5], i;
  printf("Ingresar nombre del archivo: ");
  gets(NombreArchivo);
  strcpy(Modo, "rt");
  Archivo = fopen(NombreArchivo, "r");
  if (Archivo != NULL) {
    fclose(Archivo);
    do {
      printf("El archivo ya existe, Puedes (s)obreescribir, (a)nadir, (t)erminar\n");
      scanf("%c", &Opcion);
      switch (Opcion) {
        case 'S': case's':
          strcpy(Modo, "wt");
          break;
        case 'A': case 'a':
          strcpy(Modo, "at");
          break;
        case 'T': case 't':
          printf("Saliendo del programa... ");
          exit(0);
          break;
        default:
          printf("Opcion incorrecta. Intenta otra vez.\n");
          Opcion = 'X';
      }
    } while(Opcion == 'X');
  }
  Archivo = fopen(NombreArchivo, Modo);
  if (Archivo == NULL) {
    printf("Error: No fue posible generar el archivo");
    exit(0);
  }
  while(fscanf(Archivo, "%d, %d, %d", &a, &b, &c) == 3){
    //fscanf(Archivo, "%d, %d, %d", &a, &b, &c);
    R1 = (-b+sqrt(b*b-4*a*c)/(2*a));
    R2 = (-b-sqrt(b*b-4*a*c)/(2*a));
    printf("Para %dx^2+%dx+%d= 0, R1 = %.2f, R2 = %.2f\n", a, b, c, R1, R2);
  }
  fclose(Archivo);
}
