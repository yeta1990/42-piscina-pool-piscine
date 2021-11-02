/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:57:14 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 13:51:00 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		length;

	length = 0;
	while (str[length])
	{
		if (str[length] > 64 && str[length] < 91)
			str[length] = str[length] + 32;
		length++;
	}
	return (str);
}
