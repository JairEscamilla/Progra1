#include <stdio.h>
#include <math.h> // Incluyo la libreria
// Prototipos de funciones
void getCof(float*, float*, float*);
void discriminante(float, float, float, float*);
void calcula(float, float, float);
// Funcion principal
float main(void){
  float a, b, c, d;
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
void getCof(float* a, float* b, float*c){
  printf("Ingresar coeficientes: ");
  scanf("%f %f %f", a, b, c);
}
void discriminante(float a, float b, float c, float* d){
  *d = (b*b) - (4*a*c);
  float x = (b*b) - (4*a*c);
}
void calcula(float a, float b, float d){
  float x1 = 0.0, x2 = 0.0;
  x1 = (float)(-(b) + sqrt(d))/2*a;
  x2 = (float)(-(b) - sqrt(d))/2*a;
  printf("Los reultados son: \n");
  printf("x1 = %.2f\nx2 = %.2f\n", x1, x2);
}
