/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:26:21 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/22 23:18:01 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

void	print_num_mgr_bil(char *input, t_dic_entry *dic, int lines)
{
	int	i;

	i = 0;
	while (input[i] == '0')
		i++;
	if (input[i] == '+')
		i++;
	print_num_manager(input[i] - 48, dic, lines);
	write(1, " ", 1);
	find_num(1000000000, dic, lines);
	write(1, " ", 1);
	print_num_manager(f_atoi((input + i + 1)), dic, lines);
}

void	thous_helps(unsigned int i, t_dic_entry *dic, int lines)
{
	find_num(i, dic, lines);
	write(1, " ", 1);
}
