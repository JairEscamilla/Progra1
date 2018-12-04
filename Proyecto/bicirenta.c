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

typedef struct defBici{
  long NumeroBici;
  long Biciestacion;
  long rentas;
  char Timestamp[50];
  struct defBici* siguiente;
}Bicicleta;
//******************************************************************************


// Prototipos de las funciones
//******************************************************************************
void validar_archivo_login();
int Pedir_datos(char[], char[], int);
int iniciar_sesion(int*, char[], char[], User*);
void leerListaUsuarios(User**);
void cargarListaBiciestacion(Biciestacion**);
void cargarListaBicis(Bicicleta**);
void separarListaUsuarios(int* i, int* j, int* contador, char linea[], char Datos[6][200]);
void limpiarDatos(char Datos[6][200]);
void MenuAdministrador(Biciestacion**, Bicicleta**);
void MenuUsuario();
void altaBiciestacion(Biciestacion**);
void altaBici(Bicicleta**, Biciestacion**);
int ValidarCaracteres(char[], char[]);
int validarNumeros(char[], char[]);
void anadirBiciestacion(int, char[], char[], char[], char[], char[], Biciestacion**);
void anadirBici(int, char[], Bicicleta**, Biciestacion**);
void MostrarLista(User*);
void imprimirArchivos(Biciestacion**, Bicicleta**);
void liberarMemoria(User**);
//******************************************************************************


// Funcion principal
//******************************************************************************
int main(int argc, char *argv[]) {
  int TipoUsuario = 0;
  char Nombre[50];
  char Password[50];
  User* ListaUsuarios = NULL;
  Biciestacion* ListaBiciestacion = NULL;
  Bicicleta* ListaBicis = NULL;
  cargarListaBiciestacion(&ListaBiciestacion);
  cargarListaBicis(&ListaBicis);
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
        MenuAdministrador(&ListaBiciestacion, &ListaBicis);
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
      Dato[i+1] = '\n';
      status = 1;
    }
    i++;
  }
  if(i == 0){
    printf("Asegurate de escribir algo!\n");
    status = 1;
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
void MenuAdministrador(Biciestacion** ListaBiciestaciones, Bicicleta** ListaBicis) {
  system("clear");
  char Opcion;
  printf("Ha iniciado sesion correctamente\n\n");
  printf("\ta. Alta de una nueva bici-estacion.\n");
  printf("\tb. Baja de una nueva bici-estacion.\n");
  printf("\tc. Alta de una bici a una bici-estacion.\n");
  printf("\td. Baja de una bici a una bici-estacion.\n");
  printf("\te. Reasignar bicicletas entre biciestaciones.\n");
  printf("\tf. Mostrar estatus.\n");
  printf("\tg. Alta de un usuario del servicio.\n");
  printf("\th. Baja de un usuario del servicio.\n");
  printf("\ti. Salida del sistema.\n\n");
  printf("Seleccione una opcion-> ");
  scanf("%c", &Opcion);
  switch (Opcion) {
    case 'a':
      altaBiciestacion(ListaBiciestaciones);
      break;
    case 'b':
      printf("Baja de una bici-estacion\n");
      break;
    case 'c':
      altaBici(ListaBicis, ListaBiciestaciones);
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
      printf("Baja de un usuario\n");
      break;
    case 'h':
      printf("Baja de un usuario\n");
      break;
    case 'i':
      printf("Hasta pronto\nVuelva pronto\n");
      imprimirArchivos(ListaBiciestaciones, ListaBicis);
      exit(0);
      break;
    default:
      printf("Opcion incorrecta\nSelecciona una opcion correcta.\n");
      break;
  }
  printf("Presiona enter para volver al menu...");
  __fpurge(stdin);
  getchar();
  MenuAdministrador(ListaBiciestaciones, ListaBicis);
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
void altaBiciestacion(Biciestacion** Lista){
  FILE* Archivo;
  Biciestacion Estacion, *auxiliar = *Lista;
  char numero[4], numeroTotal[3], cp[5], error[50], renglon[500], basura[100];
  int validacion = 1, validacion2 = 1, id = 0;
  error[0] = '\0';
  numero[0] = '\0';
  cp[0] = '\0';
  Archivo = fopen("biciestaciones.txt", "rt");
  if (Archivo == NULL) {
    id = 1;
  }else{
    while(auxiliar->siguiente != NULL)
      auxiliar = auxiliar->siguiente;
    id = auxiliar->NumBiciestacion +1;
  }
  Archivo = fopen("biciestaciones.txt", "at");
  system("clear");
  printf("\t\tDar de alta una nueva biciestacion\n");
  while(Pedir_datos(Estacion.NombreGenerico, "nombre generico de biciestacion", 100));
  while(Pedir_datos(Estacion.Calle, "calle de la biciestacion", 50));
  while(validacion || validacion2){
    validacion = Pedir_datos(numero, "numero (numeracion de la calle)", 2);
    validacion2 = validarNumeros(numero, error);
    if(strlen(error) != 0)
      puts(error);
    error[0] = '\0';
  }
  validacion = 1;
  while(validacion){
    validacion = Pedir_datos(cp, "codigo postal", 5);
    validacion = validarNumeros(cp, error);
    if(strlen(cp) != 5){
      printf("Este campo se compone de solo 5 caracteres\n");
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
  anadirBiciestacion(id, Estacion.NombreGenerico, Estacion.Calle, numero, cp, Estacion.Ciudad, Lista);
  fclose(Archivo);
}
void altaBici(Bicicleta** Lista, Biciestacion** ListaBiciestaciones){
  FILE* Archivo;
  Bicicleta *auxiliar = *Lista;
  char NumBiciestacion[4], error[100];
  Archivo = fopen("bicis.txt", "rt");
  int id = 0;
  Biciestacion* LBiciestaciones = *ListaBiciestaciones;
  int validacion = 1;
  if (Archivo == NULL) {
    id = 1;
  }else{
    while(auxiliar->siguiente != NULL)
      auxiliar = auxiliar->siguiente;
    id = auxiliar->NumeroBici +1;
  }
  Archivo = fopen("bicis.txt", "at");
  system("clear");
  printf("\t\tDar de alta una nueva bicicleta\n");
  printf("\n");
  while(LBiciestaciones != NULL){
    printf("\t%ld-> %s\n", LBiciestaciones->NumBiciestacion, LBiciestaciones->NombreGenerico);
    LBiciestaciones = LBiciestaciones->siguiente;
  }

  while(validacion){
    validacion = Pedir_datos(NumBiciestacion, "de la lista anterior, el numero de biciestacion", 3);
    validacion = validarNumeros(NumBiciestacion, error);
    if(strlen(error) != 0)
      puts(error);
    error[0] = '\0';
  }
  anadirBici(id, NumBiciestacion, Lista, ListaBiciestaciones);
  fclose(Archivo);
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
void cargarListaBiciestacion(Biciestacion** Lista){
  char linea[500], Datos[6][200];
  int i, j = 0, contador = 0;
  FILE* Archivo = fopen("biciestaciones.txt", "rt");
  if (Archivo == NULL) {
    printf("Ha ocurrido un error, vuelva a intentar\n");
  }else{
    while (fgets(linea, 500, Archivo) != NULL) {
      Biciestacion* Nueva = (Biciestacion*)malloc(sizeof(Biciestacion));
      i = 0;
      contador = 0;
      separarListaUsuarios(&i, &j, &contador, linea, Datos);
      Nueva->NumBiciestacion = atoi(Datos[0]);
      strcpy(Nueva->NombreGenerico, Datos[1]);
      strcpy(Nueva->Calle, Datos[2]);
      Nueva->Numero = atoi(Datos[3]);
      Nueva->CP = atoi(Datos[4]);
      strcpy(Nueva->Ciudad, Datos[5]);
      Nueva->siguiente = NULL;
      if (*Lista == NULL) {
        *Lista = Nueva;
      }else{
        Biciestacion* aux = *Lista;
        while (aux->siguiente != NULL) {
          aux = aux->siguiente;
        }
        aux->siguiente = Nueva;
      }
    }
    fclose(Archivo);
  }
}
void cargarListaBicis(Bicicleta** Lista){
  char linea[500], Datos[6][200];
  int i, j = 0, contador = 0;
  FILE* Archivo = fopen("bicis.txt", "rt");
  if (Archivo == NULL) {
    printf("Ha ocurrido un error, vuelva a intentar\n");
  }else{
    while (fgets(linea, 500, Archivo) != NULL) {
      Bicicleta* Nueva = (Bicicleta*)malloc(sizeof(Bicicleta));
      i = 0;
      contador = 0;
      separarListaUsuarios(&i, &j, &contador, linea, Datos);
      Nueva->NumeroBici = atoi(Datos[0]);
      Nueva->Biciestacion = atoi(Datos[1]);
      Nueva->rentas = atoi(Datos[2]);
      strcpy(Nueva->Timestamp, Datos[3]);
      Nueva->siguiente = NULL;
      if (*Lista == NULL) {
        *Lista = Nueva;
      }else{
        Bicicleta* aux = *Lista;
        while (aux->siguiente != NULL) {
          aux = aux->siguiente;
        }
        aux->siguiente = Nueva;
      }
    }
  }
}
void anadirBici(int id, char NumeroBici[], Bicicleta** Lista, Biciestacion** ListaBiciestaciones){
  Bicicleta* Nueva = (Bicicleta*)malloc(sizeof(Bicicleta));
  Biciestacion* aux = *ListaBiciestaciones;
  int found = 0, numeroBiciestacion = atoi(NumeroBici), CuentaBici = 0;
  Nueva->NumeroBici = id;
  Nueva->rentas = 0;
  strcpy(Nueva->Timestamp, "NULL");
  Nueva->Biciestacion = numeroBiciestacion;
  Nueva->siguiente = NULL;
  while(aux != NULL){
    if(Nueva->Biciestacion == aux->NumBiciestacion)
      found = 1;
    aux = aux->siguiente;
  }
  if(found == 0)
    printf("No se pudo añadir porque no se encontro la biciestacion introducida\n");
}
void anadirBiciestacion(int id, char NombreGenerico[], char Calle[], char numero[], char cp[], char Ciudad[], Biciestacion** Lista){
  Biciestacion* Nueva = (Biciestacion*)malloc(sizeof(Biciestacion));
  Biciestacion* aux;
  Nueva->NumBiciestacion = id;
  strcpy(Nueva->NombreGenerico, NombreGenerico);
  strcpy(Nueva->Calle, Calle);
  Nueva->Numero = atoi(numero);
  Nueva->CP = atoi(cp);
  strcpy(Nueva->Ciudad, Ciudad);
  Nueva->siguiente = NULL;
  if (*Lista == NULL) {
    *Lista = Nueva;
  }else{
    aux = *Lista;
    while (aux->siguiente != NULL) {
      aux = aux->siguiente;
    }
    aux->siguiente = Nueva;
  }
}
void imprimirArchivos(Biciestacion** ListaBicis, Bicicleta** ListaBicicletas){
  Biciestacion* aux = *ListaBicis;
  Bicicleta* aux2 = *ListaBicicletas;
  FILE* Archivo = fopen("biciestaciones.txt", "wt");
  while (aux != NULL) {
    fprintf(Archivo, "%ld/%s/%s/%d/%d/%s/\n", aux->NumBiciestacion, aux->NombreGenerico, aux->Calle, aux->Numero, aux->CP, aux->Ciudad);
    aux = aux->siguiente;
  }
  fclose(Archivo);
  Archivo = fopen("bicis.txt", "wt");
  while(aux2 != NULL){
    fprintf(Archivo, "%ld/%ld/%ld/%s", aux2->NumeroBici, aux2->Biciestacion, aux2->rentas, aux2->Timestamp);
    aux = aux->siguiente;
  }
  fclose(Archivo);
}
//******************************************************************************
