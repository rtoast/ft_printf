/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:23:01 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/09 16:10:49 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		ft_col_width(list_t *tmp, int colnum, long long elem)
{
	int res;

	res = tmp->width;
	if (tmp->type == 'p')
		res = res - 2;
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

int		ft_width_s(list_t *tmp, int colnum)
{
	int	size;

	if (tmp->precision == 0)
		return (tmp->width);
	if (tmp->precision > colnum || tmp->precision == -1)
		size = tmp->width - colnum;
	else 
		size = tmp->width - tmp->precision;
	if (size < 0)
		return (0);
	return (size);
}
