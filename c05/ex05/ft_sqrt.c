/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:28:09 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/17 19:47:09 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sq(int nb, int mult);

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	return (sq(nb, 1));
}

int	sq(int nb, int mult)
{
	if (mult > 46340)
		return (0);
	if (mult * mult == nb)
		return (mult);
	else if (mult * mult > nb)
		return (0);
	else
		return (sq(nb, mult + 1));
}
