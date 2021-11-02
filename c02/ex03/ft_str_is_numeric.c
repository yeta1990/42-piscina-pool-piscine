/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:31:47 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 13:50:27 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	size;
	int	counter;
	int	result;

	size = 0;
	counter = 0;
	result = 1;
	while (str[size])
		size++;
	while (counter < size)
	{
		if (str[counter] < 48 || str[counter] > 57)
			result = 0;
		counter++;
	}
	return (result);
}
