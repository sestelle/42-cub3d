/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:23:23 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/08 20:33:44 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		size;
	int		i;

	size = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[size])
		size++;
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
