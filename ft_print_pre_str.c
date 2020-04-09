/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pre_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:23:54 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/14 16:38:43 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_pre_str(t_print *argu1, char *str)
{
	char	*str_aux;
	int		i;

	i = ft_strlen(str);
	if (argu1->dot == 1 && argu1->precision < i)
		return (str_aux = ft_substr(str, 0, argu1->precision));
	else
	{
		if (!(str_aux = malloc((i + 1) * sizeof(char))))
			return (0);
		ft_strcpy(str_aux, str);
	}
	return (str_aux);
}
