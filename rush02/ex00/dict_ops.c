/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 09:55:10 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/22 18:39:36 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush_header.h"

int	count_lines(char *dictsrc)
{
	int		lines;
	int		f;
	char	c;

	lines = 0;
	f = open(dictsrc, O_RDONLY);
	if (f == -1)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	while (read(f, &c, 1) == 1)
	{
		if (c == '\n')
			lines++;
	}
	close(f);
	return (lines);
}

void	parse_num(char *dictsrc, int lines, t_dic_entry *dic, char c)
{
	int				i;
	int				f;
	unsigned int	num;

	i = 0;
	num = 0;
	f = open(dictsrc, O_RDONLY);
	while (read(f, &c, 1) == 1 && i < lines)
	{
		if (c >= '0' && c <= '9')
			num = num * 10 + c - 48;
		else if (c == ':')
		{
			dic[i].key = num;
			num = 0;
		}
		else if ((c >= 32 && c < 127) || c == '\n')
			val_len(c, i, dic);
		if (c == '\n')
			i++;
	}
	close(f);
}

void	val_len(char c, int i, t_dic_entry *dic)
{
	int	len;
	int	phase;

	len = 0;
	phase = 1;
	if (c >= 32 && c < 127 && phase == 3)
		len++;
	else if (c > 32 && c < 127)
	{
		phase = 3;
		len++;
	}
	else if (c == '\n')
	{
		dic[i].val = (char *)malloc(sizeof(char) * len);
		len = 1;
		phase = 0;
	}
}

void	copy_values(char *dictsrc, t_dic_entry *dic, char c)
{
	int		i;
	int		j;
	int		f;
	int		phase;

	i = 0;
	j = 0;
	f = open(dictsrc, O_RDONLY);
	while (read(f, &c, 1) == 1)
	{
		if (c == ':')
			phase = 2;
		else if (c >= 32 && c < 127)
		{
			if (phase == 2 && c != 32)
				phase = 3;
			if (phase == 3)
				dic[i].val[j++] = c;
		}
		else if (c == '\n')
			close_line(&i, &j, dic, &phase);
	}
	close(f);
}

void	close_line(int *i, int *j, t_dic_entry *dic, int *phase)
{
	int	h;
	int	k;

	h = *i;
	k = *j;
	dic[h].val[k] = '\0';
	*j = 0;
	*phase = 0;
	*i = h + 1;
}
