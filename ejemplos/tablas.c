#include <stdio.h>
void calcula(int);
int main(void){
  for(int i = 1; i <= 20; i++){
    calcula(i);
    printf("\n");
  }
}

void calcula(int Num){
  printf("Tabla del %d\n", Num);
  for(int i = 1; i <= 10; i++){
    printf("%d * %d = %d", Num, i, Num*i);
    printf("\n");
  }
}
