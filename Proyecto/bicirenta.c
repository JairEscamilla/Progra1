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
  struct defLogin* siguiente;
}User;
//******************************************************************************


// Prototipos de las funciones
//******************************************************************************
void validar_archivo_login();
int Pedir_datos(char[], char[]);
int iniciar_sesion(int*);
void leerListaUsuarios(User**);

void liberarMemoria(User**);
//******************************************************************************


// Funcion principal
//******************************************************************************
int main(int argc, char *argv[]) {
  int TipoUsuario = 0;
  char Nombre[50];
  char Password[50];
  User* ListaUsuarios = NULL;
  if (argc != 1) {
    printf("Esto se va a desarrollar despues\n");
  }else{
    validar_archivo_login();
    while(Pedir_datos(Nombre, "nombre"));
    while(Pedir_datos(Password, "password"));
    puts(Nombre);
    puts(Password);
    leerListaUsuarios(&ListaUsuarios);
  }

  liberarMemoria(&ListaUsuarios);
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
    Usuario.siguiente = NULL;
    fprintf(Archivo, "%s*%s*%s*%ld*%ld*%d\n", Usuario.Nombre, Usuario.Direccion, Usuario.Contrasenia, Usuario.TarjetaCredito, Usuario.UserNumber, Usuario.Flag);
    fclose(Archivo);
  }
}
int Pedir_datos(char Dato[], char NombreDato[]){
  system("clear");
  int i = 0;
  int status = 0;
  printf("Ingresar %s: ", NombreDato);
  i = 0;
  while ((Dato[i] = getchar()) != '\n' && status == 0) {
    if (i > 50) {
      printf("Haz sobrepasado el limite de caracteres!\nPresione enter para volver a intentar");
      getchar();
      __fpurge(stdin);
      Dato[i+1] = '\n';
      status = 1;
    }
    i++;
  }
  Dato[i] = '\0';
  return status;
}
void leerListaUsuarios(User** Lista){
  FILE* Archivo = fopen("login.txt", "rt");
  if (Archivo == NULL) {
    printf("Ha ocurrido un error, vuelva a intentar\n");
    exit(0);
  }
  while (!feof(Archivo)) {
    User* Usuario = (User*)malloc(sizeof(User));
    fscanf(Archivo,"%s*%s*%s*%ld*%ld*%d", Usuario->Nombre, Usuario->Direccion, Usuario->Contrasenia, &Usuario->TarjetaCredito, &Usuario->UserNumber, &Usuario->Flag);
    if (*Lista == NULL) {
      *Lista = Usuario;
    }else{
      User* aux = *Lista;
      while (aux->siguiente != NULL) {
        aux = aux->siguiente;
      }
      aux->siguiente = Usuario;
    }
  }
}

void liberarMemoria(User** Lista){
  while (*Lista !=  NULL) {
    User* Proximo = (*Lista)->siguiente;
    free(*Lista);
    *Lista = Proximo;
  }
}

int iniciar_sesion(int* TipoUsuario){
  int inicio = 0;

  return inicio;
}
//******************************************************************************
