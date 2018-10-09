#include <stdio.h>
#include <string.h>
void Imprimed(char*);
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
  Imprimed(Frase);
}
void Imprimed(char* Frase){
  while (*Frase != '\0') {
    printf("%c", *Frase);
    Frase++;
  }
  printf("\n");
}
