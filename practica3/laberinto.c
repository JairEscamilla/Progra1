//  Incluimos las librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// PROTOTIPOS DE FUNCIONES
void leerArchivo(char Archivo[], char Laberinto[30][30], int* y);
void imprimirLaberinto(char Laberinto[30][30], int y);
void analizarLaberinto(char Laberinto[30][30], int* x, int* y, int cy);
void resolverLaberinto(char Laberinto[30][30], int x, int y, int Cy, int* Counter);
// FIN DE PROTOTIPOS DE FUNCIONES

// FUNCION PRINCIPAL
int main(int argc, char *argv[]) {
  // Declaracion de variables
  char Archivo[50], Validacion[] = "-p";
  char Laberinto[30][30];
  int y;
  int Entradax = 0, Entraday = 0;
  int contador = 0;
  // Fin de declarcion de variables
  if((argc < 2 || argc > 3) || (strcmp(argv[1], Validacion) == 0)){ // Validamos la cantidad de parametros y formato
    printf("Error, opcion incorrecta\n");
  }else{
    if(argc == 3 && strcmp(argv[2], Validacion) != 0){ // Validamos que el tercer parametro no sea distinto de -p
      printf("Error, opcion incorrecta\n");
    }else{
      strcpy(Archivo, argv[1]);
      leerArchivo(Archivo, Laberinto, &y); // Leemos el archivo
      imprimirLaberinto(Laberinto, y); // Imprimimos el laberinto
      printf("Presione enter para continuar... ");
      getchar(); // Pausa para visualizar el laberinto
      printf("Continuacion del problema\n");
      analizarLaberinto(Laberinto, &Entradax, &Entraday, y);
      system("clear");
      printf("Continuamos con el desarrollo del laberinto\n");
      resolverLaberinto(Laberinto, Entradax, Entraday, y, &contador);
      printf("Contador %d\n", contador);
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
void imprimirLaberinto(char Laberinto[30][30], int y){ // Funcion que imprime en pantalla el laberinto
  system("clear");
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
void analizarLaberinto(char Laberinto[30][30], int* x, int* y, int cy){ // Funcion que obtiene las coordenadas de la entrada
  int j = 0;
  for(int i = 0; i < cy-1; i++){
    j = 0;
    while (Laberinto[i][j] != '\n') {
      j++;
      if (Laberinto[i][j] == 'E') {
        *x = i;
        *y = j;
      }
    }
  }
}
void resolverLaberinto(char Laberinto[30][30], int x, int y, int Cy, int* Counter){

  if (Laberinto[x][y] != 'S') {
    imprimirLaberinto(Laberinto, Cy);
    system("sleep 0.5");
    if (Laberinto[x][y+1] != '*' && Laberinto[x][y+1] != 'S') {
      Laberinto[x][y+1] = '.';
      (*Counter)++;
      resolverLaberinto(Laberinto, x, y+1, Cy, Counter);
    }

    if (Laberinto[x-1][y] != '*' && Laberinto[x-1][y] != 'S') {
      Laberinto[x-1][y] = '.';
      (*Counter)++;
      resolverLaberinto(Laberinto, x-1, y, Cy, Counter);
    }
    


    if(Laberinto[x][y] != 'E')
      Laberinto[x][y] = ' ';
    imprimirLaberinto(Laberinto, Cy);
    system("sleep 0.5");
  }

} // funcion que resuelve el laberinto
// FIN DE DESARROLLO DE FUNCIONES
