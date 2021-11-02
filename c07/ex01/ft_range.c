/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:10:29 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/24 19:09:26 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*r;
	int			size;
	long int	i;

	i = 0;
	size = max - min;
	if (size <= 0)
	{
		r = 0;
		return (r);
	}
	r = malloc(sizeof(int) * size);
	while (i < size)
	{
		r[i] = min + i;
		i++;
	}
	return (r);
}
