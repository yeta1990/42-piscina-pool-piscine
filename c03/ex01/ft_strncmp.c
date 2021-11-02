/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:45:42 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/12 10:47:54 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	if (n < 1)
		return (0);
	while (counter < n - 1)
	{
		if (s1[counter] != s2[counter])
			return (s1[counter] - s2[counter]);
		else if (s1[counter] == '\0')
			return (-s2[counter]);
		else if (s2[counter] == '\0')
			return (s1[counter]);
		counter++;
	}
	if (s1[counter] != s2[counter])
		return (s1[counter] - s2[counter]);
	return (0);
}
