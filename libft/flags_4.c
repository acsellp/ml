/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:35:45 by dplesca           #+#    #+#             */
/*   Updated: 2017/01/27 17:51:52 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag2do(char *s, t_write *wr, int *x, int *max)
{
	if (wr->param->flags['#'])
		wr->cnt += wr->ftwrite("0", 1);
	if (*s == '0' && !wr->param->width)
	{
		while (*max < wr->param->width--)
			wr->cnt += wr->ftwrite(" ", 1);
		return ;
	}
	while (wr->param->prec-- > *x)
		wr->cnt += wr->ftwrite("0", 1);
	wr->cnt += wr->ftwrite(s, *x);
	while (*max < wr->param->width--)
		wr->cnt += wr->ftwrite(" ", 1);
}

void	flag20o(char *s, t_write *wr, int *x, int *max)
{
	if (!wr->param->prec && *s == '0' && wr->param->flags['.'])
	{
		if (!wr->param->width && wr->param->flags['#'])
		{
			wr->cnt += wr->ftwrite("0", 1);
			return ;
		}
		while (0 < wr->param->width--)
			wr->cnt += wr->ftwrite(" ", 1);
		return ;
	}
	while (*max < wr->param->width--)
		wr->cnt += wr->ftwrite(" ", 1);
	if (wr->param->flags['#'] && *s != '0' && !wr->param->prec)
		wr->cnt += wr->ftwrite("0", 1);
	while (wr->param->prec-- > *x)
		wr->cnt += wr->ftwrite("0", 1);
	wr->cnt += wr->ftwrite(s, *x);
}

void	flag30o(char *s, t_write *wr, int *x, int *max)
{
	if (wr->param->flags['#'] && *s != '0')
		wr->cnt += wr->ftwrite("0", 1);
	while (*max < wr->param->width--)
		wr->cnt += wr->ftwrite("0", 1);
	while (wr->param->prec-- > *x)
		wr->cnt += wr->ftwrite("0", 1);
	wr->cnt += wr->ftwrite(s, *x);
}
