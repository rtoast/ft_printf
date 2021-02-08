/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_2.0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:36:09 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/09 01:43:56 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		ft_putstr_fd(char *s, int fd, int colstr, list_t *tmp)
{
	size_t	i;

	i = 0;
	if (tmp->precision == 0)
		return (0);
	if (s != NULL)
	{
		while (i < colstr)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int		ft_type_s(list_t *tmp, va_list *ap)
{
	char	*elem;
	int		width;
	int		colnum;
	int		colstr;
	int		flag;

	elem = va_arg(*ap, char *);
	flag = 0;
	if (elem == NULL && ++flag)
		elem = ft_strdup("(null)");
	colnum = ft_strlen(elem);
	width = ft_width_s(tmp, colnum);
	colstr = colnum;
	if (tmp->precision < colnum && tmp->precision > -1)
		colstr = tmp->precision;
	if (tmp->flag == '0' || tmp->flag == '\0')
		ft_putchar(' ', width);
	colnum = ft_putstr_fd(elem, 1, colstr, tmp);
	if (tmp->flag == '-')
		ft_putchar(' ', width);
	if (flag == 1)
		free(elem);
	return (colstr + width);
}

char	ft_perevod(int ost, char x)
{
	char	n;
	int		i;

	i = 0;
	n = ost + '0';
	if (x == 'X' && ost >= 10)
		i = 32;
	if (ost == 10)
		n = 'a' - i;
	if (ost == 11)
		n = 'b' - i;
	if (ost == 12)
		n = 'c' - i;
	if (ost == 13)
		n = 'd' - i;
	if (ost == 14)
		n = 'e' - i;
	if (ost == 15)
		n = 'f' - i;
	return (n);
}

void	ft_int_16(unsigned int elem, char x)
{
	int		ost;
	char	n;
	int		i;

	i = 0;
	ost = 0;
	while (elem > 0)
	{
		ost = elem % 16;
		elem = elem / 16;
		n = ft_perevod(ost, x);
		ft_int_16(elem, x);
		write (1, &n, 1);
		return ;
	}
}

int		ft_colnum_16(unsigned int elem)
{
	int i;

	i = 0;
	if (elem == 0)
		return (1);
	while (elem > 0)
	{
		elem = elem / 16;
		i++;
	}
	return (i);
}

int		ft_type_xX(list_t *tmp, va_list *ap)
{
	unsigned int	elem;
	int				colnum;
	int				width;
	int				precision;
	char			n;

	elem = va_arg(*ap, unsigned int);
	colnum = ft_colnum_16(elem);
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
	if (elem == 0)
		write (1, "0", 1);
	ft_int_16(elem, tmp->type);
	if (tmp->flag == '-')
		ft_putchar(' ', width);
	if (elem < 0)
		return (width + precision + colnum + 1);
	return (width + precision + colnum);
}
