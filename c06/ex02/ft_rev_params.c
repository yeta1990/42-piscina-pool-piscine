/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:58:58 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/17 10:06:23 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	argc--;
	while (argc > 0)
	{
		while (argv[argc][i])
		{
			write(1, &argv[argc][i], 1);
			i++;
		}
		i = 0;
		write(1, "\n", 1);
		argc--;
	}
}
