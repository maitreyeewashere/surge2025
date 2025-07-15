#include<mpi.h>
#include<iostream>
#include<stddef.h>
#include<vector>


int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    // #define VALIDATE_BUFFERS
    const int nelems = 1;



    #ifdef VALIDATE_BUFFERS
    std::vector<int> buffer(nelems);

    if (rank == 0) {
        for (int i = 0; i < nelems; ++i) {
            buffer[i] = i;
        }
        std::cout << "Rank 0 broadcasting data...\n";
    }


    #else
    void* send_buf = sstmac_nullptr_send;

    #endif

    MPI_Bcast(send_buf, nelems, MPI_INT,0, MPI_COMM_WORLD);



    #ifdef VALIDATE_BUFFERS

    std::cout << "Rank " << rank << " received data: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << "...\n";

    #endif

    MPI_Finalize();

    if (rank == 0){
        std::cout << "Cleared finalize" << std::endl;
    }
    return 0;
}
