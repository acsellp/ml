/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:49:44 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:23:15 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;

	ssrc = (unsigned char *)src;
	sdest = (unsigned char *)dest;
	while (n)
	{
		*sdest = *ssrc;
		ssrc++;
		sdest++;
		n--;
	}
	return (dest);
}
