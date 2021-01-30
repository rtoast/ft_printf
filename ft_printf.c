/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:49:08 by rtoast            #+#    #+#             */
/*   Updated: 2021/01/30 10:08:36 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *text, ...)
{
	va_list		ap;
	size_t		i;
	list_t		tmp;
	size_t		size;

	i = 0;
	va_start(ap, text);
	size = ft_strlen(text);
	while (text[i] != '\0')
	{
		while (text[i] != '%' && text[i] != '\0')
			write(1, &text[i++], 1);
		if (text[i] == '%')
		{
			if ((ft_parser((char*)&text[++i], &ap, &tmp) == 0))
			{
				va_end(ap);
				return (-1);
			}
			size = size - tmp.length + ft_processor(&tmp, &ap);
			i += tmp.length - 1;
		}
	}
	va_end(ap);
	return (size);
}
