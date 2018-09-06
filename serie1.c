#include <stdio.h>
int main(){
  int n = 0;
  int cont = 0;
  do {
    printf("Ingresar numero: ");
    scanf("%d", &n);
    if (n != 0) {
      printf("%d\n", n);
      cont += 1;
    }
  } while(n != 0);
  printf("Los cantidad de numeros distintos de 0 leidos es %d\n", cont);
  return 0;
}
