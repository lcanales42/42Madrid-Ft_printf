/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pre_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:26:24 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/14 16:40:08 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_pre_ptr(t_print *argu1, char *num_cad)
{
	char	*num_aux;
	char	*num_pre;
	int		i;

	i = ft_strlen(num_cad);
	if (argu1->dot == 1)
	{
		argu1->zero = 0;
		if (!(num_aux = malloc(sizeof(char) * (argu1->precision - (i + 1)))))
			return (0);
		ft_memset(num_aux, '0', ((argu1->precision + 2) - i));
		num_aux[argu1->precision - i] = 0;
		num_pre = ft_strjoin(num_aux, num_cad);
		free(num_aux);
		num_aux = ft_strjoin("0x", num_pre);
		free(num_pre);
		return (num_aux);
	}
	num_aux = ft_strjoin("0x", num_cad);
	return (num_aux);
}
