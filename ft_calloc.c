/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:24:39 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/12 21:25:21 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	rt;
	char	*str;

	rt = 0;
	if (!(str = malloc(count * size)))
		return (0);
	while (rt < (count * size))
	{
		str[rt] = 0;
		rt++;
	}
	return (str);
}
