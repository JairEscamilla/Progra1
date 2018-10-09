#include <stdio.h>
// Prototipos de las funciones
void getLetter(char[], char[]);
void iniciarCuenta(int[]);
void cuenta(char[], char[], int[]);
void despliega(char[], int[]);
// Funcion principal
int main(void){
  char Frase[100];
  char Letras[100];
  int Conteo[100];
  printf("Ingresar una frase: ");
  scanf("%s", Frase);
  for(int i = 0; i<= 100; i++){
    Letras[i] = '*';
  }
  getLetter(Frase, Letras);
  //iniciarCuenta(Conteo);
  //cuenta(Frase, Letras, Conteo);
  //despliega(Letras, Conteo);
}

// Desarrollando las funciones
void getLetter(char Frase[], char Letras[]){
  int Flag = 0;
  for(int i = 0; Frase[i] != '\0'; i++){
    Flag = 0;
      for(int j = 0; j <= i; j++){
          if (Letras[j] == Frase[i]) {
            Flag = 1;
          }
      }
      if (Flag == 0) {
        Letras[i] = Frase[i];
      }
  }
  int Cuenta = 0;
  char Nueva[100];
  for(int i = 0; i <= 100; i++){
    if (Letras[i] != '*') {
      __fpurge(stdin);
      Nueva[Cuenta] = Letras[i];
      Cuenta++;
    }
  }
  for(int i = 0; Nueva[i] != '\0'; i++){
    printf("%d - %c\n", Nueva[i], Nueva[i]);
  }
}

void iniciarCuenta(int Cuenta[]){
  for(int i = 0; i <= 100; i++){
    Cuenta[i] = 0;
  }
}
void cuenta(char Frase[], char Letras[], int Conteo[]){
  int i = 0;
  int j = 0;
  while (Letras[i] != '\0') {
    while (Frase[j] != '\0') {
      if (Letras[i] == Frase[i]) {
        Conteo[i]++;
      }
      j++;
    }
    i++;
  }
}

void despliega(char Frase[], int Cuenta[]){
  int i = 0;
  printf("Estamos dentro\n");
  printf("%c", Frase[0]);
  while (Frase[i] != '\0') {
    printf("%c aparece %d veces", Frase[i], Cuenta[i]);
  }
}
