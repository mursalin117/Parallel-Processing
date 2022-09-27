#include <mpi.h>
#include <stdio.h>

// how to run 
// mpicc file_name.c -o file_name
// mpirun -np 5 ./file_name

int main(int argc, char** argv) {
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
    // printf("%s\n", processor_name); // ---> name got but not showing

    int name_len;
    MPI_Get_processor_name(processor_name, &name_len); // name of the processor got successfully
    // printf("Processor Name %d\n", name_len);

    // printf("%s\n", processor_name);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();

    return 0;
}