/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:14:29 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/10 19:34:01 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	result;
	int	counter;
	int	size;

	result = 1;
	counter = 0;
	size = 0;
	while (str[size])
		size++;
	while (counter < size)
	{
		if (str[counter] < 65 || str[counter] > 90)
			result = 0;
		counter++;
	}
	return (result);
}
