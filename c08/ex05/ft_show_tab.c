/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:40:07 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/19 22:21:15 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	print_copy(struct s_stock_str *par, int i);
void	ft_putnbr(int n);
void	recursive_printer(int n);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (par[i].str)
	{
		while (par[i].str[j])
		{
			write(1, &par[i].str[j], 1);
			j++;
		}
		j = 0;
		write (1, "\n", 1);
		ft_putnbr(par[i].size);
		write (1, "\n", 1);
		print_copy(par, i);
		i++;
	}
}

void	print_copy(struct s_stock_str *par, int i)
{
	int	j;

	j = 0;
	while (par[i].copy[j])
	{
		write(1, &par[i].copy[j], 1);
		j++;
	}
	write (1, "\n", 1);
}

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
