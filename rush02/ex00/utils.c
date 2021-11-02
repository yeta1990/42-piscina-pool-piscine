/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:19:17 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/22 23:02:21 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	rec_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power > 0)
		return (nb * rec_power(nb, power - 1));
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	n_l(int l, unsigned int	n)
{
	if (n > 0)
		return (n_l(l + 1, n / 10));
	if (n == 0 && l == 0)
		return (1);
	else
		return (l);
}

unsigned int	f_atoi(char *str)
{
	unsigned int	num;
	int				i;

	num = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
