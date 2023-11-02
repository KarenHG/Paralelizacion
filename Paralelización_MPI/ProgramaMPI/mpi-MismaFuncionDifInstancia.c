#include <stdio.h> 
#include <mpi.h>
#include <unistd.h>

int sumaNaturales( int n);
int factorial(int n);

int  main (int argc, char *argv[])
{
int  idproceso, totalprocesos;
char nombre[250];
int n=5;
int m=3;
MPI_Init (&argc,&argv);
MPI_Comm_size (MPI_COMM_WORLD, &totalprocesos);  
MPI_Comm_rank (MPI_COMM_WORLD, &idproceso);
gethostname(nombre, sizeof(nombre));

printf ("Proceso P%d de un total de %d procesos y me ejecuto  en la maquina %s \n", idproceso, totalprocesos, nombre); 

if(idproceso==0){
	printf("P%d: El factorial de %d = %d \n", idproceso, n, factorial(n));
}else{
	printf("P%d: El factorial de %d = %d \n", idproceso, m, factorial(m));

}

MPI_Finalize ();

}


int factorial(int n){
	int i;
	int factorial=1;
	for(i=1; i<=n; i++){
		factorial=factorial*i;
	}
	return factorial;

}
