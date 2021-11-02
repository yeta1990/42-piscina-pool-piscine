/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:19:01 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/17 18:18:53 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (to_find[i])
	{
		while (str[j])
		{
			if (to_find[i] == str[j])
			{
				printf("yes, %c, %c", to_find[i], str[j]);
				return (str + j);
			}
			j++;
		}
	//	j = 0;
		i++;
	}
	return (0);
}


*/
int	get_size(char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	size = get_size(to_find);
	if (to_find[0] == '\0')
		return (str);
	while (str[j])
	{
		if (to_find[0] == str[j])
		{
			i = 0;
			while (to_find[i])
			{
				if (to_find[i] != str[j + i])
					break ;
				i++;
			}
			if (i == size)
				return (str + j);
		}
		j++;
	}
	return (0);
}

int	get_size(char *to_find)
{
	int	size;

	size = 0;
	while (to_find[size])
		size++;
	return (size);
}
