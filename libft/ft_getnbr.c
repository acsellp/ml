/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 12:23:50 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 12:23:53 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_getnbr(long int nr, int pos)
{
	long int	n;
	int			x;

	x = 0;
	while (x++ < pos)
		nr /= 10;
	n = nr;
	n -= nr % 10;
	nr = nr - n;
	return (nr + '0');
}
