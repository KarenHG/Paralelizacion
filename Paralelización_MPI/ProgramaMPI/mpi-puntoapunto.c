#include <stdio.h>
#include <mpi.h>
#include <unistd.h>

#define EtiquetaRoja 1
#define EtiquetaBlanca 2

int  main (int argc, char *argv[])
{
MPI_Status status;
int  idproceso, totalprocesos;
int  A[]={0,0};
MPI_Init (&argc,&argv);
MPI_Comm_size (MPI_COMM_WORLD, &totalprocesos);  
MPI_Comm_rank (MPI_COMM_WORLD, &idproceso);

printf ("P%d de un total de %d procesos, la variable A = [%d, %d]\n", idproceso, totalprocesos, A[0], A[1]); 

if(idproceso==0){
	A[0]=8;
	A[1]=9;
	printf("P%d:Envio los datos [%d, %d]  al procesos 1\n", idproceso, A[0], A[1]);
	MPI_Send(A, 2, MPI_INT, 1,EtiquetaRoja, MPI_COMM_WORLD);
 }else{
	if(idproceso==1){
			printf("P%d:Recibiendo los datos desde el proceso 0..\n", idproceso);
			MPI_Recv (A,2,MPI_INT, 0, EtiquetaRoja, MPI_COMM_WORLD, &status);
	}
}

printf ("Proceso P%d  y en A=[%d, %d] \n", idproceso, A[0], A[1]); 
MPI_Finalize ();

}
