/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:57:17 by rtoast            #+#    #+#             */
/*   Updated: 2021/02/09 21:53:40 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int main()
{
	int i, j;
	i = ft_printf("ZERO, flag 0, width 1, precision 0\n%01.0d|\n", 0);
	j = printf("ZERO, flag 0, width 1, precision 0\n%01.0d|\n", 0);
	printf("p = %d\nftp = %d", i, j);
	return (0);
}