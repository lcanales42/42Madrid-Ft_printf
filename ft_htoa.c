/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:33:24 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/12 21:37:23 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_htoa(unsigned int n, char option)
{
	int			i;
	char		*p;
	long int	num;
	long int	num2;

	i = 2;
	num = n;
	num2 = num;
	while (num /= 16)
		i++;
	if (!(p = malloc((i) * sizeof(char))))
		return (0);
	p[--i] = '\0';
	while (i-- > 0)
	{
		num = num2 % 16;
		if (num < 10)
			p[i] = '0' + num;
		else
			p[i] = option == 'x' ? 'a' + num - 10 : 'A' + num - 10;
		num2 /= 16;
	}
	return (p);
}
