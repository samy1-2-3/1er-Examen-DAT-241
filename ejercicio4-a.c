#include <stdio.h>

void calcularPi(int *n, double *pi) {
    *pi = 0.0;
    double signo = 1.0;

    for (int i = 0; i < *n; i++) {
        *pi += signo / (2 * i + 1); 
        signo = -signo;  
    }
    *pi *= 4; 
}

int main() {
    int iteraciones;
    double pi;

    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &iteraciones);

    calcularPi(&iteraciones, &pi);
    printf("Valor aproximado de Pi (iterativo): %lf\n", pi);

    return 0;
}
