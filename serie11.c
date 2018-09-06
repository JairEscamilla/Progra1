#include <stdio.h>
int main(){
  int Num, May = 0;
  do {
    printf("Ingresar numero: ");
    scanf("%d", &Num);
    if (Num > 0) {
      if (Num > May) {
        May = Num;
      }
    }else{
      if (Num == -99) {
        printf("\n");
      }else{
        printf("Ingresa un valor positivo distinto de 0\n");
      }
    }
  } while(Num != -99);
  printf("El numero mayor es %d\n", May);
  return 0;
}
