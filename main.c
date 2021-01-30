/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:57:17 by rtoast            #+#    #+#             */
/*   Updated: 2021/01/30 12:05:38 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int main()
{
	int i, j;
	i = printf("|%-6.4u%012cfkldlkfd%0-1.u%10%|\n", 111, 'k', 7878);
	j = ft_printf("|%-6.4u%012cfkldlkfd%0-1.u%10%|\n", 111, 'k', 7878);
	
	printf("p = %d\nftp = %d", i, j);
	return (0);
}