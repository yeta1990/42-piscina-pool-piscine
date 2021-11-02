/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:00:37 by dpenas-u          #+#    #+#             */
/*   Updated: 2021/08/26 10:09:51 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq_header.h"

int	check_terminal_nl(char *file, int n_char)
{
	int		f;
	char	buff;
	int		counter;

	buff = 0;
	counter = 0;
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		counter++;
		if (counter == n_char - 1 && buff == 10)
		{
			close(f);
			return (0);
		}
		if (counter == n_char && buff != 10)
		{
			close(f);
			return (0);
		}
	}
	close(f);
	return (1);
}

int	check_intermediate_nl(char *file)
{
	int		f;
	char	buff;
	int		bl;

	buff = 0;
	bl = 0;
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		if (buff == 10 && bl == 1)
		{
			close(f);
			return (0);
		}
		else
			bl = 0;
		if (buff == 10)
			bl = 1;
	}
	close(f);
	return (1);
}

int	check_one_square(char *file)
{
	int		f;
	char	buff;
	int		bl;
	int		n_squares;

	bl = 0;
	buff = 0;
	n_squares = 0;
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		if (buff == 10 && bl == 0)
			bl = 1;
		else if (buff != 10 && bl == 1)
			n_squares++;
	}
	close(f);
	if (n_squares == 0)
		return (0);
	return (1);
}

int	*save_len_lines(char *file, t_dims d, int f, char buff)
{
	int		bl;
	int		*len_lines;
	int		i;
	int		n_cols;

	bl = 0;
	n_cols = 0;
	i = 0;
	len_lines = malloc(sizeof(int *) * d.lines);
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		if (buff == 10 && bl == 0)
			bl = 1;
		else if (buff != 10 && bl == 1)
			n_cols++;
		else if (buff == 10 && bl == 1)
		{
			len_lines[i] = n_cols;
			n_cols = 0;
			i++;
		}
	}
	close(f);
	return (len_lines);
}

int	check_same_len_lines(int *len_lines, t_dims d)
{
	int		i;

	i = 1;
	while (i < d.lines)
	{
		if (len_lines[i] != len_lines[0])
			return (0);
		i++;
	}
	return (1);
}
