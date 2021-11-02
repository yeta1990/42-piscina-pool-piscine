/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:42:41 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/25 20:27:14 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	count_lines_and_cols(char *file, t_dims *d, int f, char buff)
{
	int		bl;

	bl = 0;
	d->lines = -1;
	d->cols = 0;
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		if (buff == 10)
			d->lines++;
	}
	close(f);
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		if (buff == 10 && bl == 0)
			bl = 1;
		else if (buff != 10 && bl == 1)
			d->cols++;
		else if (buff == 10 && bl == 1)
			break ;
	}
	close(f);
}

char	**memory_for_map(t_dims d, char *file, int f, char buff)
{
	int		bl;
	int		i;
	int		j;
	char	**map;

	bl = 0;
	i = -1;
	j = 0;
	map = (char **)malloc(sizeof(char *) * d.lines);
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		j++;
		if (buff == 10)
		{
			if (bl == 1)
				map[++i] = (char *)malloc(sizeof(char) * (j + 1));
			j = 0;
			bl = 1;
		}
	}
	close(f);
	return (map);
}

void	copy_map(char **map, char *file, int f, char buff)
{
	int		i;
	int		j;
	int		bl;

	bl = 0;
	i = 0;
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		if (buff == 10)
		{
			if (bl == 1)
			{
				map[i][j] = '\0';
				i++;
			}
			bl = 1;
			j = 0;
		}
		else if (buff != 0 && bl == 1)
			map[i][j++] = buff;
	}
	close(f);
}
