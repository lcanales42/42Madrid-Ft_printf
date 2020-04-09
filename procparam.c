/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procparam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:40:33 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 21:41:54 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		procparam(t_print *argu1)
{
	if (argu1->format == NULL)
		return (0);
	if (argu1->format[argu1->pos] == '%')
		ft_print_ptg(argu1);
	else if (argu1->format[argu1->pos] == 'd' ||
			argu1->format[argu1->pos] == 'i')
		ft_numb(argu1);
	else if (argu1->format[argu1->pos] == 'u')
		ft_unumb(argu1);
	else if (argu1->format[argu1->pos] == 'c')
		ft_char(argu1);
	else if (argu1->format[argu1->pos] == 's')
		ft_str(argu1);
	else if (argu1->format[argu1->pos] == 'p')
		ft_ptrhex(argu1);
	else if (argu1->format[argu1->pos] == 'x' ||
			argu1->format[argu1->pos] == 'X')
		ft_hex(argu1, argu1->format[argu1->pos]);
	else
		argu1->strimp = ft_strdup("");
	return (0);
}
