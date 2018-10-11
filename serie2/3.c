#include <stdio.h>
#include <string.h>
// Prototipos de fuciones
void getLetter(char[], char[]);
// Funcion principal
int main(void){
  char Frase[100];
  char Letras[100];
  printf("Ingresar frase: ");
  gets(Frase);
  getLetter(Frase, Letras);
}

void getLetter(char Frase[], char Letras[]){
  int i = 0;
  int Cont = 0;
  int Flag;
  // Dibujo el encabezado
  for(int i = 0; i< 43; i++){
    printf("*");
  }
  printf("\n");
  printf("*     Letra     * Cantidad de apariciones *\n");
  for(int i = 0; i< 43; i++){
    printf("*");
  }
  printf("\n");
  // Fin del dibujo del encabezado


  while (Frase [i] != '\0') {
    Cont = 0;
    Flag = 0;
    for(int k = 0; Letras[k] != '\0'; k++){
      if (Letras[k] == Frase[i]) {
        Flag = 1;
      }
    }
    for(int j = 0; Frase[j] != '\0'; j++){
      if (Flag == 0 && Frase[i] == Frase[j]) {
        Cont++;
      }
    }
    if (Cont > 0) {
      printf("*%8c       *%10d veces         *\n", Frase[i], Cont);
      for(int i = 0; i < 43; i++){
        printf("*");
      }
      printf("\n");
    }
    Letras[i] = Frase[i];
    Letras[i+1] = '\0';
    i++;
  }
}
