/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:43:27 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/14 16:44:55 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_pre(t_print *argu1, char *num_cad, int i)
{
	char	*num_aux;
	char	*num_pre;

	argu1->zero = argu1->dot == 1 ? 0 : argu1->zero;
	if (argu1->precision == 0 && argu1->dot == 1 && num_cad[0] == '0')
		return (ft_strdup(""));
	if (argu1->dot == 1 && argu1->precision > i)
	{
		if (!(num_aux = malloc(sizeof(char) * (argu1->precision - i + 1))))
			return (0);
		ft_memset(num_aux, '0', (argu1->precision - i));
		num_aux[argu1->precision - i] = 0;
		num_pre = ft_strjoin(num_aux, num_cad);
		free(num_aux);
		if (argu1->neg == 1)
		{
			num_aux = ft_strjoin("-", num_pre);
			argu1->neg = 0;
			free(num_pre);
			return (num_aux);
		}
		return (num_pre);
	}
	return (ft_strdup(num_cad));
}
