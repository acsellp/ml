/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dplesca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:34:31 by dplesca           #+#    #+#             */
/*   Updated: 2017/01/27 19:01:39 by dplesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull	lltoull(t_ll ll, t_write *wr)
{
	t_ull	ull;

	if (ll < 0)
	{
		wr->param->flags['&'] = '-';
		ull = ~ll;
		ull += 1;
	}
	else
		ull = ll;
	return (ull);
}

void	proc_(t_write *wr, char *s, int max, int x)
{
	if (wr->param->flags['-'])
		flag2d(s, wr, &x);
	else if (wr->param->flags['0'] && !wr->param->flags['.'] \
			&& !wr->param->flags[' '])
		flag30(s, wr, &x);
	else
		flag20(s, wr, &x, &max);
}

void	format_number_dd(va_list ap, t_write *wr)
{
	char	*s;
	int		x;
	int		max;
	t_ll	ll;
	t_ull	ull;

	if (wr->param->lenght)
		wr->type[wr->param->lenght](NULL, ap, 3, &ll);
	else
		ll = (t_ull)va_arg(ap, long int);
	ull = lltoull(ll, wr);
	s = ft_utoa_base(ull, 10, 0);
	x = ft_strlen(s);
	max = wr->param->prec > x ? wr->param->prec : x;
	while (wr->param->wild_card--)
		wr->cnt += wr->ftwrite(" ", 1);
	if ((wr->param->flags['+'] || wr->param->flags['&']))
		max++;
	else if (!wr->param->width && wr->param->flags['\x20'])
		wr->param->width = x + 1;
	proc_(wr, s, max, x);
	free(s);
}

void	format_number_d(va_list ap, t_write *wr)
{
	char	*s;
	int		x;
	int		max;
	t_ll	ll;
	t_ull	ull;

	if (wr->param->lenght)
		wr->type[wr->param->lenght](NULL, ap, 0, &ll);
	else
		ll = (t_ull)va_arg(ap, int);
	ull = lltoull(ll, wr);
	s = ft_utoa_base(ull, 10, 0);
	x = ft_strlen(s);
	max = wr->param->prec > x ? wr->param->prec : x;
	while (wr->param->wild_card--)
		wr->cnt += wr->ftwrite(" ", 1);
	if ((wr->param->flags['+'] || wr->param->flags['&']))
		max++;
	else if (!wr->param->width && wr->param->flags[' '])
		wr->cnt += wr->ftwrite(" ", 1);
	proc_(wr, s, max, x);
	free(s);
}
