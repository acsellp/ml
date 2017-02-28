/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:35:29 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:31:28 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	sz;
	size_t	i;

	sz = 0;
	while (dest[sz])
		sz++;
	i = 0;
	while (src[i])
	{
		dest[sz + i] = src[i];
		i++;
	}
	dest[sz + i] = '\0';
	return (dest);
}
