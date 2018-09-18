#include <stdio.h>
int main(void){
  int Num;
  int Cont = 1;
  int L;
  printf("Ingresar numero: ");
  scanf("%d", &Num);
  for(int i = 2; i < Num; i++){
    if (Num % i == 0) {
      printf("No es primo\n");
      break;
    }else{
      Cont++;
    }
  }
  L = Num-2;
  //printf("%d y %d", L, Cont);
  if (L < Cont) {
    printf("Si es primo\n");
  }
}
