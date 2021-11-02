/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:34:23 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/25 19:13:37 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	free_corners(t_corner **d, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(d[i]);
		i++;
	}
	free (d);
}

void	free_map(char **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free (map);
}
