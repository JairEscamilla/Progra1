#include <stdio.h>
#include <string.h>
int main(){
  FILE* Archivo;
  char Frase[200];
  Archivo = fopen("algo.txt", "at");
  printf("Dame tu frase favorita: ");
  gets(Frase);
  fprintf(Archivo, "Tu frase favorita es: \n   %s\n", Frase);
  fclose(Archivo);
}
