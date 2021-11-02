/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:57:14 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 13:50:42 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		length;

	length = 0;
	while (str[length])
	{
		if (str[length] > 96 && str[length] < 123)
			str[length] = str[length] - 32;
		length++;
	}
	return (str);
}
