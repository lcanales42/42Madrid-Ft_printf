/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:02:07 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 21:04:37 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptrhex(t_print *argu1)
{
	unsigned long long	u_num;
	char				*num_cad;
	char				*num_pre;

	u_num = va_arg(argu1->argu, unsigned long long);
	num_cad = ft_ptrtoa(u_num);
	if (argu1->dot == 0 && argu1->zero == 1 && argu1->minus == 0
		&& argu1->width > 14)
	{
		argu1->precision = argu1->width - 2;
		argu1->dot = 1;
	}
	num_pre = ft_print_pre_ptr(argu1, num_cad);
	if (num_pre == 0)
		num_pre = ft_strdup("0x");
	ft_print_width(argu1, num_pre);
	free(num_pre);
	free(num_cad);
}
