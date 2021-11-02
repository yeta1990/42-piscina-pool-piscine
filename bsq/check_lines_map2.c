/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:10:19 by dpenas-u          #+#    #+#             */
/*   Updated: 2021/08/26 10:34:14 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	len_header_map(char *file)
{
	int		f;
	char	buff;
	int		len_header;

	buff = 0;
	len_header = 0;
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		if (buff != 10)
			len_header++;
		if (buff == 10)
		{
			close(f);
			return (len_header);
		}
	}
	close(f);
	return (-1);
}

int	compute_n_char_in_map(char *file)
{
	int		f;
	char	buff;
	int		n_char;

	buff = 0;
	n_char = 0;
	f = open(file, O_RDONLY);
	while (read(f, &buff, 1) == 1)
	{
		n_char++;
	}
	close(f);
	return (n_char);
}
