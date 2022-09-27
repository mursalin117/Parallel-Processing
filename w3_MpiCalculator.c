#include <stdio.h>
#include <mpi.h>

void getInput(int world_rank, int world_size, int* a, int* b) {
    if (world_rank == 0) {
        printf("Enter two number:\n");
        scanf("%d%d", a, b);
        for (int i = 1; i < world_size; i++) {
            MPI_Send(a, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(b, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        MPI_Recv(a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
}

int main(int argc, char const *argv[]) {
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
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    int a, b;
    getInput(world_rank, world_size, &a, &b);

    // Print off a hello message
    if (world_rank == 0) {
        printf("Hello world from processor %s, rank %d out of %d processors\n", processor_name, world_rank, world_size);
    } else if (world_rank == 1) {
        printf("Addition = %d [processor=%s, rank=%d/%d]\n", a+b, processor_name, world_rank, world_size);
    } else if (world_rank == 2) {
        printf("Subtraction = %d [processor=%s, rank=%d/%d]\n", a-b, processor_name, world_rank, world_size);
    } else if (world_rank == 3) {
        printf("Multiplication = %d [processor=%s, rank=%d/%d]\n", a*b, processor_name, world_rank, world_size);
    } else if (world_rank == 4) {
        printf("Division = %d [processor=%s, rank=%d/%d]\n", a/b, processor_name, world_rank, world_size);
    } else {
        printf("Nothing to do [processor=%s, rank=%d/%d]\n", processor_name, world_rank, world_size);
    }

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}
