void	ft_rev_int_tab(int *tab, int size)
{
	int	count2;
	int	swap;

	count2 = 0;
	swap = 0;
	while (count2 < size / 2)
	{
		swap = tab[count2];
		tab[count2] = tab[size - count2 - 1];
		tab[size - count2 - 1] = swap;
		count2++;
	}
}
