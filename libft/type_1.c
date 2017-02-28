/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:41:56 by dplesca           #+#    #+#             */
/*   Updated: 2017/01/27 18:34:43 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	type_j(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll)
{
	uintmax_t	uim;
	intmax_t	im;

	if (sw == 1 || sw == 2)
	{
		uim = va_arg(ap, uintmax_t);
		*ull = (t_ull)uim;
	}
	else if (sw == 0 || sw == 3)
	{
		im = va_arg(ap, intmax_t);
		*ll = (t_ll)im;
	}
	return (1);
}

int	type_z(t_ull *ull, va_list ap, uint8_t sw, t_ll *ll)
{
	size_t	sz;
	ssize_t	ssz;

	if (sw == 1 || sw == 2)
	{
		sz = va_arg(ap, size_t);
		*ull = (t_ull)sz;
	}
	else if (sw == 0 || sw == 3)
	{
		ssz = va_arg(ap, ssize_t);
		*ll = (t_ll)ssz;
	}
	return (1);
}
