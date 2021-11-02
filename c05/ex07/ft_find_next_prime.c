/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:19:29 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/20 12:25:41 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb);
int	sq_root(int nb, int mult);

int	ft_find_next_prime(int nb)
{
	int	prime;
	int	i;

	prime = 0;
	if (nb == 2147483647)
		return (nb);
	i = nb + 1;
	if (nb < 0)
		return (2);
	while (is_prime(i) == 0 && i <= 2147483647)
		i++;
	return (i);
}

int	is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	else if (nb == 2)
		return (1);
	else if (nb == 3)
		return (1);
	while (i <= sq_root(nb, 1))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	sq_root(int nb, int mult)
{
	if (mult > 46340)
		return (0);
	if (mult * mult == nb)
		return (mult);
	else if (mult * mult > nb)
		return (mult + 1);
	else
		return (sq_root(nb, mult + 1));
}
