#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
  FILE* Archivo;
  char renglon[200];
  if (argc != 2) {
    printf("Uso:\n text8.exe <archivo-de-texto>\n");
    exit(1);
  }
  Archivo = fopen(argv[1], "rt");
  if (Archivo == NULL) {
    printf("No existe el archivo. Fin del programa");
    exit(0);
  }
  while (fgets(renglon, 100, Archivo) != NULL) {
    renglon[strlen(renglon)-1] = '\0';
    puts(renglon);
  }
  fclose(Archivo);
}
