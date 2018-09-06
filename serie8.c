#include <stdio.h>
int main() {
  char c;
  printf("Ingresar caracter: ");
  scanf("%c", &c);
  if(c>=65 && c<=90 )
    printf("El caracter introducido %c es mayuscula\n", c);
  else{
    if(c>=97 && c<=122)
      printf("El caracter %c es minuscula\n", c);
    else
      printf("Eso no es un una letra\n");
  }
  return 0;
}
