#include <stdio.h>
#include <omp.h>
#include "mpi.h"

int main(int argc, char *argv[]) {
  int numprocs, rank, namelen;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int iam = 0, np = 1;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &namelen);

  #pragma omp parallel default(shared) private(iam, np)
  {
    np = omp_get_num_threads();
    iam = omp_get_thread_num();
    printf("Hola soy el hilo  %d de un total de  %d hilos pertenezco al  proceso %d que se ejecuta en la maquina %s  de un total de  %d procesos \n",iam, np, rank,  processor_name, numprocs);
  }

  MPI_Finalize();
}
