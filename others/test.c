#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv){
    int process_Rank, size_Of_Cluster;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);

    if (process_Rank == 0){
        printf("Hello\n");
    }
    else if (process_Rank == 1){
        printf("Hi\n");
    }
    else {
        printf("Bye\n");
    }

    MPI_Finalize();
    
    return 0;
}