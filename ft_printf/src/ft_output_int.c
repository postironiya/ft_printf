/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:06:14 by rmarguri          #+#    #+#             */
/*   Updated: 2020/08/01 20:04:01 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	output_pre(t_flag flag, int n)
{
	int res;
	int l;
	int l1;
	int m;

	res = 0;
	l = ft_nbrlen(n, 10);
	l1 = l;
	m = n < 0 ? 1 : 0;
	if (flag.accur_f > l)
		l1 = flag.accur_f;
	if (flag.accur_f == 0 && n == 0)
		l1 = 0;
	if (flag.width_f > flag.accur_f && (!flag.zero_f || flag.accur_f >= 0) \
	&& !flag.minus_f && flag.width_f >= 0)
		res += spam(flag.width_f - m - l1, ' ');
	if (m)
		res += ft_putchar('-');
	if (flag.accur_f <= -1 && !flag.minus_f && flag.width_f >= 0 && flag.zero_f)
		res += spam(flag.width_f - m - l1, '0');
	if (flag.accur_f > l)
		res += spam(flag.accur_f - l, '0');
	return (res);
}

static int	output_suf(t_flag flag, int n)
{
	int res;
	int l;
	int l1;
	int	m;

	res = 0;
	m = n < 0 ? 1 : 0;
	l = ft_nbrlen(n, 10);
	l1 = l;
	if (flag.accur_f > l)
		l1 = flag.accur_f;
	if (!flag.accur_f && n == 0)
		l1 = 0;
	if ((flag.minus_f || flag.width_f < 0) && ft_abs(flag.width_f) > l \
	&& flag.width_f != 0)
		res += spam(ft_abs(flag.width_f) - m - l1, ' ');
	return (res);
}

int			output_int(va_list *args, t_flag flag)
{
	int		res;
	int		n;

	res = 0;
	n = va_arg(*args, int);
	res += output_pre(flag, n);
	if (flag.accur_f != 0 || n != 0)
		res += ft_itoa_base(n, 10, "0123456789\0");
	res += output_suf(flag, n);
	return (res);
}
