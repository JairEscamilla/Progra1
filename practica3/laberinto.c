//  Incluimos las librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// PROTOTIPOS DE FUNCIONES
void leerArchivo(char Archivo[], char Laberinto[30][30], int* y);
void imprimirLaberinto(char Laberinto[30][30], int y);
void analizarLaberinto(char Laberinto[30][30], int* x, int* y, int cy);
void resolverLaberinto(char Laberinto[30][30], int x, int y, int Cy, int* Counter, int* Min, int* CuentaPasos, char Laberinto2[30][30]);
void copiarLaberinto(char Laberinto[30][30], char Laberinto2[30][30], int Altura);
void desplegarResultados(char Laberinto2[30][30], int Totsoluciones, int CamOptimo, int Cy);
// FIN DE PROTOTIPOS DE FUNCIONES

// FUNCION PRINCIPAL
int main(int argc, char *argv[]) {
  // Declaracion de variables
  char Archivo[50], Validacion[] = "-p"; // Nombre del archivo y variable para validar la ejecucion del programa
  char Laberinto[30][30]; // Arreglo bidimensional que almacena el laberinto
  char Laberinto2[30][30]; // Arreglo que almacena el laberinto con la solucion optima
  int y; // Altura del laberinto
  int Entradax = 0, Entraday = 0; // Coordenadas de la entrada
  int contador = 0; // Variable para la cantidad de salidas
  int Min = 0; // Variable que almacenará el camino minimo
  int CuentaPasos = 0; // Variable que contará los pasos
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
      resolverLaberinto(Laberinto, Entradax, Entraday, y, &contador, &Min, &CuentaPasos, Laberinto2);
      desplegarResultados(Laberinto2, contador, Min, y);
    }
  }
  return 0;
}
// FIN DE FUNCION PRINCIPAL

// DESARROLLO DE LAS FUNCIONES
void leerArchivo (char Archivo[], char Laberinto[30][30], int* y) { // Funcion que lee el archivo
  FILE* Arch = fopen(Archivo, "r");
  char c; // Caracter que vamos a ir leyendo
  int i = 0, j = 0;
  // Copiamos el contenido del archivo a un arreglo bidimensional
  while(!feof(Arch)){
    fread(&c, sizeof(char), 1, Arch);
    Laberinto[j][i] = c;
    if (c == '\n') {
      Laberinto[j][i] = '\n';
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
void copiarLaberinto(char Laberinto[30][30], char Laberinto2[30][30], int Altura){
  int i = 0;
  while (i < Altura) {
    strcpy(Laberinto2[i], Laberinto[i]);
    i++;
  }
}
void desplegarResultados(char Laberinto2[30][30], int Totsoluciones, int CamOptimo, int Cy) {
  imprimirLaberinto(Laberinto2, Cy);
  printf("Camino optimo: %d pasos.\n", CamOptimo);
  printf("Se encontraron %d caminos de salida.\n", Totsoluciones);
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
void resolverLaberinto(char Laberinto[30][30], int x, int y, int Cy, int* Counter, int* Min, int* CuentaPasos, char Laberinto2[30][30]){ // Funcion que resuelve el laberinto
  if (Laberinto[x][y] != 'S') { // Verificamos que no nos encontremos en la salida
    imprimirLaberinto(Laberinto, Cy); // Imprimimos el laberinto
    system("sleep 0.1"); // Hacemos una pausa de 5 milisegundos
    if(Laberinto[x+1][y] == 'S' || Laberinto[x][y+1] == 'S' || Laberinto[x-1][y] == 'S' || Laberinto[x][y-1] == 'S'){ // Contamos las veces que encontramos la salida
      (*Counter)++;
      if(*CuentaPasos < *Min || *Counter == 1){
        *Min = *CuentaPasos;
        copiarLaberinto(Laberinto, Laberinto2, Cy);
      }
    }
    if (Laberinto[x][y+1] != '*' && Laberinto[x][y+1] != 'S' && Laberinto[x][y+1] != '.' && Laberinto[x][y+1] != 'E') { // Condicion para que se mueva a la derecha
      Laberinto[x][y+1] = '.';
      (*CuentaPasos)++;
      resolverLaberinto(Laberinto, x, y+1, Cy, Counter, Min, CuentaPasos, Laberinto2);
    }
    if (Laberinto[x-1][y] != '*' && Laberinto[x-1][y] != 'S' && Laberinto[x-1][y] != '.' && Laberinto[x-1][y] != 'E') { // Condicion para que se mueva hacia arriba
      Laberinto[x-1][y] = '.';
      (*CuentaPasos)++;
      resolverLaberinto(Laberinto, x-1, y, Cy, Counter, Min, CuentaPasos, Laberinto2);
    }
    if (Laberinto[x+1][y] != '*' && Laberinto[x+1][y] != 'S' && Laberinto[x+1][y] != '.' && Laberinto[x+1][y] != 'E') { // Condicion para que se mueva hacia abajo
      Laberinto[x+1][y] = '.';
      (*CuentaPasos)++;
      resolverLaberinto(Laberinto, x+1, y, Cy, Counter, Min, CuentaPasos, Laberinto2);
    }
    if (Laberinto[x][y-1] != '*' && Laberinto[x][y-1] != 'S' && Laberinto[x][y-1] != '.' && Laberinto[x][y-1] != 'E') { // Condicion para que se mueva a la izquierda
      Laberinto[x][y-1] = '.';
      (*CuentaPasos)++;
      resolverLaberinto(Laberinto, x, y-1, Cy, Counter, Min, CuentaPasos, Laberinto2);
    }
    if(Laberinto[x][y] != 'E'){ // Verificamos que no nos encontremos en la salida para comenzar a retroceder
      Laberinto[x][y] = ' '; // Limpiamos la casilla
      (*CuentaPasos)--;
    }
    imprimirLaberinto(Laberinto, Cy); // Imprimimos el laberinto
    system("sleep 0.1"); // Pausamos durante 5 milisegundos
  }
} // funcion que resuelve el laberinto
// FIN DE DESARROLLO DE FUNCIONES
