#include <stdio.h>
int main(){
  int Sum = 0, Num;
  for(int i = 0; i < 10; i++){
    printf("Ingresar el valor %d: ", i+1);
    scanf("%d", &Num);
    Sum += Num;
  }
  printf("La suma es %d\n ", Sum);
  return 0;
}
