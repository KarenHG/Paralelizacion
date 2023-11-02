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
MPI_Init (&argc,&argv);
MPI_Comm_size (MPI_COMM_WORLD, &totalprocesos);  
MPI_Comm_rank (MPI_COMM_WORLD, &idproceso);
gethostname(nombre, sizeof(nombre));

printf ("Proceso P%d de un total de %d procesos y me ejecuto  en la maquina %s \n", idproceso, totalprocesos, nombre); 

if(idproceso==0){
	printf("P%d: El resultado de la suma de los %d numeros naturales es %d\n", idproceso, n, sumaNaturales(n));
}else{
	printf("P%d: El factorial de %d = %d \n", idproceso, n, factorial(n));

}

MPI_Finalize ();

}

int sumaNaturales( int n){
	int i;
	int suma=0;
	for(i=0; i<=n; i++){
		suma=suma+i;
	}
	return suma;
}
int factorial(int n){
	int i;
	int factorial=1;
	for(i=1; i<=n; i++){
		factorial=factorial*i;
	}
	return factorial;

}
