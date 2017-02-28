/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:51:30 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:22:28 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = malloc(size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(p + i) = 0;
		i++;
	}
	return ((void*)p);
}
