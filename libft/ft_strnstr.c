/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:37:30 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:35:49 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t y;
	size_t x;

	x = 0;
	if (!*s2)
		return ((char *)s1);
	while (x < n && s1[x])
	{
		y = 0;
		while (x + y < n && s1[x + y] && s1[x + y] == *(s2 + y) && s2[y])
			y++;
		if (!*(s2 + y))
			return ((char *)(s1 + x));
		x++;
	}
	return (NULL);
}
