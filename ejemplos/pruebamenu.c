#include <stdio.h>
#include <string.h>
// Prototipos de funciones
void insertar(float[4][20], char[50][50], int*);
void imprimirPromedios(char[50][50], float[4][20], int);
void buscarAlumnos(float[4][20], char[50][50], int);
// Funcion principal
int main(void){
  int resp = 1;
  int Op;
  char Nombres[50][50];
  float Calificaciones[4][20];
  int Cuenta = 0;
  do {
    printf("1.- Insertar Alumno: \n");
    printf("2.- Imprimir Promedios: \n");
    printf("3.- Buscar Alumno: \n\n");
    printf("Ingresar la opcion que desee: ");
    scanf("%d", &Op);
    switch (Op) {
      case 1:
        insertar(Calificaciones, Nombres, &Cuenta);
        break;
      case 2:
        imprimirPromedios(Nombres, Calificaciones, Cuenta);
        break;
      case 3:
        buscarAlumnos(Calificaciones, Nombres, Cuenta);
        break;
    }
    printf("Desea realizar otra operacion? (1.- Si / 2.- No): ");
    scanf("%d", &resp);
  } while(resp == 1);
}

// Desarrollando las funciones
void insertar(float Calificaciones[4][20], char Nombres[50][50], int* Cuenta){ // Inserta un nuevo alumno
  float Sum = 0;
  printf("Ingresar nombre: ");
  __fpurge(stdin);
  gets(Nombres[*Cuenta]);
  for(int i = 0; i < 3; i++){
    printf("Ingresa la calificacion %d de %s: ", i+1, Nombres[*Cuenta]);
    scanf("%f", &Calificaciones[*Cuenta][i]);
  }
  for(int i = 0; i < 3; i++){
    Sum += Calificaciones[*Cuenta][i];
  }
  Calificaciones[*Cuenta][3] = (float)Sum/3.0;
  (*Cuenta)++;
}

// Funcion que imprime los pronedios de todos los alumnos
void imprimirPromedios(char Nombre[50][50], float Calificaciones[4][20], int Cuenta){
  for(int i = 0; i < Cuenta; i++){
    printf("%s tiene promedio de %.2f\n", Nombre[i], Calificaciones[i][3]);
  }
}

// Funcion que busca un Alumno
void buscarAlumnos(float Calificaciones[4][20], char Nombres[50][50], int Cuenta){
  int Flag = 0;
  char Nombre[50];
  int i = 0;
  printf("Ingresar nombre a buscar: ");
  __fpurge(stdin);
  gets(Nombre);
  while (i < Cuenta) {
    if (strcmp(Nombre, Nombres[i]) == 0) {
      printf("%s tiene promedio de %.2f\n", Nombre, Calificaciones[i][3]);
      Flag = 1;
      break;
    }
    i++;
  }
  if (Flag == 0) {
    printf("El alumno no se encontro\n");
  }
}
