#include <stdio.h>
int main(){
  int Cant = 0, Values[100];
  int Aux = 0;
  printf("Ingrese la cantidad de valores: ");
  scanf("%d", &Cant);
  for(int i = 0; i < Cant; i++){
    printf("Ingresar valor %d: ", i+1);
    scanf("%d", &Values[i]);
  }
  // Vamos a ordenar

  for(int i = 0; i < Cant; i++){
    for(int k = 0; k < Cant; k++){
      if (Values[k] > Values[i]) {
        Aux = Values[i];
        Values[i] = Values[k];
        Values[k] = Aux;
      }
    }
  }

  printf("Los valores ordenados son: ");
  // Desplegamos el array ordenado
  for(int i = 0; i < Cant; i++){
    printf("%d, ", Values[i]);
  }
  printf("\n");
}
