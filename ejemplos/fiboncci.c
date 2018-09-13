#include <stdio.h>
void getNum(int*);
void calc(int);
int main(void) {
  int Num = 0;
  getNum(&Num);
  calc(Num);
}
void getNum(int* Num){
  printf("Ingresar numero: ");
  scanf("%d", Num);
}
void calc(int Num){
  int a = 0, b = 1, c = 0;
  int aux = 0;
  printf("%d, ", a);
  printf("%d, ", b);
  for(int i = 0; i <= Num; i++){
    c = a+b;
    printf("%d, ", c);
    a = b;
    b = c;
  }
  printf("\n");
}
