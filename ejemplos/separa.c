#include <stdio.h>
#include <string.h>
int separa(char[], char[50][50]);
int imprime(char[50][50], int);
int main(){
  char linea[100], palabras[50][50];
  int numpalabras;
  printf("Ingresar palabras: ");
  gets(linea);
  imprime(palabras, separa(linea, palabras));
}
int separa(char frase[], char palabras[50][50]){
  int i, j = 0, k = 0;
  for(i = 0; i < strlen(frase); i++){
    if (frase[i] != ' ') {
      palabras[k][j] = frase[i];
      j++;
    }else{
      if (frase[i-1] != ' ') {
        palabras[k][j] = '\0';
        k++;
        j = 0;
      }
    }
  }
  palabras[k][j] = '\0';
  k++;
  return k;
}

int imprime(char Palabras[50][50], int num){
  int i;
  for(i = 0; i < num; i++){
    puts(Palabras[i]);
  }
}
