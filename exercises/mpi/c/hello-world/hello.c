#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
int rank, rc;

MPI_Init(&argc, &argv);
rc = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello world! %d\n", rank);

 
MPI_Finalize();
    return 0;
}
