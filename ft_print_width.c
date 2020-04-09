/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:58:13 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/17 19:41:40 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_zero(t_print *argu1, int i, char *cad_aux, char *num_pre)
{
	if (argu1->zero == 1)
	{
		ft_memset(cad_aux, '0', (argu1->width - i));
		cad_aux[0] = argu1->neg == 1 ? '-' : cad_aux[0];
		cad_aux[argu1->width - i] = 0;
	}
	else
		cad_aux[argu1->width - (i + 1)] = argu1->neg == 1 ? '-' : cad_aux[0];
	argu1->strimp = ft_strjoin(cad_aux, num_pre);
}

static void	ft_negative(t_print *argu1, char *num_pre, char *cad_aux)
{
	if (argu1->neg == 1)
	{
		num_pre = ft_strjoin("-", num_pre);
		cad_aux[argu1->width - ft_strlen(num_pre)] = 0;
	}
	argu1->strimp = ft_strjoin(num_pre, cad_aux);
}

int			ft_print_width(t_print *argu1, char *n_p)
{
	char	*cad_aux;
	int		i;

	i = ft_strlen(n_p);
	if (argu1->width > i)
	{
		if (!(cad_aux = malloc(sizeof(char) * (argu1->width - i) + 1)))
			return (0);
		ft_memset(cad_aux, ' ', (argu1->width - i));
		cad_aux[argu1->width - i] = 0;
		if (argu1->minus == 0)
			ft_zero(argu1, i, cad_aux, n_p);
		else
			ft_negative(argu1, n_p, cad_aux);
		free(cad_aux);
	}
	else
		argu1->strimp = argu1->neg == 1 ? ft_strjoin("-", n_p) : ft_strdup(n_p);
	return (0);
}
