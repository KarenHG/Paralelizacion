#include <math.h>
#include <stdio.h>
#include <omp.h>

int main(){
   int total,id;
   #pragma omp parallel private(total,id) 
   {
      id=omp_get_thread_num();
      if(id%2==0)
          printf("Hilo %d: Mi id es par\n",id);
      else
          printf("Hilo %d: Mi id es impar\n",id);
   }

   return 0;
}

