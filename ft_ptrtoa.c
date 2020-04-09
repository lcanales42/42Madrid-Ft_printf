/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:06:00 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/13 21:06:33 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_ptrtoa(unsigned long long n)
{
	int					i;
	char				*p;
	unsigned long long	num;
	unsigned long long	num2;

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
			p[i] = 'a' + num - 10;
		num2 /= 16;
	}
	return (p);
}
