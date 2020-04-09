/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:16:54 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/14 16:49:19 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unumb(t_print *argu1)
{
	unsigned int	u_num;
	int				i;
	char			*num_cad;
	char			*num_pre;

	u_num = va_arg(argu1->argu, unsigned int);
	num_cad = ft_utoa(u_num);
	i = ft_strlen(num_cad);
	num_pre = ft_print_pre(argu1, num_cad, i);
	ft_print_width(argu1, num_pre);
	free(num_cad);
	free(num_pre);
}
