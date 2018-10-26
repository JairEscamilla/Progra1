#include <stdio.h>
#include <string.h>
void InvertirFrase(char Cadena[200], char Volteada[200]);
int main(){
  char Frase[200];
  char Volteada[200];
  printf("Ingresar frase: ");
  gets(Frase);
  printf("Tu frase invertida es : ");
  InvertirFrase(Frase, Volteada);
  puts(Volteada);
}

void InvertirFrase(char Cadena[200], char Volteada[200]) {
  if (*Cadena != '\0') {
    InvertirFrase(Cadena+1, Volteada);

    *Volteada = *Cadena;
    Volteada ++;
  }
}
