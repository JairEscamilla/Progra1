#include <stdio.h>
#include <string.h>
void voltear(char[]);
int main(void){
    char Frase[250];
    printf("Ingresar frase: ");
    gets(Frase);
    voltear(Frase);
}
void voltear(char Frase[]){
  for(int i = strlen(Frase) - 1; i >= 0; i--){
    printf("%c", Frase[i]);
  }
  printf("\n");
}
