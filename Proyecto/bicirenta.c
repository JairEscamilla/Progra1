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
int Pedir_datos(char[]);
int iniciar_sesion(int*);
//******************************************************************************


// Funcion principal
//******************************************************************************
int main(int argc, char *argv[]) {
  int TipoUsuario = 0;
  char Nombre[10];
  char Password[50];
  if (argc != 1) {
    printf("Esto se va a desarrollar despues\n");
  }else{
    validar_archivo_login();
    printf("%d, \n", gets(Nombre));
    puts(Nombre);
  /*  do {
      printf("Ingresar nombre: ");
    }while(Pedir_datos(Nombre) == 1);
    do{
      printf("Ingresar contrasenia: ");
    }while(Pedir_datos(Password));
    iniciar_sesion(&TipoUsuario);*/
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
int Pedir_datos(char Dato[10]){
  system("clear");
  if (gets(Dato)) {
    Dato[strlen(Dato)] = '\0';
    puts(Dato);
    getchar();
    return 0;
  }else{
    printf("Ha superado el limite de caracteres permitidos");
    return 1;
  }
}
int iniciar_sesion(int* TipoUsuario){
  int inicio = 0;

  return inicio;
}
//******************************************************************************
