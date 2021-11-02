void	ft_sort_int_tab(int *tab, int size)
{
	int	counter1;
	int	counter2;
	int	swap;

	counter1 = 0;
	while (counter1 < size)
	{
		counter2 = 0;
		while (counter2 < size)
		{
			if (tab[counter1] < tab[counter2])
			{
				swap = tab[counter2];
				tab[counter2] = tab[counter1];
				tab[counter1] = swap;
			}
			counter2++;
		}
		counter1++;
	}
}
