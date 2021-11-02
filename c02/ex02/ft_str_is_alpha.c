/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:57:32 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 12:36:01 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	size;
	int	c;
	int	alpha;

	size = 0;
	c = 0;
	alpha = 1;
	while (str[size])
		size++;
	while (c < size)
	{
		if (str[c] < 65 || (str[c] > 90 && str[c] < 97) || str[c] > 122)
			alpha = 0;
		c++;
	}
	return (alpha);
}
