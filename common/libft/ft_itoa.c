/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:57:31 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/17 15:57:37 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int *n)
{
	int		sign;

	sign = 0;
	if (*n < 0)
	{
		*n *= -1;
		sign = 1;
	}
	return (sign);
}

static int	ft_size(int n)
{
	int		size;

	size = 0;
	while (1)
	{
		n /= 10;
		if (n != 0)
			break ;
		size += 1;
	}
	return (size);
}

static char	*ft_fill(char *str, int size, int n, int sign)
{
	str[--size] = '\0';
	while (size--)
	{
		str[size] = n % 10 + 48;
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(n) + 2;
	sign = ft_sign(&n);
	size += sign;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_fill(str, size, n, sign);
	return (str);
}
