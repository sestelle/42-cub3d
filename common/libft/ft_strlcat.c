/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:20:17 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/03 19:13:29 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (j < dstsize && dst[j])
		j++;
	if (dstsize <= j)
		return (j + i);
	k = 0;
	while (dstsize && (--dstsize - j) && src[k])
	{
		dst[j + k] = src[k];
		k++;
	}
	dst[j + k] = '\0';
	return (i + j);
}
