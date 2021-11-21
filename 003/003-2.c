#include<stdio.h>
#include"mpi.h"
#define N 10000000

int main(int argc,char *argv[])
{
	int rank,size;
	int n;
	double start,end;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("hello world I'm %d of %d\n",rank,size);
	start = MPI_Wtime();
	for( n = 0 ; n < N ; n++ );
	end = MPI_Wtime();
	printf("elapsed time = %lf\n",end-start);
	MPI_Finalize();
	return 0;
}
