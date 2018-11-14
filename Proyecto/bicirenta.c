// Incluimos las librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definimos las estructuras
//******************************************************************************
typedef struct defLogin{
  char Nombre[50];
  char Direccion[200];
  char Contrasenia[50];
  long TarjetaCredito;
  long UserNumber;
  int Flag;
}User;
//******************************************************************************


// Prototipos de las funciones
//******************************************************************************
void validar_archivo_login();
//******************************************************************************


// Funcion principal
//******************************************************************************
int main(int argc, char *argv[]) {
  int TipoUsuario = 0;
  if (argc != 1) {
    printf("Esto se va a desarrollar despues\n");
  }else{
    validar_archivo_login();
  }
  return 0;
}
//******************************************************************************

// Desarrollo de las funciones
//******************************************************************************
void validar_archivo_login(){
  User Usuario;
  FILE* Arch;
  FILE* Archivo;
  Arch = fopen("login.txt", "rt");
  if (Arch == NULL) {
    Archivo = fopen("login.txt", "wt");
    strcpy(Usuario.Nombre, "Ibero");
    strcpy(Usuario.Direccion, "Prolongacion Paseo de la Reforma 880, Lomas de Santa Fe, 01219 Ciudad de Mexico, CDMX");
    strcpy(Usuario.Contrasenia, "c123");
    Usuario.TarjetaCredito = 1234567;
    Usuario.UserNumber = 1;
    Usuario.Flag = 1;
    fprintf(Archivo, "%s\n%s\n%s\n%ld\n%ld\n%d\n", Usuario.Nombre, Usuario.Direccion, Usuario.Contrasenia, Usuario.TarjetaCredito, Usuario.UserNumber, Usuario.Flag);
    fclose(Archivo);
  }
}
//******************************************************************************
