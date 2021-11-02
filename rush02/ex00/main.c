/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 09:46:27 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/22 21:33:16 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	main(int argc, char *argv[])
{
	if (argc == 2 && is_dict("numbers.dict") && is_num_ok(argv[1]))
		main_controller(argv[1], "numbers.dict");
	else if (argc == 3 && is_dict(argv[1]) && is_num_ok(argv[2]))
		main_controller(argv[2], argv[1]);
	else if (argc == 3 && is_dict(argv[1]) == 0)
		write(1, "Dict Error\n", 11);
	else if (argc == 1)
		write(1, "Usage: ./rush-02 [num] or ./rush-02 [.dict] [num]\n", 50);
}

void	main_controller(char *input, char *dictsrc)
{
	int			lines;
	t_dic_entry	*dic;
	char		c;

	c = 0;
	lines = 0;
	lines = count_lines(dictsrc);
	dic = (t_dic_entry *)malloc(sizeof(t_dic_entry) * (lines));
	parse_num(dictsrc, lines, dic, c);
	copy_values(dictsrc, dic, c);
	if (is_num_ok(input) == 2)
		print_num_mgr_bil(input, dic, lines);
	else
		print_num_manager(f_atoi(input), dic, lines);
	write(1, "\n", 1);
	free_me(lines, dic);
}

void	free_me(int lines, t_dic_entry *dic)
{
	while (--lines >= 0)
	{
		free(dic[lines].val);
		if (lines == 0)
			free(dic);
	}
}
