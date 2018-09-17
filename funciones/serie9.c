#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getAB(char*, char*);
void compareAB(char, char);
// Funcion principal
int main(void){
  char A, B;
  getAB(&A, &B);
  compareAB(A, B);
}
// Desarrollando las funciones
void getAB(char* A, char* B){
  printf("Ingresa dos caracteres: ");
  scanf("%c %c", A, B);
}

void compareAB(char A, char B) {
  if (B > A) {
    printf("Están en orden alfabetico\n");
  }else{
    printf("No están en orden alfabetico\n");
  }
}
