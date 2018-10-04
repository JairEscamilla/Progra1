#include <stdio.h>
// Prototipos de funciones
void ordenar(int[], int);
void desplegar(int[], int);
// Funcion principal
int main(void){
  int Cant;
  int Array[100];
  do{
    printf("Ingresar cantidad de numeros: ");
    scanf("%d", &Cant);
  }while(0< Cant > 100);
  for(int i = 0; i < Cant; i++){
    printf("Ingresar valor %d: ", i+1);
    scanf("%d", &Array[i]);
    ordenar(Array, i);
  }
  desplegar(Array, Cant);
}

// Desarrollando las funciones
void ordenar(int Array[], int i){
  int Aux = 0;
  for(int j = 0; j <= i; j++){
    for(int k = 0; k <= i; k++){
      if (Array[j] > Array[k]) {
        Aux = Array[j];
        Array[j] = Array[k];
        Array[k] = Aux;
      }
    }
  }
}

void desplegar(int Array[], int Cant){
  printf("La lista ordenada es: ");
  for(int i = Cant-1; i >= 0; i--){
    printf("%d, ", Array[i]);
  }
  printf("\n");
}
