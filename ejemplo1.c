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
      case 5:
        printf("\nHasta luego\n");
        break;
      default:
        printf("Ingresa una opcion valida\n");
    }
  } while(opcion != 5);
}

void MostrarMenu(){
  printf("Seleccione una opcion: \n");
  printf("1.- Circulo\n");
  printf("2.- Cuadrado\n");
  printf("3.- Rectangulo\n");
  printf("4.- Triangulo\n");
  printf("5.- Salir\n");
  printf("--> ");
}

void Circulo(float radio, float *area){
  *area = Pi*radio*radio;
  printf("El resultado es %.2f\n", *area);
}
void Cuadrado(float lado, float *area){
  *area = lado*lado;
  printf("El resultado es %.2f\n", *area);
}
void Rectangulo(float base, float altura, float *area){
  *area = base*altura;
  printf("El resultado es %.2f\n", *area);
}
void Triangulo(float base, float altura, float *area){
  *area = (base*altura)/2;
  printf("El resultado es %.2f\n", *area);
}
