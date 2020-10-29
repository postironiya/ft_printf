/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 22:43:13 by rmarguri          #+#    #+#             */
/*   Updated: 2020/07/31 23:27:39 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		smash(int n)
{
	if (n < 0)
		return (0);
	return (n);
}

int		spam(int l, char c)
{
	int i;

	i = 0;
	while (i < l)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
