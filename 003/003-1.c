#include<stdio.h>
#include"mpi.h"
#define N 10000000

int main(int argc,char *argv[])
{
	int rank,size;
	int n;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("hello world I'm %d of %d\n",rank,size);
	for( n = 0 ; n < N ; n++ );
	MPI_Finalize();
	return 0;
}
