/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:23:01 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/06 22:18:30 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_col_width(list_t *tmp, int colnum, long long elem)
{
	int res;

	res = tmp->width;
	if (elem < 0)
		res--;
	if (tmp->precision > colnum)
		res -= tmp->precision;
	else
		res -= colnum;
	if (res < 0)
		return (0);
	return (res);
}

int		ft_col_precision(list_t *tmp, int colnum, long long elem)
{
	int res;

	res = tmp->precision;
	if (res == -1)
		return (0);
	res -= colnum;
	if (res < 0)
		return (0);
	return (res);
}

void	ft_putchar(char n, int i)
{
	while (i > 0)
	{
		write(1, &n, 1);
		i--;
	}
}

int		ft_nado(int width)
{
	if (width > 0)
		width++;
	ft_putchar(' ', width);
	return (width);
}
