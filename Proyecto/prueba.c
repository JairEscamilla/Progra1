#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  char Nombre[20];
  Nombre[0] = 'a';
  int i = 0;
  printf("Ingresar nombre: ");
  while((Nombre[i]=getchar())!='\n' ){
          if(i < 5)
            printf( "%c", Nombre[i] );
          else{
            printf("Haz alcanzado el limite\n");
            Nombre[i] = '\n';
          }
          i++;
     }
}
