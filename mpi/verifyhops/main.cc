#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 1) {
        int msg = 99;
        MPI_Send(&msg, 1, MPI_INT, 14, 0, MPI_COMM_WORLD);
        MPI_Recv(&msg, 1, MPI_INT, 14, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("[Rank %d] Sent and received %d to/from rank 14\n", rank, msg);
    } else if (rank == 14) {
        int msg;
        MPI_Recv(&msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&msg, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        printf("[Rank %d] Received and sent back %d to rank 1\n", rank, msg);
    }

    MPI_Finalize();
    return 0;
}
