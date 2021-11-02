#include <unistd.h>

void	ft_putchar(char c);

void	rush (int width, int height)
{
	int	w;
	int	h;

	w = width;
	h = height;
	while (w > 0)
	{
		if (w == width)
			ft_putchar('/');
		else if (w > 1)
			write(1, "*", 1);
		else
			write(1, "\\", 1);
		w--;
	}
	w = width;
	write(1, "\n", 1);
	while (h > 2)
	{
		while (w > 0)
		{
			if (w == width)
				write(1, "*", 1);
			else if (w > 1)
				write(1, " ", 1);
			else
				write(1, "*", 1);
			w--;
		}
		w = width;
		write(1, "\n", 1);
		h--;
	}
	while (w > 0 && height > 1)
	{
		if (w == width)
			write(1, "\\", 1);
		else if (w > 1)
			write(1, "*", 1);
		else
			write(1, "/", 1);
		w--;
	}
	if (h > 1)
		write(1, "\n", 1);
}
