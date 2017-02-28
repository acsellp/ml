/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:36:57 by dplesca           #+#    #+#             */
/*   Updated: 2017/01/27 18:04:49 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull	ft_upow(int n, int p)
{
	if (p == 0)
		return (1);
	else
		return (n * ft_pow(n, p - 1));
}

char	*ft_utoa_base(t_ull n, int base, int up)
{
	char	*s;
	int		i;

	i = 1;
	while (ft_upow(base, i) - 1 < n)
		i++;
	i = (i == 64) ? 20 : i;
	s = (char *)malloc(sizeof(char) * i);
	s[i] = '\0';
	while (i-- > 0)
	{
		s[i] = (n % base) + (n % base > 9 ? ('A' - 10) + up : '0');
		n /= base;
	}
	return (s);
}
