/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:54:05 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/17 15:55:14 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	if (lst)
	{
		size = 1;
		while (lst->next)
		{
			size++;
			lst = lst->next;
		}
	}
	return (size);
}
