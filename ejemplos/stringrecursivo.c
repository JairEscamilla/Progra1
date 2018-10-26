#include <stdio.h>
#include <string.h>
void InvertirFrase(char Cadena[200], char Volteada[200]);
int main(){
  char Frase[200];
  char Volteada[200];
  printf("Ingresar frase: ");
  gets(Frase);
  printf("Tu frase invertida es : ");
  InvertirFrase(Frase, Volteada+strlen(Frase)-1);
  Volteada[strlen(Frase)] = '\0';
  puts(Volteada);
}

void InvertirFrase(char Cadena[200], char Volteada[200]) {
  char aux;
  if (*Cadena != '\0') {
    InvertirFrase(Cadena+1, Volteada-1);
    aux = *Cadena;
    *Volteada = aux;
  }
}
