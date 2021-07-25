/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:32:24 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/03 19:45:04 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc((i + 1) * sizeof(char));
	if (s2 != NULL)
	{
		i = 0;
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	else
	{
		return (NULL);
	}
}
