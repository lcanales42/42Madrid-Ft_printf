/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:37:35 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/14 17:33:44 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		procflags(t_print *argu1)
{
	if (argu1->format == NULL)
		return (-1);
	argu1->pos++;
	while (argu1->format[argu1->pos] == '-' || argu1->format[argu1->pos] == '0')
	{
		if (argu1->format[argu1->pos] == '-')
			argu1->minus = 1;
		else
			argu1->zero = 1;
		argu1->pos++;
	}
	checkwidth_prec(argu1);
	if (argu1->format[argu1->pos] == '.')
	{
		argu1->dot = 1;
		argu1->pos++;
		checkwidth_prec(argu1);
	}
	return (0);
}
