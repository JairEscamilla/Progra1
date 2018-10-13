#include <stdio.h>
#include <string.h>
void separa(char[], int);
void cuentaEspacios(int*, char[]);
int main(void){
  char Frase[100];
  int Espacios = 0;
  printf("Ingresar frase: ");
  gets(Frase);
  cuentaEspacios(&Espacios, Frase);
  separa(Frase, Espacios);
}

void cuentaEspacios(int* Esp, char Fr[]){
  for(int i = 0;  Fr[i] != '\0'; i++){
    if (Fr[i] == 32) {
      *Esp = *Esp + 1;
    }
  }
}

void separa(char Frase[], int Limite){
  int Con = 0;
  for(int i = 0; i <= Limite; i++){
    for(int r = Con; Frase[r] != 32 && Frase[r] != '\0'; r++){
      printf("%c", Frase[r]);
      Con++;
    }
    Con++;
    printf("\n");
  }
}
