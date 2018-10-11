#include <stdio.h>
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
