/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sestelle <sestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:22:07 by sestelle          #+#    #+#             */
/*   Updated: 2020/11/17 18:47:55 by sestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_2;
	t_list	*new;
	t_list	*tmp_1;

	if (!lst)
		return (NULL);
	tmp_1 = lst;
	new = NULL;
	while (tmp_1)
	{
		tmp_2 = ft_lstnew(f(tmp_1->content));
		if (!tmp_2)
		{
			ft_lstclear(&new, del);
			break ;
		}
		ft_lstadd_back(&new, tmp_2);
		tmp_1 = tmp_1->next;
	}
	return (new);
}
