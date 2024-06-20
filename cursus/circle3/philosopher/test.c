#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_te
{
	int *num;
}t_te;

void change_num(t_te test)
{
	*test.num = 7;
}

int main(void)
{
	t_te test;

	int *a = (int *)malloc(4);
	*a = 3;
	test.num = a;
	change_num(test);
	printf("%d\n", *test.num);
	struct timeval tv;
	gettimeofday(&tv, 0);
	printf("sec %ld usec %ld\n", tv.tv_sec, tv.tv_usec);
}
