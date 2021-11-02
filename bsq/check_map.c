/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:15:40 by dpenas-u          #+#    #+#             */
/*   Updated: 2021/08/26 10:42:26 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	check_map(char *file, char *first_line)
{
	t_dims	d;
	int		n_char;
	int		f;
	char	buff;

	f = 0;
	buff = 0;
	first_line_copy(file, first_line);
	parse_first_line(first_line, &d, file);
	count_lines_and_cols(file, &d, f, buff);
	n_char = compute_n_char_in_map(file);
	if (check_char_map_in_header(d, file) == 0)
		return (0);
	if (check_terminal_nl(file, n_char) == 0)
		return (0);
	if (check_map2(file, d, first_line) == 0)
		return (0);
	return (1);
}

int	check_map2(char *file, t_dims d, char *first_line)
{
	int		f;
	char	buff;
	int		*len_lines;

	buff = 0;
	f = 0;
	len_lines = save_len_lines(file, d, f, buff);
	if (check_n_char_in_header(first_line, file) == 0)
		return (0);
	if (check_nbr_before_o_e_n(first_line) == 0)
		return (0);
	if (check_repeat_char_in_header(d) == 0)
		return (0);
	if (check_intermediate_nl(file) == 0)
		return (0);
	if (check_one_square(file) == 0)
		return (0);
	if (check_same_len_lines(len_lines, d) == 0)
		return (0);
	if (len_header_map(file) == -1)
		return (0);
	if (n_header_equal_lines_file(first_line, d, file) == 0)
		return (0);
	free(len_lines);
	return (1);
}
