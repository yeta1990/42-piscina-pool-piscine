/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:59:27 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/10 19:12:55 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	counter;
	int	result;
	int	size;

	counter = 0;
	result = 1;
	size = 0;
	while (str[size])
		size++;
	while (counter < size)
	{
		if (str[counter] < 97 || str[counter] > 122)
			result = 0;
		counter++;
	}
	return (result);
}
