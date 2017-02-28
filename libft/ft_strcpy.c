/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:34:34 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:35:16 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t sz;

	sz = 0;
	while (src[sz])
	{
		dest[sz] = src[sz];
		sz++;
	}
	dest[sz] = '\0';
	return (dest);
}
