/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:05:54 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:27:27 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		output_pe(va_list *args, t_flag flag)
{
	int		res;
	va_list	tmp;

	res = 0;
	va_copy(tmp, *args);
	va_end(tmp);
	if (flag.minus_f || flag.width_f < 0)
	{
		res += ft_putchar('%');
		res += spam(flag.width_f - 1, ' ');
	}
	else
	{
		if (flag.zero_f)
			res += spam(flag.width_f - 1, '0');
		else
			res += spam(flag.width_f - 1, ' ');
		res += ft_putchar('%');
	}
	return (res);
}
