
#include <stdio.h>
#include <unistd.h>
#include "error.c"
#include <stdlib.h>
void runner(int pos, int *r, int back, int val1, int val2);
int check_rows(int *r, int *r1, int row);

int main(void)
{

	int r[] = {1, 1, 1, 1};
	int r2[] = {1, 1, 1, 1};
	int r3[] = {1, 1, 1, 1};
	int r4[] = {1, 1, 1, 1};


/*	int *c;
	int *c1;
	int *c2;
	int *c3;
	*/
	int i;
	int j;
//	int z;
	i = 0;
	j = 0;
	printf("row0\n");
	runner(0, r, 0, 2, 2);
	runner(0, r2, 0, 2, 3);
	runner(0, r3, 0, 3, 1);
	runner(0, r4, 0, 1, 2);	


	while (check_rows(r, r2, 1) == 0)
	{	
		printf("row1\n");
		runner(0, r2, 1, 2, 3);
	}
	while (check_rows(r2, r3, 2) == 0)
	{	
		printf("row2");
		runner(0, r3, 1, 2, 3);

	}

}
	
int check_rows(int *r, int *r2, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (r[i] == r2[i])
			return (0);
		i++;
	}
	printf("row%d: %d%d%d%d\n", row - 1, r[0], r[1], r[2], r[3]);

	printf("row%d: %d%d%d%d\n", row, r2[0], r2[1], r2[2], r2[3]);

	return (1);
}
void runner(int pos, int *r, int back, int val1, int val2)
{
	if (pos == 0)
	{
		if (back == 1)
		{
			if (r[pos] < 4)
				r[pos] = r[pos] + 1;
			else
				return runner(pos + 1, r, 0, val1, val2);
		}
		else if (r[pos] == 4 && r[pos+1] == 1 && r[pos+2] == 1)
		{
			r[pos] = 1;
			return runner(pos + 1, r, 0, val1, val2);
		}
		else
		{
			return runner(pos + 1, r, 0, val1, val2);
		}	
	}
	else if (pos > 0 && pos < 3)
	{
		if (back == 1)
		{
			if (r[pos] < 4)
			{	
				r[pos] = r[pos] + 1;
				return runner(pos + 1, r, 0, val1, val2);
			}
			else
			{	
				r[pos] = 1;	
				return runner(pos - 1, r, 1, val1, val2);
			}
		}
		else
			return (runner(pos + 1, r, 0, val1, val2));
	}
	else
	{
		if (lft_up(r, val1) && rgt_dwn(r, val2))
		{
			printf("%d: %d%d%d%d :%d\n", val1, r[0], r[1], r[2], r[3], val2);
			return;
		}	
		else if (r[pos] < 4)
		{
			r[pos] = r[pos] + 1;
			return runner (pos, r, 0, val1, val2);
		}
		else
		{
			r[pos] = 1;
			return runner(pos - 1, r, 1, val1, val2);
		}
	}
}

