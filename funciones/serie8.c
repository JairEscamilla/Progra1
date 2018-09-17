#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getLetter(char*);
void compare(char);
// Funcion principal
int main(void){
  char Letter = 0;
  do {
    getLetter(&Letter);
    compare(Letter);
  } while(!(Letter >= 65 && Letter <= 90) && !(Letter >= 97 && Letter <= 122));
}
// Desarrollando las funciones
void getLetter(char* Letter){
    __fpurge(stdin);
    printf("Ingresar letra: ");
    scanf("%c", Letter);
}
void compare(char Letter){
  if (Letter >= 65 && Letter <= 90)
    printf("La letra introducida es mayuscula\n");
  else{
    if (Letter >= 97 && Letter <= 122)
      printf("La letra introducida es minuscula\n");
    else{
      printf("Ingresa una letra!\n");
    }
  }
}
