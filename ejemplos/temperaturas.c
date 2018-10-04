#include <stdio.h>
// Prototipos de funciones
void may(int[], int*);
void men(int[], int*);
void media(int[], float*);
void desplegar(int[]);
// Funcion principal
int main(void){
  int Temp[23], May, Men;
  float Prom;
  for(int i = 0; i < 24; i++){
    printf("Ingresar la temperatura %d: ", i+1);
    scanf("%d", &Temp[i]);
  }
  May = Temp[0];
  Men = Temp[0];
  may(Temp, &May);
  men(Temp, &Men);
  media(Temp, &Prom);
  desplegar(Temp);
  printf("La mayor temperatura es %d\nLa menor temperatura es %d\nEl promedio de temperaturas es %.2f\n", May, Men, Prom);
}
// Desarrollando las funciones
void may(int Array[], int* Mayor){
  for(int i = 0; i < 24; i++){
    if (Array[i] > *Mayor) {
      *Mayor = Array[i];
    }
  }
}

void men(int Array[], int* Menor){
  for(int i = 0; i < 24; i++){
    if (Array[i] < *Menor) {
      *Menor = Array[i];
    }
  }
}

void media(int Array[], float* Prom){
  int Sum = 0;
  for(int i = 0; i < 24; i++){
    Sum += Array[i];
  }
  *Prom = Sum/24.0;
}

void desplegar(int Array[]){
  printf("Las temperaturas son: ");
  for(int i = 0; i < 24; i++){
    printf("%d, ", Array[i]);
  }
  printf("\n");
}
