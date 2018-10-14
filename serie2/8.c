// Incluy las librerias
#include <stdio.h>
#include <string.h>
// Prototipos de funciones
void min(char[]);
void may(char[]);
// Funcion principal
int main(void){
  char Frase[100];
  printf("Ingresar frase: ");
  gets(Frase);
  min(Frase);
  printf("\n");
  may(Frase);
  printf("\n");
}

// Desarrollando las funciones
void min(char Frase[]){
  for(int i = 0; Frase[i] != '\0'; i++){
    if (Frase[i] >= 'A' && Frase[i] <= 'Z') {
      printf("%c", Frase[i] - 'A' + 'a');
    }else{
      printf("%c", Frase[i]);
    }
  }
}

void may(char Frase[]){
  for(int i = 0; Frase[i] != '\0'; i++){
    if (Frase[i] >= 'a' && Frase[i] <= 'z') {
      printf("%c", Frase[i] - 'a' + 'A');
    }else{
      printf("%c", Frase[i]);
    }
  }
}
