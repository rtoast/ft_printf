/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:54:09 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/01 17:28:23 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_colnum(long long elem)
{
	long long		i;

	i = 0;
	if (elem == 0)
		return (1);
	while (elem > 0)
	{
		elem = elem / 10;
		i++;
	}
	return (i);
}

int		ft_type_c_pro(list_t *tmp, va_list *ap)
{
	char	elem;
	int		width;
	char	n;

	if (tmp->width == 0)
		width = 1;
	else
		width = tmp->width;
	if (tmp->type == '%')
		elem = '%';
	else
		elem = va_arg(*ap, int);
	n = ' ';
	if (tmp->flag == '0')
		n = '0';
	if (tmp->flag == '-')
		write(1, &elem, 1);
	while (tmp->width-- > 1)
		write(1, &n, 1);
	if (tmp->flag != '-')
		write(1, &elem, 1);
	return (width);
}

int		ft_type_u(list_t *tmp, va_list *ap)
{
	unsigned int	elem;
	char			*str;
	int				colnum;
	int				col;

	elem = va_arg(*ap, unsigned int);
	colnum = ft_colnum(elem);
	str = ft_itoa(elem);
	if (elem == 0 && tmp->precision == 0 && tmp->width == 0)
		return (tmp->width);
	if ((colnum >= tmp->precision && colnum >= tmp->width) ||
		(tmp->precision == -1 && tmp->width == 0))
		return (ft_putstr_fd(str, 1));
	if (tmp->precision >= tmp->width)
		col = ft_write_zero(tmp, colnum, elem);
	if (tmp->width > tmp->precision && tmp->precision <= colnum)
	{
		if (tmp->flag != '-')
			col = ft_write_skip(tmp, colnum, elem);
		if (!(tmp->precision == 0 && elem == 0))
			ft_putstr_fd(str, 1);
		if (tmp->flag == '-')
			col = ft_write_skip(tmp, colnum, elem);
		return (colnum + col);
	}
	if (tmp->width > tmp->precision && tmp->precision > colnum)
		return (ft_write_zeroskip(tmp, colnum, str));
	return (ft_putstr_fd(str, 1) + col);
}



int		ft_processor(list_t *tmp, va_list *ap)
{
	int		i;

	i = 0;
	if (tmp->flag == '0' && tmp->precision != -1)
		tmp->flag = '\0';
//	if (tmp->type == 'i' || tmp-> 'd')
	//	i = ft_type_id(list_t *tmp, va_list *ap);
	if (tmp->type == 'u')
		i = ft_type_u(tmp, ap);
	if (tmp->type == 'c' || tmp->type == '%')
		i = ft_type_c_pro(tmp, ap);
	//if (tmp->type == 's')
	//	ft_type_s(list_t *tmp, va_list *ap);
	//if (tmp->type == 'p')
		//ft_type_p(list_t *tmp, va_list *ap);
	//if (tmp->type == 'x' || tmp->type == 'X')
	//	ft_type_xX(list_t *tmp, va_list *ap);
	return(i);
}
