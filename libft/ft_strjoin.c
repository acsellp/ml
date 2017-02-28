/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:41:34 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:33:43 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	l = 0;
	i = 0;
	while (*(s1 + i++))
		l++;
	i = 0;
	while (*(s2 + i++))
		l++;
	str = (char*)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
