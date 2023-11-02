#include <math.h>
#include <stdio.h>
#include <omp.h>
#include <mpi.h>
#include <unistd.h>

#define INICIO 1.0f 
#define FIN 3.0f 
#define PARTICIONES 999999999 
#define DELTA ((FIN-INICIO)/PARTICIONES) 

int main(int argc, char *argv[]) {
MPI_Status status;
  int rank, nprocs, leng;
  int inicio, fin;
  int bloques, residuo, adicional;
  double suma=0;
  double sumal=0;
  double sumal1=0;
  double sumal2=0;
  int i;
  MPI_Init (&argc,&argv);
MPI_Comm_size (MPI_COMM_WORLD, &nprocs); 

MPI_Comm_rank (MPI_COMM_WORLD, &rank);
bloques=PARTICIONES/nprocs;
residuo=PARTICIONES%nprocs;
inicio=rank*bloques+1;
fin=inicio+bloques;
if(residuo>0 &&rank<residuo){
adicional=PARTICIONES-rank;
sumal=sumal+(DELTA*(pow((INICIO+(DELTA*adicional)),2)+1));
printf("Soy %d mi rango es (%d, %d) adicional= %d\n",rank, inicio, fin, adicional );

}else{
 printf("Soy %d mi rango es (%d, %d)\n",rank, inicio, fin );
 
}

for(i=inicio; i<fin; i++){
  sumal=sumal+(DELTA*(pow((INICIO+(DELTA*i)),2)+1));
}
if(rank<nprocs-1){
	MPI_Send(&sumal, 1, MPI_DOUBLE, nprocs-1, 1, MPI_COMM_WORLD);
 }else{
	if(rank==nprocs-1){
	for(i=0; i<nprocs-1; i++)
	{
			MPI_Recv (&sumal1,1,MPI_DOUBLE, i, 1, MPI_COMM_WORLD, &status);
			sumal2=sumal2+sumal1;
			}			
	}
}
MPI_Barrier (MPI_COMM_WORLD);
if(rank==nprocs-1)
    suma=sumal+sumal2;
  MPI_Finalize();
printf("Suma %f\n",suma );
}
