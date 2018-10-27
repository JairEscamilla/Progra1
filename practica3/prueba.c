#include <stdio.h>
int main(void){
  char c;
  char Laberinto[30][30];
  FILE* arch = fopen("laberinto.txt", "r+b");
  int i = 0, j = 0;
  do {
    do {
      fread(&c, sizeof(char), 1, arch);
      Laberinto[i][j] = c;
      //sprintf("%c", c );
      j++;
    } while(c != '\n');
    Laberinto[i][j+1] = '\0';
    i++;
  } while(!feof(arch));

  int h = 0, k = 0;
  while (!feof(arch)) {
    while (Laberinto[h][k] != '\n') {
      printf("%c", Laberinto[h][k]);
      k++;
    }
    h++;
  }

  /*
  for(int i = 0; Laberinto[i][j] != '\0'; i++){
    printf("\n");
    for(int j = 0; Laberinto[i][j] != '\0'; j++){
      printf("%c", Laberinto[i][j]);
    }
  }
*/
  return 0;
}
