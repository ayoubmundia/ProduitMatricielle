#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int main()
{
	clock_t t1,t2;
	t1 = 0;
	
	int L1 = 550 , X = 550 , C2 = 550;
	
	double M1[L1][X] , M2[X][C2] , Result[L1][C2] ;
	
	for (int i=0;i<L1;i++)
	{
		for (int j=0;j<X;j++)
		{
			M1[i][j] = 100000;
		}
	}

	for (int i=0;i<X;i++)
	{
		for (int j=0;j<C2;j++)
		{
			M2[i][j] = 150000;
		}
	}

	for (int i=0;i<L1;i++)
	{
		for (int j=0;j<C2;j++)
			{
				Result[i][j]=0;
			}
	}

	#pragma omp parallel for schedule(static,2)
	for (int i=0;i<L1;i++)
	{
		for (int j=0;j<C2;j++)
		{
			for (int k=0;k<X;k++)
			{
				Result[i][j]=M1[i][k]*M2[k][j]+Result[i][j];
			}
		}
	}

	t2 = clock();

	float temps = float(t2-t1)/CLOCKS_PER_SEC;
		
	printf("Execution Time : => %f \n",temps);
	return 0;
}