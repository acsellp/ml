/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:36:14 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:33:54 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t ld;
	size_t ls;

	ld = 0;
	ls = 0;
	while (ld < n && dest[ld] != '\0')
		ld++;
	while (ld + ls < n - 1 && src[ls] != '\0')
	{
		dest[ld + ls] = src[ls];
		ls++;
	}
	if (ld < n)
		dest[ld + ls] = '\0';
	return (ft_strlen(src) + ld);
}
