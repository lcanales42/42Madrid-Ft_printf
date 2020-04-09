/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:51:28 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/04 19:06:38 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	rt;

	if (s == 0)
		return (0);
	rt = ft_strlen(s);
	if (start > rt)
		return (ft_strdup(""));
	rt = rt + start;
	if (rt < len)
		len = rt;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (0);
	rt = 0;
	while (rt < len)
	{
		str[rt] = s[rt + start];
		rt++;
	}
	str[rt] = '\0';
	return (str);
}
