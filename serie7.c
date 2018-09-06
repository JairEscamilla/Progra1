#include <stdio.h>
int main(){
  int a, b, c, aux, aux2;
  printf("Ingresar valor de a, b, c: ");
  scanf("%d %d %d", &a, &b, &c);
  aux = b;
  aux2 = c;
  b = a;
  c = aux;
  a = aux2;
  printf("El intercambio es a = %d b = %d c = %d\n", a, b, c);
  return 0;
}
