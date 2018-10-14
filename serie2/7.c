// Incluyo las librerias
#include <stdio.h>
#include <string.h>
// Prototipos de funciones
void eliminarFrase(char[]);
// Funcion principal
int main(void){
  char Frase[100];
  printf("Ingresar una frase de 3 palabras: ");
  gets(Frase);
  eliminarFrase(Frase);
}

// Desarrollando las funciones
void eliminarFrase(char Frase[]){
  for(int i = 0; Frase[i] != 32; i++)
    printf("%c", Frase[i]);
  printf(" ");
  for(int i = strlen(Frase)-1; i >= 0; i--){
    if (Frase[i] == 32) {
      for(int j = i+1; Frase[j] != '\0'; j++)
        printf("%c", Frase[j]);
      break;
    }
  }
  printf("\n");
}
