#include <stdio.h>
int main(){
  int n, m = 0;

  for (int i = 0; i < 4; i++) {
    printf("Ingresar valor %d: ", i+1);
    scanf("%d", &n);
    if (n > m) {
      m = n;
    }
  }
  printf("El numero mayor es %d\n", m);
  return 0;
}
