#include "mpi.h"
#include <stdio.h>

int main( int argc, char* argv[] ){
    int i;
    int idproceso, totalprocesos;
    int isend, irecv[25];
 
    MPI_Init( &argc, &argv );
    MPI_Comm_size( MPI_COMM_WORLD, &totalprocesos );
    MPI_Comm_rank( MPI_COMM_WORLD, &idproceso);

    isend = idproceso + 1;
	//int MPI_Gather(const void *sendbuf,int sendcount,MPI_Datatype sendtype,void *recvbuf,int recvcount,MPI_Datatype sendtype,int root,MPI_Comm comm)
    MPI_Gather( &isend, 1, MPI_INT, irecv, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(idproceso == 0) {
        for(i=0; i<totalprocesos; i++)
            printf("irecv = %d\n", irecv[i]);
        }
    MPI_Finalize();
}
