/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:14:25 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/10 15:49:54 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	size;
	unsigned int	counter;

	size = 0;
	counter = 0;
	while (src[size])
		size++;
	while (counter < n)
	{
		if (counter < size)
			dest[counter] = src[counter];
		else
			dest[counter] = '\0';
		counter++;
	}
	return (dest);
}
