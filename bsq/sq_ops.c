/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:48:19 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/25 16:16:35 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	all_squares(char **map, t_corner **map_corner, t_dims d)
{
	int		i;
	int		j;
	t_obs	o;
	int		lap;

	lap = 0;
	i = 0;
	j = 0;
	while (i < d.lines)
	{
		o.x = i;
		j = 0;
		while (j < d.cols)
		{
			o.y = j;
			map_corner[i][j].size = c_max_square(map, d, o, lap);
			j++;
		}
		i++;
	}
}

void	fill_square(char **map, t_corner biggest, t_dims d)
{
	int	i;
	int	j;

	i = 0;
	while (i < biggest.size)
	{
		j = 0;
		while (j < biggest.size)
		{
			map[i + biggest.x][j + biggest.y] = d.full;
			j++;
		}
		i++;
	}
	print_map(map, d);
}
