#include <stdio.h>

void calcularPi(int *n, double *pi, int i, double signo) {
    if (i >= *n) {
        *pi *= 4;  
        return;
    }

    *pi += signo / (2 * i + 1);  
    calcularPi(n, pi, i + 1, -signo);
}

int main() {
    int iteraciones;
    double pi = 0.0;

    printf("Ingrese el numero de iteraciones: ");
    scanf("%d", &iteraciones);

    calcularPi(&iteraciones, &pi, 0, 1.0);
    printf("Valor aproximado de Pi (recursivo): %lf\n", pi);

    return 0;
}
