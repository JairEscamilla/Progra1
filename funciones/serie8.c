#include <stdio.h> // Incluyo la libreria
// Prototipos de funciones
void getLetter(char*);
void compare(char);
// Funcion principal
int main(void){
  char Letter = 0;
  printf("Ingresar letra: ");
  getLetter(&Letter);
  while (!(Letter >= 65 && Letter <= 90)) {
    getLetter(&Letter);
    compare(Letter);
  }
}

// Desarrollando las funciones
void getLetter(char* Letter){
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
