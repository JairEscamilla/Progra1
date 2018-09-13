#include <stdio.h> // Incluyo la libreria de entrada y salida
// Prototipos de funciones
void getW(float*);
void toKg(float, float*);
void toG(float, float*);
// Funcion principal
int main(void){
  float W, Kg, G;
  getW(&W);
  toKg(W, &Kg);
  toG(Kg, &G);
  printf("Kilogramos: %f\n. Gramos: %f\n", Kg, G);
}

// Desarrollando las funciones
void getW(float* W){
  printf("Ingresar peso en libras: ");
  scanf("%f", W);
}

void toKg(float W, float* Kg) {
  // 1lb ->  0.45359 kg
  // nlb -> x Kg
}

/* Fundamentos -> Lab -> Practica1 (Aquí van a estar todos los ejercicios )
  1.c
  1.exe
  2.c
  2.exe
  3.c
  3.exe
  Y así de manera sucesiva

*/
