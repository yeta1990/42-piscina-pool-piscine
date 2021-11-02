#include <unistd.h>

void	ft_putnbr(int n);
void	recursive_printer(int n);

void	ft_putnbr(int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		recursive_printer(n);
	}
}

void	recursive_printer(int n)
{
	char			c;
	unsigned int	number;

	number = n;
	if (n < 0)
	{
		write(1, "-", 1);
		recursive_printer(number * -1 / 10);
		c = (number * -1 % 10) + 48;
		write(1, &c, 1);
	}
	if (n > 0)
	{
		recursive_printer(number / 10);
		c = (number % 10) + 48;
		write(1, &c, 1);
	}
}
