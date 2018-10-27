//  Incluimos las librerias
#include <stdio.h>
#include <string.h>

// PROTOTIPOS DE FUNCIONES


// FIN DE PROTOTIPOS DE FUNCIONES

// FUNCION PRINCIPAL
int main(int argc, char const *argv[]) {
  // Declaracion de variables
  char Archivo[50];
  char Valida[7] = {'-', 'p', 'a', 's', 'o', 's', '\0'};
  // Fin de declarcion de variables


  if ((argc > 3) || (strcmp(argv[1], Valida) == 0)) { // Validamos los parametros
    printf("Error, opcion incorrecta\n");
  }else{
    strcpy(Archivo, argv[1]); // Obtenemos el nombre del Archivo

  }



  return 0;
}
// FIN DE FUNCION PRINCIPAL

// DESARROLLO DE LAS FUNCIONES

// FIN DE DESARROLLO DE FUNCIONES
