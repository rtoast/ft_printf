/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:23:01 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/01 17:10:59 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_zero(list_t *tmp, int colnum, unsigned int elem)
{
	int	i;
	int	col;

	if(tmp->precision == 0 && elem == 0)
		return(0);
	i = tmp->precision - colnum;
	col = tmp->precision - colnum;
	while (i != 0)
	{
		write(1, "0", 1);
		i--;
	}
	return (col);
}

int		ft_write_skip(list_t *tmp, int colnum, unsigned int elem)
{
	int		i;
	int		col;
	char	n;

	n = ' ';
	i = tmp->width - colnum;
	col = tmp->width - colnum;
	if (tmp->precision == 0 && elem == 0)
		i++;
	if (tmp->flag == '0' && tmp->precision == -1)
		n = '0';
	while (i != 0)
	{
		write(1, &n, 1);
		i--;
	}
	return (col);
}

int		ft_write_zeroskip(list_t *tmp, int colnum, char *str)
{
	int col;
	int rez;

	rez = 0;
	if (tmp->flag == '0' || tmp->flag == '\0')
	{
		col = tmp->width - tmp->precision;
		while (col != 0 && ((col-- && rez++) || 1))
			write(1, " ", 1);
		col = tmp->precision - colnum;
		while (col != 0 && col-- && rez++)
			write(1, "0", 1);
		return (ft_putstr_fd(str, 1) + rez);
	}
	else
	{
		col = tmp->precision - colnum;
		while (col != 0 && ((col-- && rez++) || 1))
			write(1, "0", 1);
		ft_putstr_fd(str, 1);
		col = tmp->width - tmp->precision;
		while (col != 0 && ((col-- && rez++) || 1))
			write(1, " ", 1);
	}
	return (rez + colnum);
}
