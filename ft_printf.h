/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:51:12 by rtoast            #+#    #+#             */
/*   Updated: 2021/01/30 12:34:42 by rtoast           ###   ########.fr       */
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
int		ft_write_zero(list_t *tmp, int colnum);
char	*ft_itoa(long long n);
int		ft_putstr_fd(char *s, int fd);
int		ft_write_skip(list_t *tmp, int colnum);
int		ft_write_zeroskip(list_t *tmp, int colnum, char *str);

#endif
