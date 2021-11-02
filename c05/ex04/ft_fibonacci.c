/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:07:17 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/16 21:25:05 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	number;

	number = 0;
	if (index == 0)
		number = 0;
	else if (index == 1)
		number = 1;
	else if (index >= 2)
		number = number + ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	else if (index < 0)
		number = -1;
	return (number);
}
