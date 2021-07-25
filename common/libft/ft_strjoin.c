/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:42:28 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/07 19:23:34 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	s = (char *)malloc((i + j + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		s[i] = s1[i];
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
