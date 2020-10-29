/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:04:53 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:27:33 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		output_str(va_list *args, t_flag flag)
{
	char	*str;
	char	c;
	int		res;

	str = va_arg(*args, char*);
	str = !str ? "(null)" : str;
	res = 0;
	if (flag.minus_f || flag.width_f < 0)
	{
		res += ft_putstr(str, flag.accur_f);
		res += spam(smash(ft_abs(flag.width_f) - res), ' ');
	}
	else
	{
		c = flag.zero_f ? '0' : ' ';
		if (flag.accur_f < 0)
			res += spam(smash(flag.width_f - ft_strlen(str)), c);
		else
			res += spam(smash(flag.width_f - min(ft_strlen(str), \
			flag.accur_f)), c);
		res += ft_putstr(str, flag.accur_f);
	}
	return (res);
}
