#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 10 

int main(int argc, char *argv[]) {
    int rank, size;
    int vectorA[N], vectorB[N], resultado[N];
    int sumaLocal = 0;


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {

        for (int i = 0; i < N; i++) {
            vectorA[i] = i + 1; 
            vectorB[i] = i + 11; 
        }
    }


    MPI_Bcast(vectorA, N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(vectorB, N, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = rank; i < N; i += size) {
        if (rank == 1 && i % 2 != 0) { 
            sumaLocal += vectorA[i] + vectorB[i];
        } else if (rank == 2 && i % 2 == 0) { 
            sumaLocal += vectorA[i] + vectorB[i];
        }
    }


    MPI_Reduce(&sumaLocal, &resultado[0], 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            resultado[i] = vectorA[i] + vectorB[i]; 
        }
        printf("Suma de vectores:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
