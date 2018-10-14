// Incluyo las librerias
#include <stdio.h>
#include <string.h>
// Prototipos de funciones
void invertir(char[]);
// Funcion principal
int main(void){
  char Frase[100];
  printf("Ingresar frase: ");
  gets(Frase);
  invertir(Frase);
}

void invertir(char Frase[]){
  for(int i = strlen(Frase)-1; i >= 0; i--){
    if (Frase[i] == 32) {
      for(int j = i+1; Frase[j] != '\0' && Frase[j] != 32; j++){
        printf("%c", Frase[j]);
      }
      printf(" ");
    }
  }
  for(int i = 0; Frase[i] != 32 && Frase[i] != '\0'; i ++){
    printf("%c", Frase[i]);
  }
  printf("\n");
}
