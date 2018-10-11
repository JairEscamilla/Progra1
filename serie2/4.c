#include <stdio.h>
#include <string.h>
// Prototipos de funciones
void getLimits(char[], int[], int*);
// Funcion princial
int main(void){
  char Frase[200];
  int Limites[100];
  int Cant = 0;
  Limites[0] = 0;
  printf("Ingresar frase: ");
  gets(Frase);
  getLimits(Frase, Limites, &Cant);
}

// Desarrollando las funciones
void getLimits(char Frase[], int Limites[], int* Cantidad){
  for(int i = 0; Frase[i] != '\0'; i++){
    
  }
}
