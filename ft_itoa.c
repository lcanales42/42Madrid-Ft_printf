/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:40:25 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/14 17:01:11 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		negative(long int *n)
{
	int cont;

	cont = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		cont += 1;
	}
	return (cont);
}

char			*ft_itoa(int n, t_print *argu1, int i, int cont)
{
	char			*p;
	long int		num;
	long int		num2;

	num = n;
	cont = negative(&num);
	num2 = num;
	if (n == 0)
		return (ft_strdup("0"));
	while (num)
	{
		num /= 10;
		i++;
	}
	if (!(p = malloc((i) * sizeof(char))))
		return (0);
	p[--i] = '\0';
	while (i-- > 0)
	{
		p[i] = num2 % 10 + '0';
		num2 = num2 / 10;
	}
	if (cont > 0)
		argu1->neg = 1;
	return (p);
}
