#include <stdio.h>

int check_row(int *r);
int main(void)
{
	int *r = [1,2,3,4];
	check_row(r);

}

int check_row(int *r)
{
	int	i;

	while (i < 4)
	{
		printf("%i", r[i]); 	
	}
}
