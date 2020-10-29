/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 22:22:28 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:27:01 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_nbrlen(int n, int base)
{
	int res;

	if (n == 0)
		return (1);
	res = 0;
	while (n != 0)
	{
		n /= base;
		res += 1;
	}
	return (res);
}

int		ft_unbrlen(unsigned int n, int base)
{
	int res;

	if (n == 0)
		return (1);
	res = 0;
	while (n != 0)
	{
		n /= base;
		res += 1;
	}
	return (res);
}

int		ft_pow(int n, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (n * ft_pow(n, pow - 1));
}

int		ft_itoa_base(int n, int base, char *digits)
{
	int		res;
	int		i;
	int		len;
	int		k;

	k = n < 0 ? 1 : 0;
	len = ft_nbrlen(n, base);
	res = 0;
	if (n == -2147483648)
	{
		res += ft_itoa_base(-214748364, 10, digits);
		res += ft_itoa_base(8, 10, digits);
		return (10);
	}
	if (k)
		n = -n;
	i = k;
	while (i - k < len)
	{
		res += ft_putchar(digits[n / ft_pow(base, len - i + k - 1)]);
		n = n % ft_pow(base, len - i + k - 1);
		i++;
	}
	return (i - k);
}

int		ft_uitoa_base(unsigned int n, int base, char *digits)
{
	int		res;
	int		i;
	int		len;

	len = ft_unbrlen(n, base);
	i = 0;
	res = 0;
	while (i < len)
	{
		res += ft_putchar(digits[n / ft_pow(base, len - i - 1)]);
		n = n % ft_pow(base, len - i - 1);
		i++;
	}
	return (i);
}
