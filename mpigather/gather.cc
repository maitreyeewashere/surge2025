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
    std::vector<int> send_buf(nelems);
    for (int i = 0; i < nelems; ++i) {
        send_buf[i] = rank;
    }

    std::vector<int> recv_buf; 
    if (rank == 0) {
        recv_buf.resize(nelems * size); 
    }

    #else
    void* send_buf = sstmac_nullptr_send;
    void* recv_buf = sstmac_nullptr_recv;

    #endif

    MPI_Gather(send_buf, nelems, MPI_INT,
               recv_buf, nelems, MPI_INT,
               0, MPI_COMM_WORLD);



    #ifdef VALIDATE_BUFFERS

    if (rank == 0) {
        std::cout << "Gathered data:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "From rank " << i << ": ";
            for (int j = 0; j < nelems; ++j) { 
                std::cout << recv_buf[i * nelems + j] << " ";
            }
            std::cout << "\n";
        }
    }

    #endif

    MPI_Finalize();

    if (rank == 0){
        std::cout << "Cleared finalize" << std::endl;
    }
    return 0;
}
