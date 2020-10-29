/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 12:57:04 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:01:03 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *f, ...)
{
	va_list	args;
	int		c;

	c = 0;
	va_start(args, f);
	c += ft_assemble(f, 0, &args);
	va_end(args);
	return (c);
}
