/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:41:50 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:36:55 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static	void	cpy(int f, int i, char *str, char const *s)
{
	size_t	n;

	n = 0;
	while (f <= i)
		str[n++] = s[f++];
	str[n] = '\0';
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	f;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i + 1])
		i++;
	while (i)
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		else
			break ;
	f = 0;
	while (s[f] == ' ' || s[f] == '\n' || s[f] == '\t')
		f++;
	if (i < f)
		i = f;
	if ((str = (char*)malloc(sizeof(char) * (i - f + 1))) == NULL)
		return (NULL);
	cpy(f, i, str, s);
	return (str);
}
