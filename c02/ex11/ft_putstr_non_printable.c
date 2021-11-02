/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:55:03 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 21:27:41 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putstr_non_printable(char *str)
{
	int		size;
	char	*hex;

	hex = "0123456789abcdef";
	size = 0;
	while (str[size])
	{
		if (str[size] < 32 || str[size] > 126)
		{
			write(1, "\\", 1);
			write(1, &hex[(str[size] / 16) % 16], 1);
			write(1, &hex[str[size] % 16], 1);
		}
		else
			write(1, &str[size], 1);
		size++;
	}
}
