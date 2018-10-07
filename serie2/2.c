#include <stdio.h>
// Prototipos de funciones
void leer(int[], int);
void media(int[], float*, int);
void ctemp(int[], float, int*, int);
// Funcion principal
int main(void){
  int Cant;
  int Array[95];
  float Med;
  int Ctemp = 0;
  do {
    printf("Ingresar cantidad de temperaturas: ");
    scanf("%d", &Cant);
    if (Cant < 5 || Cant > 100) {
      printf("Debe ingresar un valor entre 5 y 100\n");
    }
  } while(Cant < 5 || Cant > 100);

  leer(Array, Cant);
  media(Array, &Med, Cant);
  ctemp(Array, Med, &Ctemp, Cant);
  printf("La media de las temperaturas es %.2f\nLa cantidad de temperaturas mayores a la media son: %d\n", Med, Ctemp);
}
// Desarrollando las funciones
void leer(int Array[], int Cant){
  for(int i = 0; i < Cant; i++){
    printf("Ingresar la temperatura %d: ", i+1);
    scanf("%d", &Array[i]);
  }
}

void media(int Array[], float* Media, int Cant){
  int Sum = 0;
  for(int i = 0; i < Cant; i++){
    Sum += Array[i];
  }
  *Media = Sum/(Cant*1.0);
}

void ctemp(int Array[], float Med, int* Ctemp, int Cant){
  for(int i = 0; i < Cant; i++){
    if (Array[i] >= Med) {
      (*Ctemp)++;
    }
  }
}
