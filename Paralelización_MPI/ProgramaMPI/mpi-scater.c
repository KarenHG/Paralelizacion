#include <stdio.h> 
#include <mpi.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define tam 10
int main(int argc, char * argv[]){
int  i, idproceso, totalproc;
int origen[10], *destino=NULL;
int tamDest;
MPI_Init (&argc, &argv);
MPI_Comm_rank (MPI_COMM_WORLD, &idproceso);
MPI_Comm_size(MPI_COMM_WORLD,&totalproc);
if(idproceso == totalproc-1){
	for(i=0; i<tam; i++){
	
	origen[i]= (i*2)+1;
	printf("[%d]\n", origen[i]);
	
	}
}

tamDest= tam/totalproc;
if(idproceso==0){
	printf("El valor de tamDes es %d\n", tamDest);
}

destino=(int*)calloc(tamDest, sizeof(int));
for(i=0; i<tamDest; i++){
		destino[i]= -1;
}
MPI_Scatter (origen, tamDest, MPI_INT, destino, tamDest,MPI_INT, totalproc-1, MPI_COMM_WORLD);

printf("Soy el proceso %d y recibi: ", idproceso);
for(i=0; i<tamDest; i++){
	printf("%d-", destino[i]);
}
printf("\n");

MPI_Finalize();



}
