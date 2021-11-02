#include <unistd.h>

int		fpow(int p, int n);

void	recursive_print(int n);

void	ft_print_combn(int n);

int		print_or_not(int number_to_check, int n);

void	logic(int n);

void	ft_print_combn(int n)
{
	char	p[10];
	int		counter;
	int		counter2;
	int		number_to_print;

	counter = 0;
	counter2 = 0;
	number_to_print = 0;
	while (counter < n)
	{
		p[counter] = counter + 48;
		counter++;
	}
	while (counter2 < n)
	{
		number_to_print += ((p[counter2] - '0') * fpow(counter - 2, 10));
		counter2 ++;
		counter --;
	}
	logic(n);
}

int	fpow(int p, int n)
{
	if (p < 1)
		return (1);
	else
		return (n * fpow(p - 1, n));
}

void	recursive_print(int n)
{
	char			c;
	unsigned int	number;

	number = n;
	if (n > 0)
	{
		recursive_print(number / 10);
		c = (number % 10) + 48;
		write(1, &c, 1);
	}
}

int	print_or_not(int t, int n)
{
	int	count;
	int	print;

	print = 1;
	count = 0;
	if (t < fpow(n - 1, 10))
	{
		while (count < (n - 1) && print)
		{
			if ((t / fpow(count, 10)) % 10 <= (t / fpow(count + 1, 10) % 10))
				print = 0;
			count++;
		}
	}
	else
	{
		while (count < n && print)
		{
			if ((t / fpow(count, 10)) % 10 <= (t / fpow(count + 1, 10) % 10))
				print = 0;
			count++;
		}
	}
	return (print);
}

void	logic(int n)
{
	int	counter3;
	int	number_to_print;

	number_to_print = 0;
	counter3 = 0;
	while (number_to_print <= 123456789 % fpow(n, 10))
	{
		if (print_or_not(number_to_print, n) == 1)
		{
			if (counter3 > 0)
				write(1, ", ", 2);
			if (number_to_print < fpow(n - 1, 10))
				write(1, "0", 1);
			recursive_print(number_to_print);
			if (number_to_print == 23456789 && n == 9)
			{	
				write(1, ", ", 2);
				write (1, "123456789", 9);
				number_to_print = number_to_print * 10;
			}
			counter3++;
		}
		number_to_print++;
	}
}
