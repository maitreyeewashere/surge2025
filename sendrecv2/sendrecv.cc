#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
//#include "hopstats.h"

int main(int argc, char** argv) {
    int rank, size;

    double tic, toc, elapsed;
    MPI_Status status;

    MPI_Init(&argc, &argv);                
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  //this process's rank

    size = 16;

    int half = size / 2;
    int partner;

    if (rank < half) {
        partner = rank + half;
        int message = rank * 10;

        tic = MPI_Wtime(); 

        MPI_Send(&message, 1, MPI_INT, partner, 0, MPI_COMM_WORLD);

        int reply;
        //MPI_Recv(&reply, 1, MPI_INT, partner, 0, MPI_COMM_WORLD, &status);

        toc = MPI_Wtime();
        elapsed = toc - tic;

        printf("\n[Rank %d] Sent %d to %d, received reply %d. Latency = %.6f seconds\n",
               rank, message, partner, reply, elapsed);
        fflush(stdout);
    } else {
        partner = rank - half;
        int recv_message;

        MPI_Recv(&recv_message, 1, MPI_INT, partner, 0, MPI_COMM_WORLD, &status);

        int reply = recv_message + 1;

        MPI_Send(&reply, 1, MPI_INT, partner, 0, MPI_COMM_WORLD);

        printf("\n[Rank %d] Received %d from %d, sent reply %d\n",
               rank, recv_message, partner, reply);
        fflush(stdout);
    }
//dumpHopData("../output/hops_output.csv");
    MPI_Finalize();  
    return 0;
}
