/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 07:43:36 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/03 04:24:45 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if (dst == NULL && src == NULL)
			break ;
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
