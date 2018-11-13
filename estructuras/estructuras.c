// Conjunto de elementos heterogeneos qye se agrupa con el fin de ser tratados como un solo tipo de datos coherente
// No es otra cosa que una variable que agrupa piezas de informacion relacionadas entre sí, llamadas miembros (o campos).
// cuyos tippos de datos pueden ser diferentes, en una variable

/* Va antes de los prototipos
  EJEMPLO:
  struct def_empleado{
    char Nombre[20];
    float Sueldo;
    int NumEmpleado;
};

int main(){
  struct def_empleado Empleado1;


}


Para declarar el tipo de dato
typedef struct def_empleado TipoEmpleado;
y se puede declarar como :
TipoEmpleado Empleado;

Pra mas facil, puedo hacer lo siguiente:
typedef struct defEmpleado <- Este es el nombre de la estructura{
  char nombre[20];
  float sueldo;
  int id;
}TipoEmpleado <- Este es el nombre del tipo;
Con estructuras si podemos hacer esto-> Empleado1 = Empleado2


Para apuntadores:
(*Otroempleado).sueldo
o
Otroempleado -> sueldo
Tambien puedo usar arreglos
*/
#include <stdio.h>
#include <string.h>
// Leer datos, imprimir, y calcular promedio
typedef struct defAlumno{
    char nombre[50];
    char cuenta[50];
    float cal1, cal2, cal3;
}tipoAlumno;

// PROTOTIPOS
void Leer(tipoAlumno[]);
void Imprimir(tipoAlumno[]);
// FUNCION PRINCIPAL
int main(){
  tipoAlumno Alumnos[5];
  Leer(Alumnos);
  Imprimir(Alumnos);
  return 0;
}

// Desarrollando las funciones
void Leer(tipoAlumno Alumnos[]){
  for(int i = 0; i < 5; i++){
    printf("Ingresar nombre del alumno %d: ", i+1);
    __fpurge(stdin);
    gets(Alumnos[i].nombre);
    //gets(Alumnos[i].nombre);
    printf("Ingresar cuenta del alumno %d: ", i+1);
    gets(Alumnos[i].cuenta);
    printf("Ingresar calif 1: ");
    scanf("%f", &Alumnos[i].cal1);
    printf("Ingresar calif 2: ");
    scanf("%f", &Alumnos[i].cal2);
    printf("Ingresar calif 3: ");
    scanf("%f", &Alumnos[i].cal3);
  }
}

void Imprimir(tipoAlumno Alumnos[]){
  float promedio;
  for(int i = 0; i < 5; i++){
    printf("Nombre %d: %s\n", i+1, Alumnos[i].nombre);
    printf("Cuenta %d: %s\n", i+1, Alumnos[i].cuenta);
    printf("Cal1: %f\n", Alumnos[i].cal1);
    printf("Cal2: %f\n", Alumnos[i].cal2);
    printf("Cal3: %f\n", Alumnos[i].cal3);
    promedio = (Alumnos[i].cal1 + Alumnos[i].cal2 + Alumnos[i].cal3)/3;
    printf("El promedio es %f\n", promedio);
  }
}
