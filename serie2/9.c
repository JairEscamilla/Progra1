// Incluyo las librerias
#include <stdio.h>
#include <string.h>
// Prototipos de funciones
void may(char[]);
// Funcion principal
int main(void){
  char Frase[100];
  printf("Ingresar una frase: ");
  gets(Frase);
  may(Frase);
  printf("\n");
}
void may(char Frase[]){
  if (Frase[0] >= 'a' && Frase[0] <= 'z') {
    printf("%c", Frase[0] - 'a' + 'A');
  }else{
    printf("%c", Frase[0]);
  }

  for(int i = 1; Frase[i] != '\0'; i++){
    if ((Frase[i+1] == 32  || Frase[i-1] == 32 || Frase[i+1] == '\0') && (Frase[i] >= 'a' && Frase[i] <= 'z')) {
      printf("%c", Frase[i] - 'a' + 'A');
    }else{
      printf("%c", Frase[i]);
    }
  }
}
