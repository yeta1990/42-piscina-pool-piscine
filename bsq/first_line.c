/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:08:15 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/26 10:43:08 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	first_line_controller(char *file, t_dims *d)
{
	char	*first_line;

	first_line = first_line_mem(file);
	first_line_copy(file, first_line);
	parse_first_line(first_line, d, file);
	free(first_line);
}

char	*first_line_mem(char *file)
{
	int		f;
	char	buff;
	int		first_line_len;

	f = 0;
	buff = 0;
	first_line_len = 0;
	f = open(file, O_RDONLY);
	if (f == -1)
		return (0);
	while (read(f, &buff, 1) == 1)
	{
		first_line_len++;
		if (buff == 10)
			break ;
	}
	close(f);
	return ((char *)malloc(sizeof(char) * (first_line_len + 1)));
}

void	first_line_copy(char *file, char *first_line)
{
	int		i;
	int		f;
	char	buff;

	i = 0;
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		first_line[i] = buff;
		i++;
		if (buff == 10)
		{
			first_line[i] = '\0';
			break ;
		}
	}
	close(f);
}

void	parse_first_line(char *first_line, t_dims *d, char *file)
{
	int	i;

	i = len_header_map(file);
	d->empty = first_line[i - 3];
	d->full = first_line[i - 1];
	d->o = first_line[i - 2];
}
