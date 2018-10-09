#include <stdio.h>
#include <string.h>
int main(void){
  char Frase[200];
  printf("Ingresar frase: ");
  gets(Frase);
  puts(Frase);
  int i = 0;
  while(Frase[i] != '\0'){
    printf("%c", Frase[i]);
    i++;
  }
  printf("\n");
}
