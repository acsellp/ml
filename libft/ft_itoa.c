/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:46:51 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:20:51 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_calc(char *s, int size, int x, long int nr)
{
	while (++x < size)
		*(s + x) = ft_getnbr(nr, (size - 1) - x);
	*(s + x) = '\0';
}

char			*ft_itoa(int n)
{
	char			*s;
	int				size;
	int				neg;
	int				i;
	long int		nr;

	nr = (long int)n;
	neg = 0;
	if (nr < 0)
	{
		nr *= -1;
		neg = 1;
	}
	size = ft_nbrsize(nr);
	if (!(s = malloc(sizeof(char) * (1 + size + neg))))
		return (NULL);
	i = neg + -1;
	if (neg)
		s[0] = '-';
	ft_calc(s, size + neg, i, nr);
	return (s);
}
