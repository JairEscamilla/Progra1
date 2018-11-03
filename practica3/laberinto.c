//  Incluimos las librerias
#include <stdio.h>
#include <string.h>

// PROTOTIPOS DE FUNCIONES
void leerArchivo(char Archivo[], char Laberinto[30][30], int* y);
void imprimirLaberinto(char Laberinto[30][30], int y);
// FIN DE PROTOTIPOS DE FUNCIONES

// FUNCION PRINCIPAL
int main(int argc, char *argv[]) {
  // Declaracion de variables
  char Archivo[50], Validacion[] = "-p";
  char Laberinto[30][30];
  int y;
  // Fin de declarcion de variables
  if((argc < 2 || argc > 3) || (strcmp(argv[1], Validacion) == 0)){ // Validamos la cantidad de parametros y formato
    printf("Error, opcion incorrecta\n");
  }else{
    if(argc == 3 && strcmp(argv[2], Validacion) != 0){ // Validamos que el tercer parametro no sea distinto de -p
      printf("Error, opcion incorrecta\n");
    }else{
      strcpy(Archivo, argv[1]);
      leerArchivo(Archivo, Laberinto, &y); // Leemos el archivo
      imprimirLaberinto(Laberinto, y);
      printf("Presione enter para continuar... ");
      getchar();
      printf("Continuacion del problema\n");
    }
  }


  return 0;
}
// FIN DE FUNCION PRINCIPAL

// DESARROLLO DE LAS FUNCIONES
void leerArchivo (char Archivo[], char Laberinto[30][30], int* y) { // Funcion que lee el archivo
  FILE* Arch = fopen(Archivo, "r+b");
  char c; // Caracter que vamos a ir leyendo
  int i = 0, j = 0;
  // Copiamos el contenido del archivo a un arreglo bidimensional
  while(!feof(Arch)){
    fread(&c, sizeof(char), 1, Arch);
    Laberinto[j][i] = c;
    if (c == '\n') {
      j++;
      i = -1;
    }
    i++;
  }

  *y = j;
  fclose(Arch);
}

void imprimirLaberinto(char Laberinto[30][30], int y){
  int j = 0;
  for(int i = 0; i < y-1; i++){
    j = 0;
    while (Laberinto[i][j] != '\n') {
      printf("%c", Laberinto[i][j]);
      j++;
    }
    printf("\n");
  }
}
// FIN DE DESARROLLO DE FUNCIONES
