//  Incluimos las librerias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// PROTOTIPOS DE FUNCIONES
void leerArchivo(char Archivo[], char Laberinto[30][30], int* y); // Funcion que carga el archivo y lo copia a una matriz
void imprimirLaberinto(char Laberinto[30][30], int y); // Funcion que imprime el laberinto
void analizarLaberinto(char Laberinto[30][30], int* x, int* y, int cy); // Funcion que encuentra las coordenadas del laberinto
void resolverLaberinto(char Laberinto[30][30], int x, int y, int Cy, int* Counter, int* Min, int* CuentaPasos, char Laberinto2[30][30], int Opcion); // Funcion que resuleve el laberinto
void copiarLaberinto(char Laberinto[30][30], char Laberinto2[30][30], int Altura); // Copia de un laberinto a otro
void desplegarResultados(char Laberinto2[30][30], int Totsoluciones, int CamOptimo, int Cy); // Despliega los resultados
// FIN DE PROTOTIPOS DE FUNCIONES

// FUNCION PRINCIPAL
int main(int argc, char *argv[]) {
  // Declaracion de variables
  char Archivo[50], Validacion[] = "-pasos"; // Nombre del archivo y variable para validar la ejecucion del programa
  char Laberinto[30][30]; // Arreglo bidimensional que almacena el laberinto
  char Laberinto2[30][30]; // Arreglo que almacena el laberinto con la solucion optima
  int y; // Altura del laberinto
  int Entradax = 0, Entraday = 0; // Coordenadas de la entrada
  int contador = 0; // Variable para la cantidad de salidas
  int Min = 0; // Variable que almacenará el camino minimo
  int CuentaPasos = 0; // Variable que contará los pasos
  int flag = 0; // Variable para determinar si se imprimen los pasos o no
  // Fin de declarcion de variables
  if((argc < 2 || argc > 3) || (strcmp(argv[1], Validacion) == 0)){ // Validamos la cantidad de parametros y formato
    printf("Error, opcion incorrecta\n");
    printf("Uso: $ laberinto nombre_archivo\n     $ laberinto nombre_archivo -pasos\n");
  }else{
    if(argc == 3 && strcmp(argv[2], Validacion) != 0){ // Validamos que el tercer parametro no sea distinto de -p
      printf("Error, opcion incorrecta\n");
      printf("Uso: $ laberinto nombre_archivo\n     $ laberinto nombre_archivo -pasos\n");
    }else{
      if (argc == 3 && strcmp(argv[2], Validacion) == 0) // En caso de que el usuario quiera los pasos, asignamos 1 a la variable flag
        flag = 1;
      strcpy(Archivo, argv[1]); // Copiamos a la variable Archivo el argumento 1 que se paso por terminal
      leerArchivo(Archivo, Laberinto, &y); // Leemos el archivo
      imprimirLaberinto(Laberinto, y); // Imprimimos el laberinto
      printf("Presione enter para continuar... ");
      getchar(); // Pausa para visualizar el laberinto
      analizarLaberinto(Laberinto, &Entradax, &Entraday, y); // Encontramos las coordenadas de la entrada
      resolverLaberinto(Laberinto, Entradax, Entraday, y, &contador, &Min, &CuentaPasos, Laberinto2, flag); // Resolvemos el laberinto
      desplegarResultados(Laberinto2, contador, Min, y); // Desplegamos los resultados
    }
  }
  return 0;
}
// FIN DE FUNCION PRINCIPAL

// DESARROLLO DE LAS FUNCIONES
void leerArchivo (char Archivo[], char Laberinto[30][30], int* y) { // Funcion que lee el archivo
  FILE* Arch = fopen(Archivo, "r"); // Abrimos el archivo
  int i = 0; // Inicializamos a i
  if (Arch == NULL) { // Verificamos que no haya habido ningun problema al momento de abrir el archivo
    printf("Error, opción incorrecta\nEl archivo no fue encontrado\n");
    printf("Uso: $ laberinto nombre_archivo\n     $ laberinto nombre_archivo -pasos\n");
    exit(0);
  }
  // Copiamos el contenido del archivo a un arreglo bidimensional
  while(!feof(Arch)){ // Mientras que no sea el final del archivo, leemos el laberinto
    fgets(Laberinto[i], 31, Arch);
    i++;
  }
  *y = i; // Obtenemos la altura del laberinto
  fclose(Arch); // Cerramos el archivo
}
void imprimirLaberinto(char Laberinto[30][30], int y){ // Funcion que imprime en pantalla el laberinto
  system("clear"); // Limpiamos pantalla
  int j = 0; // Inicializamos j
  for(int i = 0; i < y-1; i++){ // Establecemos dos ciclos para imprimir el laberinto
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
  for(int i = 0; i < cy-1; i++){ // Recorremos la altura
    j = 0;
    while (Laberinto[i][j] != '\n') { // Recorremos el ancho
      j++;
      if (Laberinto[i][j] == 'E') { // Obtenemos las coordenadas de la Entrada
        *x = i;
        *y = j;
      }
    }
  }
}
void resolverLaberinto(char Laberinto[30][30], int x, int y, int Cy, int* Counter, int* Min, int* CuentaPasos, char Laberinto2[30][30], int Opcion){ // Funcion que resuelve el laberinto
  if (Laberinto[x][y] != 'S') { // Verificamos que no nos encontremos en la salida
    if(Opcion == 1){
      imprimirLaberinto(Laberinto, Cy); // Imprimimos el laberinto
      system("sleep 0.1"); // Hacemos una pausa de 5 milisegundos
    }
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
      resolverLaberinto(Laberinto, x, y+1, Cy, Counter, Min, CuentaPasos, Laberinto2, Opcion);
    }
    if (Laberinto[x-1][y] != '*' && Laberinto[x-1][y] != 'S' && Laberinto[x-1][y] != '.' && Laberinto[x-1][y] != 'E') { // Condicion para que se mueva hacia arriba
      Laberinto[x-1][y] = '.';
      (*CuentaPasos)++;
      resolverLaberinto(Laberinto, x-1, y, Cy, Counter, Min, CuentaPasos, Laberinto2, Opcion);
    }
    if (Laberinto[x+1][y] != '*' && Laberinto[x+1][y] != 'S' && Laberinto[x+1][y] != '.' && Laberinto[x+1][y] != 'E') { // Condicion para que se mueva hacia abajo
      Laberinto[x+1][y] = '.';
      (*CuentaPasos)++;
      resolverLaberinto(Laberinto, x+1, y, Cy, Counter, Min, CuentaPasos, Laberinto2, Opcion);
    }
    if (Laberinto[x][y-1] != '*' && Laberinto[x][y-1] != 'S' && Laberinto[x][y-1] != '.' && Laberinto[x][y-1] != 'E') { // Condicion para que se mueva a la izquierda
      Laberinto[x][y-1] = '.';
      (*CuentaPasos)++;
      resolverLaberinto(Laberinto, x, y-1, Cy, Counter, Min, CuentaPasos, Laberinto2, Opcion);
    }
    if(Laberinto[x][y] != 'E'){ // Verificamos que no nos encontremos en la salida para comenzar a retroceder
      Laberinto[x][y] = ' '; // Limpiamos la casilla
      (*CuentaPasos)--;
    }
    if(Opcion == 1){
      imprimirLaberinto(Laberinto, Cy); // Imprimimos el laberinto
      system("sleep 0.1"); // Pausamos durante 5 milisegundos
    }
  }
} // funcion que resuelve el laberinto
void copiarLaberinto(char Laberinto[30][30], char Laberinto2[30][30], int Altura){ // Funcion que copia de una matriz a otra
  int i = 0; // Copiamos el laberinto a una nueva matriz
  while (i < Altura) {
    strcpy(Laberinto2[i], Laberinto[i]);
    i++;
  }
}
void desplegarResultados(char Laberinto2[30][30], int Totsoluciones, int CamOptimo, int Cy) { // Funcion que despliega los resultados obtenidos
  imprimirLaberinto(Laberinto2, Cy); // Imprime laberinto
  printf("Camino optimo: %d pasos.\n", CamOptimo);
  printf("Se encontraron %d caminos de salida.\n", Totsoluciones);
}
// FIN DE DESARROLLO DE FUNCIONES
