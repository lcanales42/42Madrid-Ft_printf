/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:11:17 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 20:58:10 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print argu1;

	va_start(argu1.argu, format);
	argu1.pos = 0;
	argu1.format = format;
	argu1.len = 0;
	while (format[argu1.pos])
	{
		if (format[argu1.pos] != '%')
		{
			ft_putchar(format[argu1.pos]);
			argu1.len++;
		}
		else
		{
			restart(&argu1);
			procflags(&argu1);
			procparam(&argu1);
			ft_printstr(&argu1);
		}
		if (format[argu1.pos] != '\0')
			argu1.pos++;
	}
	return (argu1.len);
}
