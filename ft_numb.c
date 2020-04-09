/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:43:30 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/14 17:00:41 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_numb(t_print *argu1)
{
	int		num;
	int		i;
	char	*num_cad;
	char	*num_pre;

	num = va_arg(argu1->argu, int);
	num_cad = ft_itoa(num, argu1, 1, 0);
	i = ft_strlen(num_cad);
	num_pre = ft_print_pre(argu1, num_cad, i);
	ft_print_width(argu1, num_pre);
	free(num_cad);
	free(num_pre);
}
