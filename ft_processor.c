/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:54:09 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/09 00:50:51 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_colnum(long long elem)
{
	long long		i;

	i = 0;
	if (elem < 0)
		elem *= -1;
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
	int				colnum;
	int				width;
	int				precision;
	char			n;

	elem = va_arg(*ap, unsigned int);
	colnum = ft_colnum(elem);
	width = ft_col_width(tmp, colnum, elem);
	precision = ft_col_precision(tmp, colnum, elem);
	if (elem == 0 && tmp->precision == 0)
		return (ft_nado(width));
	if (tmp->flag == '0')
		n = '0';
	else
		n = ' ';
	if (tmp->flag != '-')
		ft_putchar(n, width);
	ft_putchar('0', precision);
	ft_putnbr_fd(elem, 1);
	if (tmp->flag == '-')
		ft_putchar(' ', width);
	if (elem < 0)
		return (width + precision + colnum + 1);
	return (width + precision + colnum);
}

int		ft_type_id(list_t *tmp, va_list *ap)
{
	int		elem;
	int		width;
	int		precision;
	char	n;

	elem = va_arg(*ap, int);
	n = ' ';
	width = ft_col_width(tmp, (ft_colnum(elem)), elem);
	precision = ft_col_precision(tmp, (ft_colnum(elem)), elem);
	if (elem == 0 && tmp->precision == 0)
		return (ft_nado(width));
	if (tmp->flag == '0')
		n = '0';
	if (elem < 0 && tmp->flag == '0')
		ft_putchar('-', 1);
	if (tmp->flag != '-')
		ft_putchar(n, width);
	if (elem < 0 && tmp->flag != '0')
		ft_putchar('-', 1);
	ft_putchar('0', precision);
	ft_putnbr_fd(elem, 1);
	if (tmp->flag == '-')
		ft_putchar(' ', width);
	return (width + precision + (ft_colnum(elem)) + (elem < 0));
}

int		ft_processor(list_t *tmp, va_list *ap)
{
	int		i;

	i = 0;
	if (tmp->flag == '0' && tmp->precision != -1)
		tmp->flag = '\0';
	if (tmp->type == 'i' || tmp->type == 'd')
		i = ft_type_id(tmp, ap);
	if (tmp->type == 'u')
		i = ft_type_u(tmp, ap);
	if (tmp->type == 'c' || tmp->type == '%')
		i = ft_type_c_pro(tmp, ap);
	if (tmp->type == 's')
		i = ft_type_s(tmp, ap);
	//if (tmp->type == 'p')
		//ft_type_p(list_t *tmp, va_list *ap);
	if (tmp->type == 'x' || tmp->type == 'X')
		i = ft_type_xX(tmp, ap);
	return(i);
}
