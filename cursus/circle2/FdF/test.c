#include <stdio.h>
#include <stdlib.h>

int	**mat_multiple(int **a, int **b, int a_rows, int b_cols, int b_rows)
{
	int	i;
	int j;
	int	k;
	int **c;

	c = (int **)malloc(sizeof(int *) * a_rows);
	i = 0;
	while (i < a_rows)
	{
		c[i] = (int *)malloc(sizeof(int) * b_cols);
		j = 0;
		while (j < b_cols)
		{
			k = 0;
			c[i][j] = 0;
			while (k < b_rows)
			{
				c[i][j] += a[i][k]*b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (c);
}

int main()
{
	int k =1;
	int h = 3;
	int **a= (int **)malloc(sizeof(int *)*2);
	a[0] = (int*)malloc(sizeof(int)*3);
	a[1] = (int*)malloc(sizeof(int)*3);
	int **b= (int **)malloc(sizeof(int *)*3);
	b[0] = (int*)malloc(sizeof(int)*2);
	b[1] = (int*)malloc(sizeof(int)*2);
	b[2] = (int*)malloc(sizeof(int)*2);

	while (k<7)
	{
		for(int i = 0; i < 2; i++)
			for(int j = 0; j <3; j++)
				a[i][j] = k++;
	}
	while (h<9)
	{
		for(int i = 0; i < 3; i++)
			for(int j = 0; j <2; j++)
				b[i][j] = h++;
	}

	int **c = mat_multiple(a,b,2,2,3);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("c[%d][%d] = %d\n", i, j, c[i][j]);
		}
	}
}