#include "mpi.h"
#include <stdio.h>
int main( int argc, char* argv[] ){
    int i;
    int idproceso, totalprocesos;
    int valor, suma=0;
 
    MPI_Init( &argc, &argv );
    MPI_Comm_size( MPI_COMM_WORLD, &totalprocesos );
    MPI_Comm_rank( MPI_COMM_WORLD, &idproceso);

    valor = idproceso + 1;
    printf("P%d tiene valor0 %d\n", idproceso, valor);
    MPI_Reduce(&valor, &suma, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); 
    if(idproceso == 0) {
            printf("La suma es %d\n", suma);
    }
    MPI_Finalize();
}
