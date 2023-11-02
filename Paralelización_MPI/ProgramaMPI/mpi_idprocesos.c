#include <stdio.h> 
#include <mpi.h>
#include <unistd.h>

int  main (int argc, char *argv[])
{
int  idproceso, totalprocesos;
char nombre[250];
MPI_Init (&argc,&argv);
MPI_Comm_size (MPI_COMM_WORLD, &totalprocesos);  
MPI_Comm_rank (MPI_COMM_WORLD, &idproceso);
gethostname(nombre, sizeof(nombre));
printf ("Proceso P%d de %d y me ejecuto  en la maquina %s \n", idproceso, totalprocesos, nombre); 
MPI_Finalize ();

}
