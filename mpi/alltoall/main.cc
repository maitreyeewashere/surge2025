#include <mpi.h>
#include <iostream>

extern void* sstmac_nullptr_send;
extern void* sstmac_nullptr_recv;

int main(int argc, char** argv)
{
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0) {
    std::cout << "Starting all-to-all" << std::endl;
  }

  const int nelems_per_target = 4;

  void* send_buf = sstmac_nullptr_send;
  void* recv_buf = sstmac_nullptr_recv;

  MPI_Alltoall(send_buf, nelems_per_target, MPI_INT,
               recv_buf, nelems_per_target, MPI_INT,
               MPI_COMM_WORLD);

  MPI_Finalize();

  if (rank == 0) {
    std::cout << "Finalized" << std::endl;
  }

  return 0;
}
