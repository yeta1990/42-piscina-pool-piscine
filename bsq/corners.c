/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:42:54 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/25 18:35:26 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

t_corner	create_corner(int x, int y, int size)
{
	t_corner	t;

	t.x = x;
	t.y = y;
	t.size = size;
	return (t);
}

t_corner	**fill_corners(t_dims d)
{
	int			i;
	int			j;
	t_corner	**t;

	i = 0;
	j = 0;
	t = (t_corner **)malloc(sizeof(t_corner *) * d.lines);
	while (i < d.lines)
	{
		j = 0;
		t[i] = (t_corner *)malloc(sizeof(t_corner) * d.cols);
		while (j < d.cols)
		{
			t[i][j] = create_corner(i, j, 0);
			j++;
		}
		i++;
	}
	return (t);
}
