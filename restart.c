/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:42:35 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 21:43:02 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	restart(t_print *argu1)
{
	argu1->minus = 0;
	argu1->zero = 0;
	argu1->dot = 0;
	argu1->precision = 0;
	argu1->width = 0;
	argu1->strimp = 0;
	argu1->neg = 0;
}
