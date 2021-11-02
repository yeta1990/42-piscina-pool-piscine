/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:03:40 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/26 17:41:39 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		cont_char(char *charset, char c);
void	assign_mem(char **p, char *str, char *charset);
char	**copy_words(char **p, char *str, char *charset);
char	**copy_str(char *str);

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		words;
	int		in_word;
	char	**p;

	i = 0;
	words = 0;
	in_word = 1;
	if (charset[0] == '\0')
		return (copy_str(str));
	while (str[i++])
	{
		if (cont_char(charset, str[i]) == 0 && str[i + 1] == 0)
			words++;
		else if (cont_char(charset, str[i]) == 0)
			in_word = 1;
		else if (cont_char(charset, str[i]) && (in_word))
		{
			in_word = 0;
			words++;
		}
	}
	p = malloc(sizeof(char *) * (words + 1));
	assign_mem(p, str, charset);
	return (copy_words(p, str, charset));
}

void	assign_mem(char **p, char *str, char *charset)
{
	int	i;
	int	size;
	int	words;

	i = -1;
	size = 0;
	words = 0;
	while (str[++i])
	{
		if (cont_char(charset, str[i]) == 0 && str[i + 1] == 0)
			p[words++] = malloc(sizeof(char *) * (size + 1));
		else if (cont_char(charset, str[i]) == 0)
			size++;
		else if (cont_char(charset, str[i]) && size > 0)
		{
			p[words++] = malloc(sizeof(char *) * (size + 1));
			size = 0;
		}
	}
	p[words] = 0;
}

int	cont_char(char *charset, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	**copy_words(char **p, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	i = -1;
	j = 0;
	word = 0;
	while (str[++i])
	{
		if (cont_char(charset, str[i]) == 0 && str[i + 1] == 0 && j == 0)
		{	
			p[word][j] = str[i];
			p[word][j + 1] = '\0';
		}	
		else if (cont_char(charset, str[i]) == 0)
			p[word][j++] = str[i];
		else if (cont_char(charset, str[i]) && j > 0)
		{	
			p[word][j++] = '\0';
			word++;
			j = 0;
		}
	}
	return (p);
}

char	**copy_str(char *str)
{
	int		len;
	int		i;
	char	**p;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	p = malloc(sizeof(char *) * 2);
	p[0] = malloc(sizeof(char) * len + 1);
	p[1] = 0;
	len = 0;
	while (str[len])
	{
		p[0][i] = str[len];
		i++;
		len++;
	}
	p[0][i] = '\0';
	return (p);
}
