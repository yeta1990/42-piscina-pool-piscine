/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:49:41 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/22 23:18:37 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

void	print_num_manager(unsigned int n, t_dic_entry *dic, int lines)
{
	int				reps;
	int				i;

	i = -1;
	reps = (n_l(0, n) / 3);
	if (n_l(0, n) % 3 != 0)
		reps++;
	if (print_mgr_helper(n, dic, lines))
		return ;
	while (++i < reps)
	{
		if (get_num_to_print(n, reps, i) && i < reps)
			print_num(get_num_to_print(n, reps, i), dic, lines);
		if (i != reps - 1 && get_num_to_print(n, reps, i))
			write(1, " ", 1);
		if (i < reps - 1 && (get_num_to_print(n, reps, i) > 1 || n_l(0, n) < 5))
		{
			find_num(rec_power(10, 3 * (reps - i - 1)), dic, lines);
			if (n != 100 && n != 10000)
				write(1, " ", 1);
		}
		else if (i < reps - 1)
			thous_helps(rec_power(10, 3 * (reps - i - 1)), dic, lines);
	}
}

int	print_mgr_helper(unsigned int n, t_dic_entry *dic, int lines)
{
	if (n == 0)
	{
		find_num(n, dic, lines);
		return (1);
	}	
	if ((n / 100 == 1 && n % 100 == 0)
		|| (n / 1000 == 1 && n % 1000 == 0)
		|| (n / 1000000 == 1 && n % 1000000 == 0)
		|| (n / 1000000000 == 1 && n % 1000000000 == 0))
	{
		find_num(1, dic, lines);
		write(1, " ", 1);
		print_num(n, dic, lines);
		return (1);
	}
	return (0);
}

unsigned int	get_num_to_print(unsigned int n, int reps, int i)
{
	unsigned int	num_to_print;

	num_to_print = n % rec_power(10, 3 * (reps - i));
	num_to_print = num_to_print / rec_power (10, 3 * (reps - i - 1));
	return (num_to_print);
}

void	print_num(unsigned int n, t_dic_entry *dic, int lines)
{
	if (find_num(n, dic, lines) == 1)
	{
		return ;
	}
	else if (n / 100 > 0 && find_num(n / 100, dic, lines) == 1)
	{
		write(1, " ", 1);
		find_num(100, dic, lines);
		if (n % 100 > 0 && n / 100 != 0)
		{
			write(1, " ", 1);
			print_num(n % 100, dic, lines);
		}
		return ;
	}
	else if (n / 10 > 0)
	{
		if (find_num((n / 10) * 10, dic, lines) == 1)
			write(1, " ", 1);
		print_num(n % 10, dic, lines);
	}
	else
		write(1, "Dict Error", 10);
}

int	find_num(unsigned int n, t_dic_entry *dic, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		if (n == dic[i].key)
		{
			ft_putstr(dic[i].val);
			return (1);
		}
		i++;
	}
	return (0);
}
