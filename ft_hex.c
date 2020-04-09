/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:30:01 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/14 16:52:38 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(t_print *argu1, char option)
{
	unsigned int	u_num;
	int				i;
	char			*num_cad;
	char			*num_pre;

	u_num = va_arg(argu1->argu, unsigned int);
	num_cad = ft_htoa(u_num, option);
	i = ft_strlen(num_cad);
	num_pre = ft_print_pre(argu1, num_cad, i);
	ft_print_width(argu1, num_pre);
	free(num_cad);
	free(num_pre);
}
