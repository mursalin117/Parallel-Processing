#include <stdio.h>
#include <mpi.h>

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

    int n = 12, partition = 12 / 4;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int total = 0, tempTotal = 0;

    // Print off a hello message
    if (world_rank == 0) {
        for (int i = 1; i < world_size; i++) {
            MPI_Send(arr + (i - 1) * partition, partition, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        for (int i = 1; i < world_size; i++) {
            MPI_Recv(&tempTotal, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total += tempTotal;
        }
        printf("Total sum = %d [processor=%s, rank=%d/%d processors]\n", total, processor_name, world_rank, world_size);
    } else {
        int tempArr[partition];
        MPI_Recv(&tempArr, partition, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (int i = 0; i < partition; i++) {
            tempTotal += tempArr[i];
        }
        MPI_Send(&tempTotal, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Temporary sum = %d [processor=%s, rank=%d/%d processors]\n", tempTotal, processor_name, world_rank, world_size);
    }

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}
