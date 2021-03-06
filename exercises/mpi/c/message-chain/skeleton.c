#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
    int i, myid, ntasks, count;
    int size = 10000000;
    int *message;
    int *receiveBuffer;
    MPI_Status status[2];
   MPI_Request request[2];
 
    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    /* Allocate message */
    message = malloc(sizeof(int) * size);
    receiveBuffer = malloc(sizeof(int) * size);
    /* Initialize message */
    for (i = 0; i < size; i++)
        message[i] = myid;


    /* TODO start */
    /* Send and receive messages as defined in exercise */
int dest, source;
  if (myid ==0){
     source = MPI_PROC_NULL;
     dest = myid+1;
  }else if (myid == ntasks-1){
     source = myid-1;
     dest = MPI_PROC_NULL;
  }else{
     source=myid-1;
     dest=myid+1;
  }

    /* Start measuring the time spend in communication */
    MPI_Barrier(MPI_COMM_WORLD);
    t0 = MPI_Wtime();


  MPI_Irecv(receiveBuffer, size, MPI_INT, source, MPI_ANY_TAG,  MPI_COMM_WORLD, &request[0]);
 MPI_Isend(message, size, MPI_INT, dest, myid+1, MPI_COMM_WORLD, &request[1]);
 
  MPI_Waitall(2, request, status);
//	MPI_Sendrecv(message, size, MPI_INT, dest, myid+1, receiveBuffer, size, MPI_INT, source, myid, MPI_COMM_WORLD, &status);
        printf("Sender: %d. Sent elements: %d. Tag: %d. Receiver: %d\n",
               myid, size, myid + 1, myid + 1);
MPI_Get_count(&status[0], MPI_INT, &count);
        printf("Receiver: %d. first element %d. Data count  %d\n",
               myid, receiveBuffer[0],count);
  

    /* TODO end */

    /* Finalize measuring the time and print it out */
    t1 = MPI_Wtime();
    MPI_Barrier(MPI_COMM_WORLD);
    fflush(stdout);

    printf("Time elapsed in rank %2d: %6.3f\n", myid, t1 - t0);

    free(message);
    free(receiveBuffer);
    MPI_Finalize();
    return 0;
}
