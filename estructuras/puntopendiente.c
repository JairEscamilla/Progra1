#include <stdio.h>
typedef struct Punto{
  int x, y;
}Punto;

void leerCoordenada(Punto*);
void construirecuacion(Punto, Punto);

int main(){
  Punto c1;
  Punto c2;
  leerCoordenada(&c1);
  leerCoordenada(&c2);
  construirecuacion(c1, c2);
  return 0;
}
void leerCoordenada(Punto* c){
  printf("Ingresar coordenada en x: ");
  scanf("%d", &c->x);
  printf("Ingresar coordenada en y: ");
  scanf("%d", &c->y);
}

void construirecuacion(Punto c1, Punto c2){
  float m = (c2.y-c1.y)/(c2.x-c1.x);
  float b;
  // y = mx+b
  // b = y-mx
  b = c1.y-(m*c1.x);
  if(b >= 0)
    printf("La ecuacion de la recta es: y = %.2fx + %0.2f\n", m, b);
  else
    printf("La ecuacion de la recta es: y = %.2fx %0.2f\n", m, b);
}
