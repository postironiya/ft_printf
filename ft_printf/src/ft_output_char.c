/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:04:08 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:27:18 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		output_char(va_list *args, t_flag flag)
{
	char	c;
	int		res;

	c = va_arg(*args, int);
	res = 0;
	if (flag.minus_f || flag.width_f < 0)
	{
		res += ft_putchar(c);
		res += spam(ft_abs(flag.width_f) - 1, ' ');
	}
	else
	{
		if (flag.zero_f)
			res += spam(flag.width_f - 1, '0');
		else
			res += spam(flag.width_f - 1, ' ');
		res += ft_putchar(c);
	}
	return (res);
}
