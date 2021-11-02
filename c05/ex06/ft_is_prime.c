/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:59:21 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/18 10:18:23 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	sqroot(int nb, int mult);

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	else if (nb == 2)
		return (1);
	else if (nb == 3)
		return (1);
	while (i <= sqroot(nb, 1))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	sqroot(int nb, int mult)
{
	if (mult > 46340)
		return (0);
	if (mult * mult == nb)
		return (mult);
	else if ((mult * mult) > nb)
		return (mult + 1);
	else
		return (sqroot(nb, mult + 1));
}
