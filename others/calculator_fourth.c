#include <mpi.h>
#include <stdio.h>

// how to run 
// mpicc file_name.c -o file_name
// mpirun -np 5 ./file_name

int main(int argc, char** argv) {
    int a = 10, b = 2, res;
    // scanf("%d%d", &a, &b); // problem appears

    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    // printf(MPI_MAX_PROCESSOR_NAME);

    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    switch (world_rank)
    {
        case 0:
            res = a + b;
            break;
        
        case 1:
            res = a - b;
            break;

        case 2:
            res = a * b; 
            break;
        case 3:
            res = a / b;
            break;

        default:
            res = -9999;
            break;
    }

    // Print off a hello world message
    if (res == -9999) {
        printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);
    }
    else {
        printf("Result is = %d [from processor %s, rank %d out of %d processors]\n",
           res, processor_name, world_rank, world_size);
    }
    

    // Finalize the MPI environment.
    MPI_Finalize();
}