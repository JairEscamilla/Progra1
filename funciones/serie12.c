#include <stdio.h> // Incluyo las librerias
// Prototipos de funciones
void procesar(int*, int*);
// Funcion principal
int main(void){
  int Numero, Suma = 0;
  for(int i = 0; i < 10; i++){
    procesar(&Numero, &Suma);
  }
  printf("La suma de los numeros es %d\n", Suma);
}

// Desarrollando las funciones
void procesar(int* Numero, int* Suma){
  printf("Ingresar numero: ");
  scanf("%d", Numero);
  *Suma += *Numero;
}
