#include <stdio.h>
int main(){
  float a, b, h;
  printf("Ingresar base: ");
  scanf("%f", &b);
  printf("Ingresar altura: ");
  scanf("%f", &h);
  a = (b*h)/2.0;
  printf("La superficie es %.2f\n", a);
  return 0;
}
