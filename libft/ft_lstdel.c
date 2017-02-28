/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:52:20 by dplesca           #+#    #+#             */
/*   Updated: 2016/11/25 17:11:45 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alt, void (*del)(void *, size_t))
{
	if (alt && *alt)
	{
		if ((*alt)->next)
			ft_lstdel(&(*alt)->next, del);
		ft_lstdelone(alt, del);
	}
}
