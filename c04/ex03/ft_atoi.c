/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:30:53 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/19 20:54:11 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	j;
	int	sign;

	j = 0;
	number = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	return (number * sign);
}
