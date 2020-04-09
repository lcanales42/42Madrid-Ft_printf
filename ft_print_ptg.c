/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:57:08 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/12 21:59:43 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptg(t_print *argu1)
{
	if (argu1->width > 1)
	{
		if (!(argu1->strimp = malloc((argu1->width + 1) * sizeof(char))))
			return (0);
		ft_memset(argu1->strimp, ' ', argu1->width);
		if (argu1->minus == 0)
		{
			if (argu1->zero == 1)
				ft_memset(argu1->strimp, '0', argu1->width);
			argu1->strimp[argu1->width - 1] = '%';
		}
		else
			argu1->strimp[0] = '%';
		argu1->strimp[argu1->width] = '\0';
	}
	else
		argu1->strimp = ft_strdup("%");
	return (1);
}
