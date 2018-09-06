#include <stdio.h>
int main(){
  char c, x;
  printf("Ingresar dos caracteres: ");
  scanf("%c %c", &c, &x);
  if (c < x) {
    printf("Estan en orden alfabetico");
  }else{
    printf("No estan en orden alfabetico\n");
  }
  return 0;
}
