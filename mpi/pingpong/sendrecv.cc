#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int rank, size;

    double tic, toc, elapsed;
    MPI_Status status;

    MPI_Init(&argc, &argv);                
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  
    size = 16;
    int half = size / 2;
    int partner;

    if (rank < half) {
        partner = rank + half;
        int message = rank * 10;

        tic = MPI_Wtime();

        MPI_Send(&message, 1, MPI_INT, partner, 0, MPI_COMM_WORLD);
        int reply;
        MPI_Recv(&reply, 1, MPI_INT, partner, 0, MPI_COMM_WORLD, &status);

        toc = MPI_Wtime();
        elapsed = toc - tic;

        printf("[Rank %d] Sent %d to %d. Latency = %.6f seconds\n",
               rank, message, partner,elapsed);
        fflush(stdout);
    } else {
        
        partner = rank - half;
        int recv_message;

        MPI_Recv(&recv_message, 1, MPI_INT, partner, 0, MPI_COMM_WORLD, &status);

        int reply = recv_message + 1;

        MPI_Send(&reply, 1, MPI_INT, partner, 0, MPI_COMM_WORLD);

        printf("[Rank %d] Received %d from %d\n",
               rank, recv_message, partner);
        fflush(stdout);
    }
    MPI_Finalize();  
    return 0;
}
