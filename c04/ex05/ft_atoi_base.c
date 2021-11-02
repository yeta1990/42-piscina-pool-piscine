/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:57:39 by albgarci          #+#    #+#             */
/*   Updated: 2021/08/19 23:01:27 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_duplchar(char *str);
int ft_atoi(char *str, char *base);
int	get_encr_numb(int pos, char *str, char *base);
int	ft_recursive_power(int nb, int power);
int get_position(char c, char *base);

int ft_atoi_base(char *str, char *base)
{
	int	base_length;
	int	i;

	i = 0;
	base_length = 0;
	while (base[base_length])
	{
		if (base[base_length] == 43 || base[base_length] == 45)
			return 0;
		base_length++;
	}
	if (base_length < 2 || ft_duplchar(base) == 0)
		return 1;
	return (ft_atoi(str, base));
	
}

int ft_atoi(char *str, char *base)
{
	int	i;
	int	number;
	int	j;
	int	sign;

	j = 0;
	number = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	number = get_encr_numb(i, str, base);
	return (number * sign);
}

int	ft_duplchar(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[j + 1])
		{
			if (str[i] == str[j + 1])
				return (0);
			j++;
		}
		i++;
		j = i;
	}
	return (1);
}

int get_encr_numb(int pos, char *str, char *base)
{
	int	i;
	int	j;
	int number;
	int	base_length;

	i = 0;
	j = 0;
	number = 0;
	base_length = 0;
	
	while (base[base_length])
		base_length++;
	printf("%i ", pos + i);
	
	while (str[pos + i])
	{
		printf("%c", str[pos + 1]);
		j = 0;
		while(base[j])
		{
			if (base[j] == str[i])
				j = 0;
			else 
				j++;
		}
		i++;

		//if (j != 0)
		//	break;
	}
	/*
	if (i == 0)
		return 0;
	
	j = 0;
	while (j < i)
	{
		number = number + get_position(str[j], base) * ft_recursive_power(base_length, i - j);
		j++;
	}*/
	return (number);
}

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	return (0);
}

int get_position(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}	
