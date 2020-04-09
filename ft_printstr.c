/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:59:50 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 21:01:19 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(t_print *argu1)
{
	int i;

	i = 0;
	while (argu1->strimp[i])
	{
		ft_putchar(argu1->strimp[i]);
		i++;
		argu1->len++;
	}
	free(argu1->strimp);
}
