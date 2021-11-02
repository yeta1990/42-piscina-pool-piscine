/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:34:37 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 11:55:41 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	result;
	int	length;

	length = 0;
	result = 1;
	while (str[length] != '\0')
	{
		if (str[length] < 32 || str[length] > 126)
			result = 0;
		length++;
	}
	return (result);
}
