/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:45:46 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/07 18:17:31 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	i;

	s = malloc(count * size);
	i = 0;
	if (!s)
		return (NULL);
	while (i < (count * size))
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (s);
}
