/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 08:56:25 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/02 17:52:14 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (dst > src)
	{
		while (len--)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else if (dst < src)
	{
		while (len--)
		{
			if (dst == NULL && src == NULL)
				break ;
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
