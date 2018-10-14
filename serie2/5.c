// Incluyo las librerias
#include <stdio.h>
#include <string.h>
// Prototipos de funciones
void Conversion(char[], char[]);
void deleteEspace(char[]);
void invertir(char[], char[]);
// Funcion principal
int main(void){
  char Frase[100];
  char Frase2[100];
  char Frase3[100];
  printf("Ingresar una frase: ");
  gets(Frase);
  Conversion(Frase, Frase2);
  deleteEspace(Frase2);
  invertir(Frase2, Frase3);

  if (strcmp(Frase2, Frase3) == 0)
    printf("La frase es un palindromo\n");
  else
    printf("La frase NO es un palindromo\n");
}

// Desarrollando las funciones

void Conversion(char Frase[], char Frase2[]){ // Convierte la cadena a mayusculas
  int i;
  for(i = 0; Frase[i] != '\0'; i++){
    if(Frase[i] >= 'a' && Frase[i] <= 'z')
      Frase2[i] = Frase[i] - 'a' + 'A';
    else
      Frase2[i] = Frase[i];
  }
  Frase2[i] = '\0';
}

// Quita los espacios de la cadena
void deleteEspace(char Frase2[]){
  int i;
  int j;
  for(i = 0; Frase2[i] != '\0'; i++){
    if (Frase2[i] == 32) {
      for(j = i+1; Frase2[j] != '\0'; j++){
        Frase2[j-1] = Frase2[j];
      }
      Frase2[j-1] = '\0';
    }
  }
}
// Invierte la cadena
void invertir(char Frase3[], char Frase4[]){
  int Cont = 0;
  for(int i = strlen(Frase3)-1; i >= 0; i--){
    Frase4[Cont] = Frase3[i];
    Cont++;
  }
  Frase4[strlen(Frase3)] = '\0';
}
