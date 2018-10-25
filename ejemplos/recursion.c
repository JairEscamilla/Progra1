#include <stdio.h>
int factorial(int);
int main(void){
  int num;
  int n;
  printf("Ingresar numero: ");
  scanf("%d", &num);
  n = factorial(num);
  printf("%d\n", n);
}

int factorial(int n){
  printf("Entrada a factorial %d\n", n);
  if (n > 1) {
    return n*factorial(n-1);
  }else{
    return 1;
  }
}
