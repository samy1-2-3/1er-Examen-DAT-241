#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

#define tamVec 10
#define tamCad 20

int main(int argc, char *argv[]) {
    int rank, size;
    char vector[tamVec][tamCad];
 
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        for (int i = 0; i < tamVec; i++) {
            sprintf(vector[i], "Elemento %d", i);
        }
    }

    MPI_Bcast(vector, tamVec * tamCad, MPI_CHAR, 0, MPI_COMM_WORLD);

    for (int i = rank; i < tamVec; i += size) {
        if (rank == 1 && i % 2 == 0) {
            printf("Procesador 1 (par): %s\n", vector[i]);
        } else if (rank == 2 && i % 2 != 0) {
            printf("Procesador 2 (impar): %s\n", vector[i]);
        }
    }

    MPI_Finalize();
    return 0;
}
