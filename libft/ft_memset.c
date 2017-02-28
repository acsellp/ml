/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:48:58 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:23:42 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			nr;
	unsigned char	*p;

	p = (unsigned char*)s;
	nr = 0;
	while (nr < n)
	{
		*p = c;
		nr++;
		p++;
	}
	return (s);
}
