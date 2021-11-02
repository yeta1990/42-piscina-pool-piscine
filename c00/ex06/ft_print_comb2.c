/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 13:18:52 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/08 14:01:55 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wrb(char a, char b, char c, char d);

void	ft_print_comb2(void)
{
	char	i[4];

	i[0] = 48;
	while (i[0] < 58)
	{
		i[1] = 48;
		while (i[1] < 58)
		{
			i[2] = 48;
			while (i[2] < 58)
			{
				i[3] = 48;
				while (i[3] < 58)
				{
					wrb(i[0], i[1], i[2], i[3]);
					i[3]++;
				}
				i[2]++;
			}
			i[1]++;
		}
		i[0]++;
	}
}

void	wrb(char a, char b, char c, char d)
{
	if ((a * 10 + b) < (c * 10 + d))
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
		if (((a * 10) + b + (c * 10) + d) < 1253)
			write(1, ", ", 2);
	}
}
