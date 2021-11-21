#include<stdio.h>
#include"mpi.h"
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(int argc,char *argv[])
{
	int rank,size;
	int mynum=0;
	int myerr=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(time(NULL)+rank);
	if(rank == 0)
		mynum = rand();
	printf("hello world I'm %d of %d my number is %d\n",rank,size,mynum);
	sleep(3);
	myerr = MPI_Bcast(&mynum,1,MPI_INT,0,MPI_COMM_WORLD);
	printf("hello world I'm %d of %d my number is %d (err No. is %d)\n",rank,size,mynum,myerr);
	MPI_Finalize();
	return 0;
}
