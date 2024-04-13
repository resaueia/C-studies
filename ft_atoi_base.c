/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:26:39 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/04/12 20:58:18 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	value(char *str, char c)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return(i);	
		}
		i++;
	}
	return (0);
}

int	power(int base, int exp)
{
	int value = 1;
	int i = 0;

	while (i < exp)
	{
		value = base * value;
		i++;
	}
	return (value);
}


int	ft_atoi_base(const char *str, int str_base)
{
	char	*lower = "0123456789abcdef";

	int	result = 0;
	int	len = 0;
	int	index = 0;
	int v = 0;
	int mult = 0; 
	while (str[len])
		len++;
	while (index < len)
	{
		v = value(lower, str[len - 1 - index]);
		mult = power(str_base, index);
		result = result + (v * mult);
		index++;
	}
	return (result);
}

#include <stdio.h>
int main(int c, char **v)
{
	int n = ft_atoi_base(v[1], 12);
	printf("result: %i\n", n);
	return(0);
}
