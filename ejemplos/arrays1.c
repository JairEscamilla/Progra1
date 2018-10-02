#include<stdio.h>
int main(){
    int Array[10];
    int Sum = 0, May = 0, Men = 0;
    float Prom;
    for(int i = 0; i < 10; i++){
      printf("Ingresar valor %d: ", i+1);
      scanf("%d", &Array[i]);
    }
    Men = Array[0];
    for(int k = 0; k < 10; k++){
      Sum += Array[k];
      if (Array[k] > May) {
        May = Array[k];
      }
      if (Array[k] < Men) {
        Men = Array[k];
      }
    }
    Prom = Sum/10.0;
    printf("La sumatoria: %d\nPromedio: %.2f\nMayor: %d\nMenor: %d\n", Sum, Prom, May, Men);
}
