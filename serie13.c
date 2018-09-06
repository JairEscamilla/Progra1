#include <stdio.h>
int main(){
  int Num, SumaPares = 0, CuentaPares = 0;
  int SumaImpares = 0, CuentaImpares = 0;
  float PromImpares;
  for(int i = 0; i < 10; i++){
      printf("Ingresar el numero %d: ", i+1);
      scanf("%d", &Num);
      if (Num%2 == 0) {
        SumaPares+= Num;
        CuentaPares+= 1;
      }else{
        SumaImpares+= Num;
        CuentaImpares+= 1;
      }
  }
  PromImpares = (SumaImpares*1.0)/(CuentaImpares*1.0);
  printf("Suma de pares= %d\n", SumaPares);
  printf("Cuenta de pares= %d\n", CuentaPares);

  printf("Suma de impares= %d\n", SumaImpares);
  printf("Cuenta de impares= %d\n", CuentaImpares);
  printf("La media aritmetica de los impares es %.2f\n", PromImpares);

  return 0;
}
// letra = getchar();
// putchar(letra);
