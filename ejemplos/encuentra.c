#include <stdio.h>
#include <string.h>
int Encuentra(char Cadena[], char Caracter);
int main(void){
  char frase[100];
  char letra;
  printf("Ingresar frase: ");
  gets(frase);
  printf("Ingresar caracter a buscar: ");
  scanf("%c", &letra);
  if (Encuentra(frase, letra)) {
    printf("Se encontro el caracter\n");
  }else{
    printf("No se encontro el caracter\n");
  }
}

int Encuentra(char cadena[], char caracter){
  int i = 0, encontrada = 0;
  while ((i < strlen(cadena)) && (caracter != cadena[i])) {
    i++;
  }
  if (i < strlen(cadena)) {
    encontrada = 1;
  }else{
    encontrada = 0;
  }
  return encontrada;
}
