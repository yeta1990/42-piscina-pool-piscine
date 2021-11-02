/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header_map2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenas-u <dpenas-u@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:35:27 by dpenas-u          #+#    #+#             */
/*   Updated: 2021/08/26 09:57:24 by dpenas-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq_header.h"

int	check_at_least_one_empty(t_dims d, char *file)
{
	int		f;
	char	b;
	int		bl;

	b = 0;
	bl = 0;
	f = open(file, O_RDONLY);
	while (read(f, &b, 1) == 1)
	{
		if (b == 10 && bl == 0)
			bl = 1;
		else if (b == d.empty && bl == 1)
		{
			close(f);
			return (1);
		}
	}
	close(f);
	return (0);
}
