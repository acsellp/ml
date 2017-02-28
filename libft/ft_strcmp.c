/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:37:45 by dplesca           #+#    #+#             */
/*   Updated: 2016/12/11 14:31:59 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int dif;
	int l;

	dif = 0;
	l = 0;
	while (*(s1 + l) != 0 || *(s2 + l) != 0)
	{
		dif = *(unsigned char *)(s1 + l) - *(unsigned char *)(s2 + l);
		if (dif != 0)
			break ;
		l++;
	}
	return (dif);
}
