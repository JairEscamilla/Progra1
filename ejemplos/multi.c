#include <stdio.h>
#include <string.h>
void leer(int[10][4]);
void imprime(int[10][4]);
void promedio(int[10][4]);
int main(void){
  int Calificaciones[10][4];
  leer(Calificaciones);
  imprime(Calificaciones);
}

void leer(int Cal[10][4]){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 3; j++){
      printf("Alumno %d\nCalificacion %d: ", i+1, j+1);
      scanf("%d", &Cal[j][i]);
    }
  }
}

void promedio(int Cal[10][4]){
  int sum = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 3; j++){
      Cal[j][3]= 0;
    }
  }
  for(int i = 0; i < 10; i++){
    sum = 0;
    for(int j = 0; j < 3; j++){
      sum+= Cal[i][j];
    }
    Cal[i][3] = sum/3;
  }
}
void imprime(int Cal[10][4]){
  for(int i = 0; i < 10; i++){
    printf("Alumno %d: ", i+1);
    for(int j = 0; j < 4; j++){
      printf("%d, ", Cal[j][i]);
    }
    printf("\n");
  }
}
void BuscarAlumno(float Notas[], char Nombres[50][50], int cantidad){
  int i = 0;
  char Alumno[50];
  printf("Que alumno buscas? ");
  gets(Alumno);
  while (i < cantidad && strcmp(Alumno, Nombres[i]) == 0) {
    i++;
  }
  if (i == cantidad) {
    printf("El alumno no se encuentra en la lista");
  }else{
    puts(Nombres[i]);
    printf("%f\t %s\t\n", Notas[i], Nombres[i]);
  }
}
