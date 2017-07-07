#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    printf("Hello world!\n");
#pragma omp parallel
    {
#pragma omp single
{
int nthrds = omp_get_num_threads();
printf("Number of active threads: %d \n", nthrds);
}
int thrd_id = omp_get_thread_num();
        printf("Thread id %d\n", thrd_id);
    }

    return 0;
}
