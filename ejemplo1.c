#include <stdio.h>
#define Pi 3.141592
void MostrarMenu(void);
void Cuadrado(float lado, float *area);
void Circulo(float radio, float *area);
void Rectangulo(float base, float altura, float *area);
void Triangulo(float base, float altura, float *area);
int main(void){
  float area, lado1, lado2;
  float radio;
  int opcion;
  int resp = 0;
  do {
    MostrarMenu();
    scanf("%d", &opcion);
    switch (opcion) {
      case 1:
        printf("Introduzca el radio del circulo: ");
        scanf("%f", &radio);
        Circulo(radio, &area);
        break;
      case 2:
        printf("Introduzca el lado del Cuadrado: ");
        scanf("%f", &lado1);
        Cuadrado(lado1, &area);
        break;
      case 3:
        printf("Ingresar base y altura del rectangulo: ");
        scanf("%f %f", &lado1, &lado2);
        Rectangulo(lado1, lado2, &area);
        break;
      case 4:
        printf("Ingresar la base y la altura del Triangulo: " );
        scanf("%f %f", &lado1, &lado2);
        Triangulo(lado1, lado2, &area);
        break;
      default:
        printf("Ingresa una opcion valida\n");
    }
    printf("El resultado es %.2f\n", area);
    printf("Ingresa 0 si quieres realizar otra operacion, de lo contrario presiona otra tecla--> ");
    scanf("%d", &resp);
  } while(resp == 0);
}

void MostrarMenu(){
  printf("Seleccione una opcion: \n");
  printf("1.- Circulo\n");
  printf("2.- Cuadrado\n");
  printf("3.- Rectangulo\n");
  printf("4.- Triangulo\n");
  printf("--> ");
}

void Circulo(float radio, float *area){
  *area = Pi*radio*radio;
}
void Cuadrado(float lado, float *area){
  *area = lado*lado;
}
void Rectangulo(float base, float altura, float *area){
  *area = base*altura;
}
void Triangulo(float base, float altura, float *area){
  *area = (base*altura)/2;
}
