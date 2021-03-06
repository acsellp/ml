/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 19:55:05 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:23:31 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;

	ssrc = (unsigned char *)src;
	sdest = (unsigned char *)dest;
	if (ssrc >= (sdest + n) || sdest <= ssrc)
	{
		while (n--)
			*sdest++ = *ssrc++;
	}
	else
	{
		sdest = sdest + n - 1;
		ssrc = ssrc + n - 1;
		while (n)
		{
			n--;
			*sdest-- = *ssrc--;
		}
	}
	return (dest);
}
