/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:53:28 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:22:00 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*t;
	t_list	*new;
	t_list	*cp;

	if (!lst)
		return (NULL);
	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new = f(lst);
	new->next = NULL;
	lst = lst->next;
	cp = new;
	while (lst)
	{
		t = f(lst);
		new->next = t;
		t->next = NULL;
		lst = lst->next;
		new = new->next;
	}
	return (cp);
}
