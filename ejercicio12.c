#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    
    printf("Ingrese la cantidad de digitos a imprimir a la serie fibonacci: ");
    scanf("%d", &n);
    
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    #pragma omp parallel for shared(fib, n)
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }

    printf("\n");

    return 0;
}
