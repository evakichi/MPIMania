#include<stdio.h>
#include"mpi.h"
#define N 10000000

int main(int argc,char *argv[])
{
	MPI_Init(&argc,&argv);
	printf("hello world\n");
	MPI_Finalize();
	return 0;
}
