#include <stdio.h> 
#include <mpi.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define tam 400
int main(int argc, char * argv[]){
int  i, idproceso, totalproc;
int origen[400], *destino=NULL;
int tamDest;
int suma=0;
char nombre[250];
int id, total=0;
MPI_Init (&argc, &argv);
MPI_Comm_rank (MPI_COMM_WORLD, &idproceso);
MPI_Comm_size(MPI_COMM_WORLD,&totalproc);
gethostname(nombre, sizeof(nombre));
if(idproceso == totalproc-1){
	for(i=0; i<tam; i++){
	
	origen[i]=i;
	//printf("[%d]\n", origen[i]);
	
	}
}
printf("\n");

tamDest= tam/totalproc;

destino=(int*)calloc(tamDest, sizeof(int));
for(i=0; i<tamDest; i++){
		destino[i]= -1;
}
MPI_Scatter (origen, tamDest, MPI_INT, destino, tamDest,MPI_INT, totalproc-1, MPI_COMM_WORLD);

printf("Soy el proceso %d en la maquina %s recibi: ", idproceso, nombre );


for(i=0; i<tamDest; i++){
	printf("%d-", destino[i]);
}



     #pragma omp parallel for reduction(+:suma)
     for(i=0;i<=tamDest;i++){
      	suma=suma+destino[i];
     }
     printf("\nSoy el proceso %d  y mi Suma Final: %d\n",idproceso, suma);


    MPI_Reduce(&suma, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); 
    if(idproceso == 0) {
            printf("La suma de todos los elementos  es %d\n", total);
    }


MPI_Finalize();



}
