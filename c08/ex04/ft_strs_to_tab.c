/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:49:32 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/25 22:23:43 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src);
int		get_size(char *s);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*p;

	i = 0;
	p = 0;
	if (ac > 0)
		p = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!p || ac < 0)
		return (p);
	while (i < ac && av[i])
	{
		p[i].size = get_size(av[i]);
		p[i].str = av[i];
		p[i].copy = malloc(sizeof(char) * (p[i].size + 1));
		if (p[i].copy)
			p[i].copy = ft_strdup(av[i]);
		else
			return (0);
		i++;
	}
	p[i].str = 0;
	return (p);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		size;

	size = 0;
	while (src[size])
		size++;
	p = malloc(sizeof(p) * (size + 1));
	size = 0;
	while (src[size])
	{
		p[size] = src[size];
		size++;
	}
	p[size] = '\0';
	return (p);
}

int	get_size(char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
