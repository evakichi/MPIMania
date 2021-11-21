#include<stdio.h>
#include"mpi.h"
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#define N 10000000

int main(int argc,char *argv[])
{
	int rank,size;
	int mynum;
	int myerr=0;
	int yournum=0;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(time(NULL)+rank);
	mynum = rand();
	printf("hello world I'm %d of %d my number is %d your number is %d\n",rank,size,mynum,yournum);
	sleep(10);
	if(rank == 0)
		myerr = MPI_Send(&mynum,1,MPI_INT,1,1,MPI_COMM_WORLD);
	if(rank == 1)
		myerr = MPI_Recv(&yournum,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
	printf("hello world I'm %d of %d my number is %d your number is %d(err No. is %d)\n",rank,size,mynum,yournum,myerr);
	MPI_Finalize();
	return 0;
}
