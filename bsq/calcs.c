/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:46:05 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/25 16:15:22 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	c_max_square(char **map, t_dims d, t_obs pos, int lap)
{
	int	i;
	int	j;
	int	s;

	s = 0;
	while (lap < (d.lines - pos.x) && lap < (d.cols - pos.y))
	{
		i = -1;
		while (++i < (s + 1))
		{
			j = -1;
			while (++j < (s + 1))
			{
				if (map[i + pos.x][j + pos.y] == d.o)
				{
					if (lap == 0 && (i + j) != 0)
						s++;
					return (s);
				}
			}
		}
		lap++;
		s++;
	}
	return (s);
}

t_corner	check_biggest_square(t_corner **map_corner, t_dims d)
{
	int			i;
	int			j;
	int			biggest;
	t_corner	coord;

	i = 0;
	biggest = 0;
	while (i < d.lines)
	{
		j = 0;
		while (j < d.cols)
		{
			if (map_corner[i][j].size > biggest)
			{
				biggest = map_corner[i][j].size;
				coord.size = biggest;
				coord.x = i;
				coord.y = j;
			}
			j++;
		}
		i++;
	}
	return (coord);
}
