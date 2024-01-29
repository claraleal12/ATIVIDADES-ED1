#include <stdio.h>
#include <math.h>

void calcula_hexagono (float lado, float *area, float *perimetro){
    *area = 3 * pow(lado, 2) * sqrt(3) / 2;
    *perimetro = 6 *lado;
}

int main(){
    float a, p, l;

    printf("Insira o comprimento do lado do hexágono:\n");
    scanf("%f", &l);

    calcula_hexagono(l, &a, &p);

    printf("Área = %.2f, Produto = %.2f\n", a, p);

return 0;
}