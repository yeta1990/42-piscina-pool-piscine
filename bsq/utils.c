/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:41:07 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/26 09:57:15 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	print_map(char **map, t_dims d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d.lines)
	{
		j = 0;
		while (j < d.cols)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
