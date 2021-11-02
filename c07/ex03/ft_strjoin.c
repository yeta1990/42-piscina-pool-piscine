/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:26:00 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/26 15:27:58 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		tl(char **strs, int size);
int		gs(char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	i = -1;
	k = 0;
	if (size == 0)
		return (malloc(1));
	ret = malloc(sizeof(char) * ((gs(sep)) * (size - 1)) + tl(strs, size) + 1);
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			ret[k++] = strs[i][j];
		if (i < size - 1)
		{
			j = -1;
			while (sep[++j])
				ret[k++] = sep[j];
		}
	}
	ret[k] = '\0';
	return (ret);
}

int	tl(char **strs, int size)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	length = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			length++;
			j++;
		}
		j = 0;
		i++;
	}
	return (length);
}

int	gs(char *sep)
{
	int	sep_length;

	sep_length = 0;
	while (sep[sep_length])
		sep_length++;
	return (sep_length);
}
