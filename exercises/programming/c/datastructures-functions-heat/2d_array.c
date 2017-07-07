#include <stdio.h>
#include <stdlib.h>

#define NX 258
#define NY 258

int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
	double array[NX][NX];

    // Initialize first the zeros
	for (i=0; i<258; i++){
		for (j=0; j<258; j++){
			array[i][j] = 0;

		}
	}

    // Initial conditions for left and right
	for (i=0; i<258; i++){
		array[i][0] = 20.0;
		array[i][257] = 70.0;
	}

    // and top and bottom boundaries


	for (i=0; i<258; i++){
		array[0][i] = 85.0;
		array[257][i] = 5.0;
	}

	printf("%f,%f,%f,%f,%f\n",array[100][100], array[100][0],array[100][257],array[257][100],array[0][100]);


printf("%f \n", array[0][0]);
    return 0;
}
