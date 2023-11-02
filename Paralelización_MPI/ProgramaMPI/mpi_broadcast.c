#include <stdio.h> 
#include <stdio.h>
#include <mpi.h>
#include <unistd.h>



int  main (int argc, char *argv[])
{
int  idproceso, totalprocesos;
double  var1=0;;
MPI_Init (&argc,&argv);
MPI_Comm_size (MPI_COMM_WORLD, &totalprocesos);  
MPI_Comm_rank (MPI_COMM_WORLD, &idproceso);

printf ("P%d de un total de %d procesos y var1= %lf]\n", idproceso, totalprocesos, var1); 

if(idproceso== 4){
	var1=3.1416;
}

MPI_Bcast(&var1,1,MPI_DOUBLE, 4, MPI_COMM_WORLD);

printf ("P%d de un total de %d procesos y var1= %lf] despues del broadcast\n", idproceso, totalprocesos, var1); 
MPI_Finalize ();

}
