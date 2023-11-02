#include "mpi.h"
#include <stdio.h>

int main( int argc, char* argv[] ){
    int i;
    int N=10;
    int idproceso, totalprocesos;
    int inicio,fin;
    int bloques,residuo,adicional;
    MPI_Init( &argc, &argv );
    MPI_Comm_size( MPI_COMM_WORLD, &totalprocesos );
    MPI_Comm_rank( MPI_COMM_WORLD, &idproceso);
    bloques=N/totalprocesos;

    residuo=N%totalprocesos;

    inicio=idproceso*bloques;

    fin=inicio+bloques-1;

    if(residuo>0 && idproceso<residuo){
       adicional=N-idproceso-1;
       printf("Soy  %d mi rango es (%d , %d) adicional=%d\n", idproceso, inicio, fin,adicional);
    }else
       printf("Soy  %d mi rango es (%d , %d)\n", idproceso, inicio, fin);


    

   
    MPI_Finalize();
}
