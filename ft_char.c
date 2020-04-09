/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:45:32 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 19:41:36 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_print *argu1)
{
	char	*car;
	int		i;

	car = ft_calloc(2, sizeof(char));
	car[0] = va_arg(argu1->argu, int);
	ft_print_width(argu1, car);
	i = argu1->width > 1 ? argu1->width : 1;
	if (argu1->minus == 0)
		argu1->strimp[i - 1] = car[0];
	else
		argu1->strimp[0] = car[0];
	write(1, argu1->strimp, i);
	argu1->len += i;
	argu1->strimp[0] = 0;
	free(car);
}
