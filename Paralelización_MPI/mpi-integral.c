#include <math.h>
#include <stdio.h>
#include <omp.h>
#include "mpi.h"

#define INICIO 1.0f 
#define FIN 3.0f 
#define PARTICIONES 999999999 
#define DELTA ((FIN-INICIO)/PARTICIONES) 

int main(int argc, char *argv[]) {
  int rank, nprocs, leng;
  int inicio, fin;
  int bloques, residuo, adicional;
  double suma=0;
  double sumal=0;
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
 MPI_Reduce(&sumal, &suma,1,MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

if(rank==0)
    printf("Suma %f\n",suma );
  MPI_Finalize();
}
