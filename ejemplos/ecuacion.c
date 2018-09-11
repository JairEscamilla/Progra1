#include <stdio.h>
#include <math.h> // Incluyo la libreria
// Prototipos de funciones
void getCof(int*, int*, int*);
void discriminante(int, int, int, int*);
void calcula(int, int, int);
// Funcion principal
int main(void){
  int a, b, c, d;
  char r;
  do {
    getCof(&a, &b, &c);
    discriminante(a, b, c, &d);
    if (d >= 0) {
      calcula(a, b, d);
    }else{
      printf("La ecuacion no tiene solucion\n");
    }
    printf("Desea hacer otra operacion? ");
    scanf("%c", &r);
    scanf("%c", &r);
  } while(r == 's' || r == 'S');
}
void getCof(int* a, int* b, int*c){
  printf("Ingresar coeficientes: ");
  scanf("%d %d %d", a, b, c);
}
void discriminante(int a, int b, int c, int* d){
  *d = (b*b) - (4*a*c);
}
void calcula(int a, int b, int d){
  float x1 = 0.0, x2 = 0.0;
  x1 = (float)(-(b) + sqrt(d))/2*a;
  x2 = (float)(-(b) - sqrt(d))/2*a;
  printf("Los reultados son: \n");
  printf("x1 = %.2f\nx2 = %.2f\n", x1, x2);
}
