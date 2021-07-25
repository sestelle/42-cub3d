/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:28:19 by sestelle          #+#    #+#             */
/*   Updated: 2020/10/30 18:46:37 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*str1;

	str1 = s;
	c = (unsigned char)c;
	while (n--)
		if (*(str1++) == c)
			return (--str1);
	return (0);
}
