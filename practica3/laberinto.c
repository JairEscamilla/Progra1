//  Incluimos las librerias
#include <stdio.h>
#include <string.h>

// PROTOTIPOS DE FUNCIONES
void leerArchivo(char Archivo[]);
// FIN DE PROTOTIPOS DE FUNCIONES

// FUNCION PRINCIPAL
int main(int argc, char *argv[]) {
  // Declaracion de variables
  char Archivo[50], Validacion[] = "-p";
  // Fin de declarcion de variables
  if((argc < 2 || argc > 3) || (strcmp(argv[1], Validacion) == 0)){
    printf("Error, opcion incorrecta\n");
  }else{
    if(argc == 3 && strcmp(argv[2], Validacion) != 0){
      printf("Error, opcion incorrecta\n");
    }else{
      strcpy(Archivo, argv[1]);
      leerArchivo(Archivo);
    }
  }


  return 0;
}
// FIN DE FUNCION PRINCIPAL

// DESARROLLO DE LAS FUNCIONES
void leerArchivo (char Archivo[]) { // Funcion que lee el archivo
  FILE* Arch = fopen(Archivo, "r+b");
  char c;
  while (!feof(Arch)) {
    fread(&c, sizeof(char), 1, Arch);
    printf("%c", c);
  }
  fclose(Arch);
}
// FIN DE DESARROLLO DE FUNCIONES
