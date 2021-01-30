/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:43:19 by rtoast            #+#    #+#             */
/*   Updated: 2021/01/30 12:44:26 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parser_flag(char *text, list_t *tmp)
{
	size_t	i;
	int		minus;

	i = 0;
	minus = 0;
	if (text[i] == '0')
	{
		while (text[i] == '0' || text[i] == '-')
		{
			if (text[i++] == '-')
				minus = 1;
			tmp->length++;
		}
		tmp->flag = '0';
		if (minus == 1)
			tmp->flag = '-';
	}
	if (text[i] == '-')
	{
		while ((text[i] == '0' || text[i] == '-') && ++i)
			tmp->length++;
		tmp->flag = '-';
	}
	return (&text[i]);
}

char	*ft_parser_width(char *text, va_list *ap, list_t *tmp)
{
	size_t	i;
	int		p;

	i = 0;
	if (text[i] == '*' && ++i)
	{
		p = va_arg(*ap, int);
		if (p < 0)
		{
			p = -p;
			tmp->flag = '-';
		}
		tmp->width = p;
		tmp->length++;
	}
	else
	{
		tmp->width = ft_atoi(&text[i]);
		while (text[i] >= '0' && text[i] <= '9')
		{
			tmp->length++;
			i++;
		}
	}
	return (&text[i]);
}

char	*ft_parser_precision(char *text, va_list *ap, list_t *tmp)
{
	size_t	i;
	int		p;

	i = 0;
	if (text[i] == '.' && ++i)
		tmp->length++;
	else
		return (&text[i]);
	tmp->precision = 0;
	if (text[i] == '*')
	{
		i++;
		p = va_arg(*ap, int);
		tmp->precision = p;
		if (p < 0)
			tmp->precision = -1;
		tmp->length++;
	}
	else if (text[i] >= '0' && text[i] <= '9')
	{
		tmp->precision = ft_atoi(&text[i]);
		while ((text[i] >= '0' && text[i] <= '9') && ++i)
			tmp->length++;
	}
	return (&text[i]);
}

char	*ft_parser_type(char *text, list_t *tmp)
{
	char	*rez;
	char	*symbols;
	size_t	i;

	if ((symbols = ft_strdup("diucspxX%")) == NULL)
		return (NULL);
	i = 0;
	if ((rez = ft_strchr(symbols, (int)text[i])) == NULL)
	{
		free(symbols);
		return (&text[i]);
	}
	else
	{
		tmp->length++;
		tmp->type = *rez;
	}
	free(symbols);
	return (&text[++i]);
}

int		ft_parser(char *text, va_list *ap, list_t *tmp)
{
	tmp->flag = '\0';
	tmp->width = 0;
	tmp->precision = -1;
	tmp->type = '\0';
	tmp->length = 1;
	text = ft_parser_flag(text, tmp);
	text = ft_parser_width(text, ap, tmp);
	text = ft_parser_precision(text, ap, tmp);
	text = ft_parser_type(text, tmp);
	if (tmp->type == '\0')
		return (0);
	return (1);
}
