/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:22:46 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 21:34:31 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_utoa(unsigned int n)
{
	int				i;
	char			*p;
	long int		num;
	long int		num2;

	i = 2;
	num = n;
	num2 = num;
	while (num /= 10)
		i++;
	if (!(p = malloc((i) * sizeof(char))))
		return (0);
	p[--i] = '\0';
	while (i-- > 0)
	{
		p[i] = num2 % 10 + '0';
		num2 = num2 / 10;
	}
	return (p);
}
