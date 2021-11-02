/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 09:48:28 by dpenas-u          #+#    #+#             */
/*   Updated: 2021/08/26 10:32:06 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	check_n_char_in_header(char *first_line, char *file)
{
	int	i;
//	int	counter;
//	int	bol_fr_number;

	i = 0;
//	counter = 0;
//	bol_fr_number = 0;
	while (i < (len_header_map(file) - 3))
	{
		if (!(first_line[i] > 47 && first_line[i] < 58))
			return (0);
		i++;
	}
	return (1);
}

int	check_repeat_char_in_header(t_dims d)
{
	if (d.o == d.empty || d.o == d.full)
		return (0);
	if (d.empty == d.full)
		return (0);
	return (1);
}

int	check_char_map_in_header(t_dims d, char *file)
{
	int		f;
	char	b;
	int		bl;

	b = 0;
	bl = 0;
	f = open(file, O_RDONLY);
	while (read(f, &b, 1) == 1)
	{
		if (b == 10 && bl == 0)
			bl = 1;
		else if (b != d.o && b != d.empty && b != d.full && bl == 1 && b != 10)
		{
			close(f);
			return (0);
		}
	}
	close(f);
	return (1);
}

int	check_nbr_before_o_e_n(char *first_line)
{
	if (first_line[0] < 48 || first_line[0] > 57)
		return (0);
	return (1);
}

int	n_header_equal_lines_file(char *first_line, t_dims d, char *file)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (i < (len_header_map(file) - 3))
	{
		if (!(first_line[i] > 47 && first_line[i] < 58))
			break ;
		num = num * 10 + first_line[i] - 48;
		i++;
	}
	if (d.lines != num)
		return (0);
	return (1);
}
