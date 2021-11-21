#include<stdio.h>
#include"mpi.h"
#include<stdlib.h>
#include<time.h>
#define N 10000000

int main(int argc,char *argv[])
{
	int rank,size;
	int mynum;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(time(NULL)+rank);
	mynum = rand();
	printf("hello world I'm %d of %d my number is %d\n",rank,size,mynum);
	MPI_Finalize();
	return 0;
}
