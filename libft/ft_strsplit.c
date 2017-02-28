/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:42:12 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:36:12 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		size(const char *s, char c)
{
	int		sz;

	sz = 0;
	while (s[sz] != c && s[sz])
		sz++;
	return (sz);
}

static int		words(const char *s, char c)
{
	int		nr;
	int		i;

	i = 0;
	nr = 0;
	while (*s)
	{
		if (*s != c && !i)
		{
			i = 1;
			nr++;
		}
		if (*s == c && i)
			i = 0;
		s++;
	}
	return (nr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nr;
	char	**arr;

	if (!s)
		return (NULL);
	nr = words(s, c);
	arr = (char **)malloc(sizeof(char*) * (nr + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (nr--)
	{
		while (*s == c && *s)
			s++;
		arr[i] = ft_strsub(s, 0, size(s, c));
		if (!arr[i])
			return (NULL);
		s = s + size(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
