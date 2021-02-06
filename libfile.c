/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:44:20 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/06 22:22:50 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] != c)
		return (NULL);
	return (&s[i]);
}

static int		f(char *str, int i)
{
	while (str[i] < '0' || str[i] > '9')
	{
		if ((str[i] != '-') && (str[i] != '+') && (str[i] != '\n'))
			if ((str[i] != ' ') && (str[i] != '\f'))
				if ((str[i] != '\r') && (str[i] != '\t') && (str[i] != '\v'))
					return (1);
		i++;
	}
	return (0);
}

static void		f2(char *str, int i, int *znak, int *znak_plus)
{
	while (str[i] < '0' || str[i] > '9')
		if (str[i++] == '-')
			(*znak)++;
	i = 0;
	while (str[i] < '0' || str[i] > '9')
		if (str[i++] == '+')
			(*znak_plus)++;
}

int				ft_atoi(char *str)
{
	unsigned long long	rez;
	int					i;
	int					znak;
	int					minus;
	int					znak_plus;

	minus = 1;
	i = 0;
	znak = 0;
	znak_plus = 0;
	rez = 0;
	if (f(str, i) == 1)
		return (0);
	f2(str, i, &znak, &znak_plus);
	if ((znak_plus > 1) || (znak >= 1 && znak_plus >= 1) || (znak > 1))
		return (0);
	while (str[i] < '0' || str[i] > '9')
		i++;
	if ((znak == 1) && (str[i - 1] == '-'))
		minus = -1;
	if ((znak == 1) && (str[i - 1] != '-'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		rez = rez * 10 + str[i++] - '0';
	return (rez * minus);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	n;
	size_t	i;

	i = 0;
	n = ft_strlen(s);
	str = (char *)malloc((n + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i <= n)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

void	ft_putnbr_fd(long long n, int fd)
{
	long long		ochen_ne_n;
	int				ne_n;
	char			symbol;

	ochen_ne_n = n;
	if (ochen_ne_n < 0)
		ochen_ne_n *= -1;
	while (ochen_ne_n > 9)
	{
		ne_n = ochen_ne_n % 10;
		ochen_ne_n /= 10;
		symbol = ne_n + '0';
		n = (int)ochen_ne_n;
		ft_putnbr_fd(n, fd);
		write(fd, &symbol, 1);
		return ;
	}
	symbol = ochen_ne_n + '0';
	write(fd, &symbol, 1);
}
