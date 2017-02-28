/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:37:08 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:36:31 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	char	*s;
	char	*st;
	char	*ss;

	if (!*n)
		return ((char*)h);
	s = (char*)h;
	while (*s)
	{
		st = s;
		ss = (char*)n;
		while (!(*st - *ss) && *st && *ss)
		{
			st++;
			ss++;
		}
		if (!*ss)
			return (s);
		s++;
	}
	return (NULL);
}
