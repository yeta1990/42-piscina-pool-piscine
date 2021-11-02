/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:44:28 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/22 23:17:15 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_HEADER_H
# define RUSH_HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct dc
{
	unsigned int	key;
	char			*val;
}	t_dic_entry;

void			ft_putstr(char *str);
int				n_l(int l, unsigned int n);
void			print_num_manager(unsigned int n, t_dic_entry *dic, int lines);
void			print_num(unsigned int n, t_dic_entry *dic, int lines);
int				find_num(unsigned int n, t_dic_entry *dic, int lines);
int				rec_power(int nb, int power);
int				count_lines(char *dictsrc);
void			parse_num(char *dictsrc, int lines, t_dic_entry *dic, char c);
void			copy_values(char *dictsrc, t_dic_entry *dic, char c);
void			copy_values_aux(t_dic_entry *dic, char c, int phase);
void			val_len(char c, int i, t_dic_entry *dic);
int				is_dict(char *file);
unsigned int	f_atoi(char *str);
int				str_len(char *str);
int				is_num_ok(char *str);
int				is_num_ok_2(char *str, int i);
void			print_num_manager(unsigned int n, t_dic_entry *dic, int lines);
void			print_num(unsigned int n, t_dic_entry *dic, int lines);
void			print_num_mgr_bil(char *input, t_dic_entry *dic, int lines);
int				find_num(unsigned int n, t_dic_entry *dic, int lines);
void			main_controller(char *input, char *dictsrc);
void			free_me(int lines, t_dic_entry *dic);
void			close_line(int *i, int *j, t_dic_entry *dic, int *phase);
int				print_mgr_helper(unsigned int n, t_dic_entry *dic, int lines);
unsigned int	get_num_to_print(unsigned int n, int reps, int i);
void			thous_helps(unsigned int i, t_dic_entry *dic, int lines);

#endif
