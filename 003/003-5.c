#include<stdio.h>
#include"mpi.h"
#define N 10000000
#define M 1000
int main(int argc,char *argv[])
{
	int rank,size;
	int n;
	int m;
	int A[M];
	double start,end;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("hello world I'm %d of %d\n",rank,size);
	start = MPI_Wtime();
	for( n = 0 ; n < N / size ; n++ )
		for( m = 0 ; m < M ; m++ )
			A[m]=m;
	end = MPI_Wtime();
	if(rank==0)
		printf("A[%d] = %d elapsed time = %lf\n",M-1,A[M-1],end-start);
	MPI_Finalize();
	return 0;
}
