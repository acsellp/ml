/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:40:52 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:33:13 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1)
		return (0);
	else if (!s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		if (s1[i + 1] == '\0' && s2[i + 1] != '\0')
			return (0);
		if (s1[i + 1] != '\0' && s2[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}
