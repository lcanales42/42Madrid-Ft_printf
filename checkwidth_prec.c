/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwidth_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:19:08 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 20:46:24 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkwidth_prec(t_print *argu1)
{
	int aux;

	if (!(aux = 0) && ft_isdigit(argu1->format[argu1->pos]))
	{
		aux = ft_atoi(argu1->format + argu1->pos);
		while (ft_isdigit(argu1->format[argu1->pos]))
			argu1->pos++;
	}
	else if (argu1->format[argu1->pos] == '*')
	{
		aux = va_arg(argu1->argu, int);
		argu1->pos++;
	}
	if (argu1->dot == 1)
		argu1->precision = aux;
	else
	{
		if (aux < 0)
		{
			aux *= -1;
			argu1->zero = 0;
			argu1->minus = 1;
		}
		argu1->width = aux;
	}
}
