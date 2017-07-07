#include <stdio.h>
#include <mpi.h>
#include <omp.h>


int main(int argc, char **argv)
{
int rank, rc, provided, required;
required = MPI_THREAD_MULTIPLE;
MPI_Init_thread(&argc, &argv, required, &provided);
printf("Thread safety: required %d, provided %d\n", required, provided);
if (provided < required){
printf("NOT SAFE!\n");
return -1;
}
rc = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#pragma omp parallel
{
int tid;
tid= omp_get_thread_num();
    printf("Hello from rank %d, thread, %d\n", rank, tid);

} 
MPI_Finalize();
    return 0;
}
