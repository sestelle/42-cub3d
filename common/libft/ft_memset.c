/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:11:28 by sestelle          #+#    #+#             */
/*   Updated: 2020/10/30 18:43:57 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*t;

	c = (unsigned char)c;
	t = b;
	while (len--)
	{
		*(t++) = c;
	}
	return (b);
}
