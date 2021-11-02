/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:38:19 by dpenas-u          #+#    #+#             */
/*   Updated: 2021/08/26 10:42:23 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	buff;
	int		fd;

	i = 1;
	buff = 0;
	fd = 0;
	if (argc > 1)
	{	
		while (i < argc)
		{
			read_file(argc, argv, i);
			i++;
		}
	}
	else if (argc == 1)
		read_stdin(fd, buff);
	return (0);
}

void	read_file(int argc, char *argv[], int i)
{
	char	*first_line;

	first_line = first_line_mem(argv[i]);
	if (first_line)
	{	
		if (check_map(argv[i], first_line) == 0)
		{
			ft_putstr("map error\n");
			if (argc == 2)
				exit(1);
		}
		else
			find_max_square(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		free(first_line);
	}
	else
	{
		ft_putstr("map error\n");
	}
}

void	read_stdin(int fd, char buff)
{
	char	*first_line;

	fd = open("user_map", O_TRUNC, 0644);
	close(fd);
	fd = open("user_map", O_WRONLY | O_CREAT | O_APPEND, 0644);
	while (read(0, &buff, 1))
		write(fd, &buff, 1);
	close(fd);
	first_line = first_line_mem("user_map");
	if (first_line)
	{
		if (check_map("user_map", first_line) == 0)
		{
			ft_putstr("map error\n");
			exit(1);
		}
		else
			find_max_square("user_map");
		free(first_line);
	}
	else
		exit(1);
}

void	find_max_square(char *file)
{
	char		**map;
	t_corner	**map_corner;
	t_dims		d;
	int			f;
	char		buff;

	f = 0;
	buff = 0;
	count_lines_and_cols(file, &d, f, buff);
	map = memory_for_map(d, file, f, buff);
	copy_map(map, file, f, buff);
	first_line_controller(file, &d);
	if (check_at_least_one_empty(d, file))
	{		
		map_corner = fill_corners(d);
		all_squares(map, map_corner, d);
		fill_square(map, check_biggest_square(map_corner, d), d);
		free_corners(map_corner, d.lines);
	}
	else
		print_map(map, d);
	free_map(map, d.lines);
}
