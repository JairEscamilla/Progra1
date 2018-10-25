#include <stdio.h>
#include <string.h>
void InvertirFrase(char Cadena[200]);
int main(){
  char Frase[200];
  printf("Ingresar frase: ");
  gets(Frase);
  printf("Tu frase invertida es : ");
  InvertirFrase(Frase);
  printf("\n");
}

void InvertirFrase(char Cadena[200]) {
  if (*Cadena != '\0') {
    InvertirFrase(Cadena+1);
    printf("%c", *Cadena);
  }
}
