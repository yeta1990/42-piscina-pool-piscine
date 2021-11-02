/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:01:20 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 21:00:25 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;

	counter = 0;
	while (src[counter] && counter < size)
	{
		if (counter < size - 1)
			dest[counter] = src[counter];
		else
			dest[counter] = '\0';
		counter++;
	}
	return (counter);
}
