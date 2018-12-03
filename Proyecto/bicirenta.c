// Incluimos las librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definimos las estructuras
//******************************************************************************
// Estructura de un Usuario
typedef struct defLogin{
  char Nombre[50];
  char Direccion[200];
  char Contrasenia[50];
  long TarjetaCredito;
  long UserNumber;
  int Flag;
  struct defLogin* siguiente;
}User;
// Estructura de una biciestacion
typedef struct defBiciestacion{
  long NumBiciestacion;
  char NombreGenerico[100];
  char Calle[50];
  int Numero;
  int CP;
  char Ciudad[50];
  struct defBiciestacion* siguiente;
}Biciestacion;
//******************************************************************************


// Prototipos de las funciones
//******************************************************************************
void validar_archivo_login();
int Pedir_datos(char[], char[], int);
int iniciar_sesion(int*, char[], char[], User*);
void leerListaUsuarios(User**);
void separarListaUsuarios(int* i, int* j, int* contador, char linea[], char Datos[6][200]);
void limpiarDatos(char Datos[6][200]);
void MenuAdministrador();
void MenuUsuario();
void altaBiciestacion();
int ValidarCaracteres(char[], char[]);
int validarNumeros(char[], char[]);
void MostrarLista(User*);
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
    system("clear");
    while(Pedir_datos(Nombre, "nombre", 50));
    system("clear");
    while(Pedir_datos(Password, "password", 50));
    leerListaUsuarios(&ListaUsuarios);
    if(iniciar_sesion(&TipoUsuario, Nombre, Password, ListaUsuarios)){
      if (TipoUsuario == 1) {
        MenuAdministrador();
      }
      if (TipoUsuario == 0) {
        MenuUsuario();
      }
    }
    else
      printf("Fallo en la autenticacion\n");
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
    fprintf(Archivo, "%s/%s/%s/%ld/%ld/%d/\n", Usuario.Nombre, Usuario.Direccion, Usuario.Contrasenia, Usuario.TarjetaCredito, Usuario.UserNumber, Usuario.Flag);
    fclose(Archivo);
  }
}
int Pedir_datos(char Dato[], char NombreDato[], int longitud){
  __fpurge(stdin);
  int i = 0;
  int status = 0;
  printf("Ingresar %s: ", NombreDato);
  i = 0;
  while ((Dato[i] = getchar()) != '\n' && status == 0) {
    if (i > longitud) {
     printf("Haz sobrepasado el limite de caracteres!\n");
    //  __fpurge(stdin);
    //  getchar();
      Dato[i+1] = '\n';
      status = 1;
    }
    i++;
  }
  Dato[i] = '\0';
  return status;
}
void liberarMemoria(User** Lista){
  while (*Lista !=  NULL) {
    User* Proximo = (*Lista)->siguiente;
    free(*Lista);
    *Lista = Proximo;
  }
}
void MostrarLista(User* Lista){
  User* aux = Lista;
  while (aux != NULL) {
    printf("Nombre lista: %s\nPassword lista: %s\n", aux->Nombre, aux->Contrasenia);
    printf("Direccion: %s\n", aux->Direccion);
    aux = aux->siguiente;
  }
}
int iniciar_sesion(int* TipoUsuario, char Nombre[], char Password[], User* Lista){
  User* aux = Lista;
  int inicio = 0;
  do{
    if ((strcmp(Nombre, aux->Nombre) == 0) && (strcmp(Password, aux->Contrasenia) == 0)) {
      inicio = 1;
      *TipoUsuario = aux->Flag;
    }
    aux = aux->siguiente;
  }while ((aux != NULL) && ((strcmp(Nombre, aux->Nombre) == 0) && (strcmp(Password, aux->Contrasenia) == 0)));
  return inicio;
}
void MenuAdministrador() {
  system("clear");
  char Opcion;
  printf("Ha iniciado sesion correctamente\n\n");
  printf("\ta. Alta de una nueva bici-estacion.\n");
  printf("\tb. Baja de una nueva bici-estacion.\n");
  printf("\tc. Reasignar bicicletas entre biciestaciones.\n");
  printf("\td. Mostrar estatus.\n");
  printf("\te. Alta de un usuario del servicio.\n");
  printf("\tf. Baja de un usuario del servicio.\n");
  printf("\tg. Salida del sistema.\n\n");
  printf("Seleccione una opcion-> ");
  scanf("%c", &Opcion);
  switch (Opcion) {
    case 'a':
      altaBiciestacion();
      break;
    case 'b':
      printf("Baja de una bici-estacion\n");
      break;
    case 'c':
      printf("Reasignar bicicletas\n");
      break;
    case 'd':
      printf("Mostrar estatus\n");
      break;
    case 'e':
      printf("Alta de un usuario\n");
      break;
    case 'f':
      printf("Baja de un usuario\n");
      break;
    case 'g':
      printf("Hasta pronto\nVuelva pronto\n");
      exit(0);
      break;
    default:
      printf("Opcion incorrecta\nSelecciona una opcion correcta.\n");
      break;
  }
  printf("Presiona enter para volver al menu...");
  __fpurge(stdin);
  getchar();
  MenuAdministrador();
}
void MenuUsuario(){
  system("clear");
  printf("Ha iniciado sesion correctamente\n\n");
  printf("\ta. Rentar una bicicleta.\n");
  printf("\tb. Estacionar una bicicleta.\n");
  printf("\tc. Mostrar el saldo.\n\n");
  printf("Ingresar una opcion: ");
}
void leerListaUsuarios(User** Lista){
  char linea[500], Datos[6][200];
  int i, j = 0, contador = 0;
  FILE* Archivo = fopen("login.txt", "rt");
  if (Archivo == NULL) {
    printf("Ha ocurrido un error, vuelva a intentar\n");
    exit(0);
  }
  while (fgets(linea, 500, Archivo) != NULL) {
    User* Usuario = (User*)malloc(sizeof(User));
    i = 0;
    contador = 0;
    separarListaUsuarios(&i, &j, &contador, linea, Datos);
    strcpy(Usuario->Nombre, Datos[0]);
    strcpy(Usuario->Direccion, Datos[1]);
    strcpy(Usuario->Contrasenia, Datos[2]);
    Usuario->TarjetaCredito = atoi(Datos[3]);
    Usuario->UserNumber = atoi(Datos[4]);
    Usuario->Flag = atoi(Datos[5]);
    Usuario->siguiente = NULL;
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
void separarListaUsuarios(int* i, int* j, int* contador, char linea[], char Datos[6][200]){
  while(linea[*i] != '\0' && linea[*i] != '\n'){
    Datos[*contador][*j] = linea[*i];

    if(linea[*i+1] == '/'){
      Datos[(*contador)][(*j)+1] = '\0';
      (*contador)++;
      (*j) = -1;
      (*i)++;
    }
    (*i)++;
    (*j)++;
  }
}
void limpiarDatos(char Datos[6][200]){
  for(int i = 0; i < 5; i++){
    Datos[i][0] = '\0';
  }
}

void altaBiciestacion(){
  FILE* Archivo;
  Biciestacion Estacion;
  char numero[3], cp[5], error[50];
  int validacion = 1;
  error[0] = '\0';
  Archivo = fopen("biciestaciones.txt", "at");
  if (Archivo == NULL) {
    Archivo = fopen("biciestaciones.txt", "wt");
  }
  system("clear");
  printf("\t\tDar de alta una nueva biciestacion\n");
  while(Pedir_datos(Estacion.NombreGenerico, "nombre generico de biciestacion", 100));
  while(Pedir_datos(Estacion.Calle, "calle de la biciestacion", 50));
  while(validacion){
    validacion = Pedir_datos(numero, "numero (numeracion de la calle)", 3);
    validacion = validarNumeros(numero, error);
    if(strlen(error) != 0)
      puts(error);
    error[0] = '\0';
  }
  validacion = 1;
  while(validacion){
    validacion = Pedir_datos(cp, "codigo postal", 5);
    validacion = validarNumeros(cp, error);
    if(strlen(cp) != 5){
      printf("Este campo solo admite 5 caracteres\n");
      validacion = 1;
    }
    if(strlen(error) != 0)
      puts(error);
    error[0] = '\0';
  }
  validacion = 1;
  while(validacion){
    validacion = Pedir_datos(Estacion.Ciudad, "ciudad", 50);
    validacion = ValidarCaracteres(Estacion.Ciudad, error);
    if(strlen(error) != 0)
      puts(error);
    error[0] = '\0';
  }
}
int ValidarCaracteres(char Cadena[], char Error[]){
  int i = 0;
  int Status = 0;
  while(Cadena[i] != '\0' && Status == 0){
    if(!(Cadena[i] >= 'a' && Cadena[i] <= 'z') && !(Cadena[i] >= 'A' && Cadena[i] <= 'Z')){
      Status = 1;
      strcpy(Error, "Este campo solamente admite letras\n");
    }
    i++;
  }
  return Status;
}
int validarNumeros(char Cadena[], char Error[]){
  int i = 0;
  int Status = 0;
  while(Cadena[i] != '\0' && Status == 0){
    if(!(Cadena[i] >= '0' && Cadena[i] <= '9')){
      Status = 1;
      strcpy(Error, "Este campo solo puede contener numeros\n");
    }
    i++;
  }
  return Status;
}
//******************************************************************************
