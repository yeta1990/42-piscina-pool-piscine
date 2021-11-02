#include<stdio.h>

int	ft_valid_lft_up(int a[4], int v)
{
	int	c;
	int	i;
	int	j;

	c = 1;
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (a[j] < a[i + 1])  
		{
	   		c++;
			j++;
		}
		i++;
	}	
	if (c == v)
		return (1);

	else 
		return (0);
}

int	ft_valid_rgt_dwn(int a[4], int v)
{
	int c;
	int	i;
	int	j;

	c = 1;
	i = 3;
	j = 3;
	while (i >= 0)
	{
		if (a[j] < a[i -1])
		{
			c++;
			j--;
		}
		i--;
	}
	if (c == v)
	{
		return (1);
	}
	else
		return (0);
}

int main(void)
{
	int	a[] = {1, 2, 3, 4};
	int b[] = {1, 2, 4, 3};
	int c[] = {4, 1, 2, 3};

	printf("%d\n", ft_valid_lft_up(a, 4));
	printf("%d\n", ft_valid_lft_up(b, 4));
	printf("%d\n", ft_valid_lft_up(c, 1));
	printf("%d\n", ft_valid_rgt_dwn(a, 1));
	printf("%d\n", ft_valid_rgt_dwn(b, 2));
	printf("%d\n", ft_valid_rgt_dwn(c, 2));	


	return (0);
}
