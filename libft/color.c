/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:34:41 by dplesca           #+#    #+#             */
/*   Updated: 2017/01/27 17:33:44 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftcolor(char *fmt)
{
	int ret;

	ret = 0;
	if (ft_strnstr(fmt, "{red}", 10))
		ret = ftwrite("\e[31m", 6) - 1;
	else if (ft_strnstr(fmt, "{green}", 10))
		ret = ftwrite("\e[32m", 6) + 1;
	else if (ft_strnstr(fmt, "{white}", 10))
		ret = ftwrite("\e[37m", 6) + 1;
	else if (ft_strnstr(fmt, "{blue}", 10))
		ret = ftwrite("\e[34m", 6);
	else if (ft_strnstr(fmt, "{cyan}", 10))
		ret = ftwrite("\e[36m", 6);
	else if (ft_strnstr(fmt, "{yellow}", 10))
		ret = ftwrite("\e[33m", 6) + 2;
	else if (ft_strnstr(fmt, "{magenta}", 10))
		ret = ftwrite("\e[35m", 6) + 3;
	else if (ft_strnstr(fmt, "{eoc}", 10))
		ret = ftwrite("\e[0m", 6) - 1;
	else
		return (0);
	return (ret);
}
