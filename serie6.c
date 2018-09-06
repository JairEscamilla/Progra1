#include <stdio.h>
int main(){
  float p, kg, g;
  printf("Ingresa tu peso en libras: ");
  scanf("%f", &p);
  kg = p*0.45359;
  g = kg * 1000;
  printf("El peso en kg es %.2f\n", kg);
  printf("El peso en g es %.2f\n", g);
  return 0;
}
