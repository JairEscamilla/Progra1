#include <stdio.h>
#include <string.h>
int main(){
  FILE* Archivo;
  char Frase[200];
  char Nombre[200];
  printf("Ingresa el nombre del archivo: ");
  gets(Nombre);
  Archivo = fopen(Nombre, "wt");
  printf("Dame tu frase favorita: ");
  gets(Frase);
  fprintf(Archivo, "Tu frase favorita es: \n   %s\n", Frase);
  fclose(Archivo);
}
