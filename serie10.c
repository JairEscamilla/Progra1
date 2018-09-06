#include <stdio.h>
int main(){
  int SumaPares = 0, SumaImpares = 0;
  for(int i = 1; i<= 200; i++){
    if (i%2 == 0) {
      SumaPares += i;
    }
  }
  for(int i = 1; i<= 200; i++){
    if (i%2 != 0) {
      SumaImpares += i;
    }
  }
  printf("La suma de numeros pares es %d\n", SumaPares);
  printf("La suma de numeros impares es %d\n", SumaImpares);
  return 0;
}
