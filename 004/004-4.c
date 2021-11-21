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
	myerr = MPI_Send(&mynum  ,1,MPI_INT,(rank+1)%size,     (rank+1)%size,MPI_COMM_WORLD);
	myerr = MPI_Recv(&yournum,1,MPI_INT,(rank+size-1)%size,rank         ,MPI_COMM_WORLD,&status);
	printf("hello world I'm %d of %d my number is %d your number is %d(err No. is %d)\n",rank,size,mynum,yournum,myerr);
	MPI_Finalize();
	return 0;
}
