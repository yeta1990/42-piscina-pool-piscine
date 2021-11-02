/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:32:28 by mtacunan          #+#    #+#             */
/*   Updated: 2021/08/22 21:25:59 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_header.h"

int	is_dict(char *file)
{
	int		i;
	int		aux;
	int		f;
	char	*dict;

	i = 0;
	aux = 4;
	dict = ".dict\0";
	f = open(file, O_RDONLY);
	if (f == -1 || file[i] == '\0')
		return (0);
	while (file[i] != '\0')
		i++;
	while (aux >= 0)
	{
		if (file[i - 1] != dict[aux])
			return (0);
		aux--;
		i--;
		return (1);
	}
	return (1);
}

int	is_num_ok(char *str)
{
	int	i;

	i = 0;
	if (str_len(str) == 0)
	{
		write(1, "Error. Introduce a number, i.e.: ./rush-02 [number]\n", 52);
		return (0);
	}
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{	
		write(1, "Error. Introduce only positive numbers\n", 39);
		return (0);
	}
	if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
	{	
		write(1, "Error. Introduce a number, i.e.: ./rush-02 [number]\n", 52);
		return (0);
	}
	return (is_num_ok_2(str, i));
}

int	is_num_ok_2(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] == '0')
		i++;
	while (str[i + j] >= '0' && str[i + j] <= '9')
		j++;
	if (str[i + j] == '.')
	{
		write(1, "Error. Only positive integer numbers are allowed\n", 49);
		return (0);
	}
	if (j == 10)
		return (2);
	if (j > 10)
	{
		write(1, "Error. Max possible number is 4294967295\n", 41);
		return (0);
	}
	return (1);
}
