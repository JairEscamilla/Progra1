#include <stdio.h>
int main(){
  int n, flag = 0;
  printf("Ingresar un numero: ");
  scanf("%d", &n);
  for (int i = 2; i < n; i++) {
    if (n%i == 0) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    printf("%d no es primo\n", n);
  }else{
    printf("%d es primo\n", n);
  }
  return 0;
}
