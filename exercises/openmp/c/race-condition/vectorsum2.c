#include <stdio.h>
#include <omp.h>
#define NX 102400

int main(void)
{
    long vecA[NX];
    long sum, psum, sumex;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i+1;
    }

    sum = 0.0;

#pragma omp parallel private(psum)
{
	psum=0;
   #pragma omp for
    for (i = 0; i < NX; i++) {
        psum = psum +  vecA[i];
    }

	#pragma omp critical(addup)
		sum =sum + psum;
}
    printf("Sum: %ld\n",sum);

    return 0;
}
