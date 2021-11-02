/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:04:28 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/11 20:26:12 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lower(char s);
int		is_alpha(char s);
int		is_upper(char s);

char	*ft_strcapitalize(char *str)
{
	int	length;
	int	wordposition;

	length = 0;
	wordposition = 0;
	while (str[length])
	{
		if (is_alpha(str[length]))
		{
			if (is_lower(str[wordposition]))
			{
				str[wordposition] = str[wordposition] - 32;
			}
			else if (is_upper(str[length]) && is_alpha(str[length - 1]))
			{
				str[length] = str[length] + 32;
			}
		}
		else
			wordposition = length + 1;
		length++;
	}
	return (str);
}

int	is_alpha(char s)
{
	if (s < 48 || (s > 57 && s < 65) || (s > 90 && s < 97) || s > 122)
		return (0);
	else
		return (1);
}

int	is_lower(char s)
{
	if (s < 97 || s > 122)
		return (0);
	return (1);
}

int	is_upper(char s)
{
	if (s > 64 && s < 91)
		return (1);
	return (0);
}
