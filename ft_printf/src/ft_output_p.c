/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:05:30 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:27:24 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			base_len(uint64_t n, int base)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

uint64_t	base_pow(uint64_t n, int pow)
{
	if (pow == 1)
		return (n);
	else if (pow == 0)
		return (1);
	else
		return (n * base_pow(n, pow - 1));
}

int			print_hex(uint64_t n)
{
	int		len;
	int		i;
	char	*hex;

	len = base_len(n, 16);
	i = 0;
	hex = "0123456789abcdef";
	while (i < len)
	{
		ft_putchar(hex[n / base_pow(16, len - i - 1)]);
		n = n % base_pow(16, len - i - 1);
		i++;
	}
	return (i);
}

static int	output_pre(t_flag flag, uint64_t n)
{
	int res;

	res = 0;
	if (flag.width_f >= 0 && !flag.minus_f)
	{
		if (!n && flag.accur_f != 0)
			res += spam(flag.width_f - 3, ' ');
		if (!n && flag.accur_f == 0)
			res += spam(flag.width_f - 2, ' ');
		if (n != 0)
			res += spam(flag.width_f - base_len(n, 16) - 2, ' ');
	}
	return (res);
}

int			output_p(va_list *args, t_flag flag)
{
	uint64_t	n;
	int			res;

	res = 0;
	n = va_arg(*args, uint64_t);
	res += output_pre(flag, n);
	res += ft_putstr("0x", 2);
	if (flag.accur_f > base_len(n, 16))
	{
		if (!n)
			res += spam(flag.accur_f, '0');
		else
			res += spam(flag.accur_f - base_len(n, 16), '0');
	}
	else if (n == 0 && flag.accur_f != 0)
		res += ft_putstr("0", 1);
	if (n != 0)
		res += print_hex(n);
	if (flag.width_f < 0 || flag.minus_f)
		res += spam(flag.width_f - res, ' ');
	return (res);
}
