/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:11:42 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/24 19:08:43 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*p;
	int		size;

	size = 0;
	while (src[size])
		size++;
	p = malloc((size + 1) * sizeof(char));
	size = 0;
	while (src[size])
	{
		p[size] = src[size];
		size++;
	}
	p[size] = '\0';
	return (p);
}
