/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:37:12 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/17 19:43:51 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF2_H
# define FT_PRINTF2_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

typedef	struct	s_print
{
	const char	*format;
	int			minus;
	int			zero;
	int			dot;
	int			precision;
	int			width;
	int			pos;
	int			neg;
	char		*strimp;
	int			len;
	va_list		argu;

}				t_print;

void			checkwidth_prec(t_print *argu1);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			ft_char(t_print *argu1);
void			ft_hex(t_print *argu1, char option);
char			*ft_htoa(unsigned int n, char option);
int				ft_isdigit(int c);
char			*ft_itoa(int n, t_print *argu1);
void			*ft_memset(void *b, int c, size_t len);
void			ft_numb(t_print *argu1);
char			*ft_print_pre_ptr(t_print *argu1, char *num_cad);
char			*ft_print_pre_str(t_print *argu1, char *str);
char			*ft_print_pre(t_print *argu1, char *num_cad);
int				ft_print_ptg(t_print *argu1);
int				ft_print_width(t_print *argu1, char *n_p);
int				ft_printf(const char *format, ...);
void			ft_printstr(t_print *argu1);
void			ft_ptrhex(t_print *argu1);
void			ft_printstr(t_print *argu1);
char			*ft_ptrtoa(unsigned long long n);
void			ft_putchar(char c);
int				ft_str(t_print *argu1);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2);
int				ft_strlen(const char *str);
char			*ft_substr(const char *s, unsigned int start, size_t len);
void			ft_unumb(t_print *argu1);
char			*ft_utoa(unsigned int n);
int				procflags(t_print *argu1);
int				procparam(t_print *argu1);
void			restart(t_print *argu1);

#endif
