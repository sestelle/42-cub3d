/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:22:53 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/03 03:03:32 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		i;

	index = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			index = i;
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	if (index == -1)
		return (NULL);
	else
	{
		return ((char *)(s + index));
	}
}
