#include <math.h>
#include <stdio.h>
#include <omp.h>
#define N 6

int main(){

   int i,fact=1;
   #pragma omp parallel for reduction(*:fact)
   for(i=1;i<=N;i++)
      fact=fact*i;
   printf("Factorial de %d es %d\n",N,fact);
   return 0;
}

