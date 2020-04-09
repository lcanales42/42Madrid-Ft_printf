/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:42:18 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/12 21:42:50 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	rt;
	char	*str;

	str = (char*)b;
	rt = 0;
	while (rt < len)
	{
		str[rt] = (char)c;
		rt++;
	}
	return (str);
}
