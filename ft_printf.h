/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:51:12 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/06 22:23:10 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include "unistd.h"
# include "stdarg.h"
# include "stdlib.h"

typedef struct	list_s
{
	char	flag;
	int		width;
	int		precision;
	char	type;
	int		length;
}				list_t;

int		ft_printf(const char *text, ...);
int		ft_parser(char *text, va_list *ap, list_t *tmp);
char	*ft_strchr(const char *str, int c);
int		ft_atoi(char *str);
char	*ft_strdup(const char *s);
int		ft_processor(list_t *tmp, va_list *ap);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(long long n, int fd);
void	ft_putchar(char n, int i);
int		ft_col_precision(list_t *tmp, int colnum, long long elem);
int		ft_col_width(list_t *tmp, int colnum, long long elem);
int		ft_nado(int width);


#endif
