/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:14:57 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/17 20:00:53 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(t_print *argu1)
{
	char	*str;
	char	*str_aux;
	char	*str_pre;

	str_aux = va_arg(argu1->argu, char *);
	if (str_aux == 0)
		str_aux = ft_strdup("(null)");
	if (!(str = malloc(ft_strlen(str_aux) + 1 * sizeof(char))))
		return (0);
	ft_strcpy(str, str_aux);
	str_pre = ft_print_pre_str(argu1, str);
	ft_print_width(argu1, str_pre);
	free(str);
	free(str_pre);
	return (0);
}
