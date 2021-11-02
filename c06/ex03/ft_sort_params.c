/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:14:34 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/17 12:13:04 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int		ft_strcmp(char *s1, char *s2);
void	ft_sort_char_tab(char **tab, int size);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	ft_sort_char_tab(argv, argc);
	if (argc > 1)
	{
		while (i < argc)
		{
			while (argv[i][j])
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			j = 0;
			write(1, "\n", 1);
			i++;
		}
	}
}

void	ft_sort_char_tab(char **tab, int size)
{
	int		counter1;
	int		counter2;
	char	*swap;

	counter1 = 1;
	swap = "";
	while (counter1 < size)
	{
		counter2 = 1;
		while (counter2 < size)
		{
			if (ft_strcmp(tab[counter1], tab[counter2]) < 0)
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return (-s2[i]);
	else
		return (s1[i]);
}
