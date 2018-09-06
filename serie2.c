#include <stdio.h>
int main(){
  for (int i = 3; i <= 99; i+= 3) {
    printf("%d, ", i);
    if (i == 99) {
      printf("\n");
    }
  }
  return 0;
}
