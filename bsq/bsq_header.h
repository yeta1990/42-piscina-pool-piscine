/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:48:58 by dpenas-u          #+#    #+#             */
/*   Updated: 2021/08/26 10:29:37 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct sq
{
	int	x;
	int	y;
	int	size;
}	t_corner;

typedef struct oo
{
	int	x;
	int	y;
}	t_obs;

typedef struct dim
{
	int		lines;
	int		cols;
	char	o;
	char	empty;
	char	full;
}	t_dims;

t_corner	**fill_corners(t_dims d);
int			c_max_square(char **map, t_dims d, t_obs pos, int lap);
t_corner	create_corner(int x, int y, int size);
void		all_squares(char **map, t_corner **map_corner, t_dims d);
t_corner	check_biggest_square(t_corner **map_corner, t_dims d);
void		fill_square(char **map, t_corner biggest, t_dims d);
void		print_map(char **map, t_dims d);
void		count_lines_and_cols(char *file, t_dims *d, int f, char buff);
char		**memory_for_map(t_dims d, char *file, int f, char buff);
void		first_line_controller(char *file, t_dims *d);
char		*first_line_mem(char *file);
void		first_line_copy(char *file, char *first_line);
void		parse_first_line(char *first_line, t_dims *d, char *file);
void		copy_map(char **map, char *file, int f, char buff);
void		find_max_square(char *file);
void		ft_putstr(char *str);
int			check_n_char_in_header(char *first_line, char *file);
int			check_map(char *file, char *first_line);
int			check_nbr_before_o_e_n(char *first_line);
int			check_repeat_char_in_header(t_dims d);
int			check_repeat_char_in_header(t_dims d);
int			check_char_map_in_header(t_dims d, char *file);
int			compute_n_char_in_map(char *file);
int			check_terminal_nl(char *file, int n_char);
int			check_intermediate_nl(char *file);
int			check_one_square(char *file);
int			*save_len_lines(char *file, t_dims d, int f, char buff);
int			check_same_len_lines(int *len_lines, t_dims d);
int			n_header_equal_lines_file(char *first_line, t_dims d, char *file);
int			len_header_map(char *file);
int			check_map2(char *file, t_dims d, char *first_line);
int			check_at_least_one_empty(t_dims d, char *file);
void		read_file(int argc, char *argv[], int i);
void		read_stdin(int fd, char buff);
void		free_corners(t_corner **map_corner, int lines);
void		free_map(char **map, int lines);

#endif
