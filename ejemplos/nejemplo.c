#include <stdio.h>
#include <string.h>
void voltear(char[], char[]);
int main(void){
  char Fr[200];
  char Volt[200];
  char Copy[200];
  printf("Ingresar frase: ");
  gets(Fr);
  voltear(Fr, Volt);
  puts(Volt);
}
void voltear(char Frase[], char Volt[]){
  int Cont = 0;
  for(int i = strlen(Frase)-1; i >= 0; i--){
    Volt[Cont] = Frase[i];
    Cont++;
  }
  Volt[strlen(Frase)] = '\0';
}

// Lab-> Practica 2 para jueves 18
