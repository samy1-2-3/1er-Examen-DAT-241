#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4  

void multiplicar(int A[][N], int B[][N], int C[][N], int filas, int infila) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;  
            for (int k = 0; k < N; k++) {
                C[i][j] += A[infila + i][k] * B[k][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    int A[N][N], B[N][N], C[N][N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
      
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i][j] = i + 1; 

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                B[i][j] = i + 1;  
    }

    MPI_Bcast(B, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    int filasXpro = N / size;
    int local_A[filasXpro][N];
    int local_C[filasXpro][N]; 

    MPI_Scatter(A, filasXpro * N, MPI_INT, local_A, filasXpro * N, MPI_INT, 0, MPI_COMM_WORLD);

    multiplicar(local_A, B, local_C, filasXpro, rank * filasXpro);

    MPI_Gather(local_C, filasXpro * N, MPI_INT, C, filasXpro * N, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Resultado de la multiplicación de matrices:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}
