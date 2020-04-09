/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:11:17 by lcanales          #+#    #+#             */
/*   Updated: 2020/02/17 20:11:49 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf2.h"

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

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	rt;
	unsigned int	rt1;
	char			*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char))))
		return (0);
	rt = 0;
	rt1 = 0;
	while (s1[rt] != 0)
	{
		str[rt] = s1[rt];
		rt++;
	}
	while (s2[rt1] != 0)
	{
		str[rt] = s2[rt1];
		rt++;
		rt1++;
	}
	str[rt] = '\0';
	return (str);
}

int	ft_strlen(const char *str)
{
	int	rt;

	rt = 0;
	while (str[rt])
		rt++;
	return (rt);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	rt;
	char			*str;

	rt = ft_strlen(s1);
	if (!(str = malloc(sizeof(char) * rt + 1)))
		return (0);
	rt = 0;
	while (s1[rt] != 0)
	{
		str[rt] = s1[rt];
		rt++;
	}
	str[rt] = 0;
	return (str);
}

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

int	ft_print_ptg(t_print *argu1)
{
	if (argu1->width > 1)
	{
		if (!(argu1->strimp = malloc((argu1->width + 1) * sizeof(char))))
			return(0);
		ft_memset(argu1->strimp, ' ' , argu1->width);
		if (argu1->minus == 0)
		{
			if (argu1->zero == 1)
				ft_memset(argu1->strimp, '0' , argu1->width);
			argu1->strimp[argu1->width -1] = '%';
		}
		else
			argu1->strimp[0] = '%';
		argu1->strimp[argu1->width] = '\0';
	}
	else
		argu1->strimp = ft_strdup("%");
	return(1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	sign;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = str[i] - 48 + 10 * ret;
		i++;
	}
	return (ret * sign);
}

int	ft_isdigit(int c)
{
	if ((c < '0' || c > '9'))
		return (0);
	return (1);
}

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

char			*ft_itoa(int n, t_print *argu1)
{
	int				i;
	char			*p;
	int				cont;
	long int		num;
	long int		num2;

	i = 1;
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

char			*ft_htoa(unsigned int n, char option)
{
	int				i;
	char			*p;
	long int		num;
	long int		num2;

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

char			*ft_ptrtoa(unsigned long long n)
{
	int				i;
	char			*p;
	unsigned long long 	num;
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

char	*ft_strcpy(char *dest, char *src)
{
	int rt;

	rt = 0;
	while (*(src + rt) != '\0')
	{
		*(dest + rt) = *(src + rt);
		rt++;
	}
	*(dest + rt) = '\0';
	return (dest);
}

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
/*int ft_print_width(t_print *argu1, char *num_pre)
{
	char	*cad_aux;

	if (argu1->width > (int)ft_strlen(num_pre))
	{
		if (!(cad_aux = malloc(sizeof(char) * (argu1->width - ft_strlen(num_pre)) + 1)))
			return(0);
		ft_memset(cad_aux, ' ' , (argu1->width - ft_strlen(num_pre)));
		cad_aux[argu1->width - ft_strlen(num_pre)] = 0;
		if (argu1->minus == 0)
		{
				if(argu1->zero == 1)
				{
					ft_memset(cad_aux, '0' , (argu1->width - ft_strlen(num_pre)));
					cad_aux[0] = argu1->neg == 1 ? '-' : cad_aux[0];
					cad_aux[argu1->width - ft_strlen(num_pre)] = 0;

				}
				else
					cad_aux[argu1->width - (ft_strlen(num_pre) + 1)] = argu1->neg == 1 ? '-' : cad_aux[0];
				argu1->strimp = ft_strjoin(cad_aux, num_pre);
		}
		else
			if (argu1->neg == 1)
			{
				num_pre = ft_strjoin("-", num_pre);
				cad_aux[argu1->width - ft_strlen(num_pre)] = 0;
			}
			argu1->strimp = ft_strjoin(num_pre, cad_aux);
		free (cad_aux);
	}
	else
		argu1->strimp = argu1->neg == 1 ? ft_strjoin("-", num_pre) : ft_strdup(num_pre);
	return(0);
}*/

char	*ft_print_pre(t_print *argu1, char *num_cad)
{
	char *num_aux;
	char *num_pre;

	argu1->zero = argu1->dot == 1 ? 0 : argu1->zero;
	if (argu1->precision == 0 && argu1->dot == 1 && num_cad[0] == '0')
		return (ft_strdup(""));
	if (argu1->dot == 1 && argu1->precision > ft_strlen((num_cad)))
	{
		if (!(num_aux = malloc(sizeof(char) * (((argu1->precision) - (ft_strlen(num_cad)) + 1)))))
            return(0);
        ft_memset(num_aux, '0', (argu1->precision - (ft_strlen(num_cad))));
        num_aux[argu1->precision - (ft_strlen(num_cad))] = 0;
		num_pre = ft_strjoin(num_aux, num_cad);
		free (num_aux);
		if (argu1->neg == 1)
		{
			num_aux = ft_strjoin("-", num_pre);
			argu1->neg = 0;
			free (num_pre);
			return (num_aux);
		}
		return (num_pre);
	}
	return (ft_strdup(num_cad));
}

char	*ft_print_pre_str(t_print *argu1, char *str)
{
	char *str_aux;

	if (argu1->dot == 1 && argu1->precision < ft_strlen(str))
		return(str_aux = ft_substr(str, 0, argu1->precision));
    else
	{
		if (!(str_aux = malloc((ft_strlen(str) + 1) * sizeof(char))))
			return (0);
		ft_strcpy(str_aux, str);
	}
	return (str_aux);
}

char	*ft_print_pre_ptr(t_print *argu1, char *num_cad)
{
	char *num_aux;
	char *num_pre;

	if (argu1->dot == 1)
	{
		argu1->zero = 0;
		if (!(num_aux = malloc(sizeof(char) * ((argu1->precision) - (ft_strlen(num_cad) + 1)))))
            return(0);
        ft_memset(num_aux, '0', ((argu1->precision + 2)  - (ft_strlen(num_cad))));
        num_aux[argu1->precision -(ft_strlen(num_cad))] = 0;
		num_pre = ft_strjoin(num_aux, num_cad);
		free (num_aux);
		num_aux = ft_strjoin("0x", num_pre);
		free (num_pre);
		return (num_aux);
	}
	num_aux = ft_strjoin("0x", num_cad);
	return (num_aux);
}

void ft_numb(t_print *argu1)
{
	int		num;
	char	*num_cad;
	char	*num_pre;

	num = va_arg(argu1->argu, int);
    num_cad = ft_itoa(num, argu1);
	num_pre = ft_print_pre(argu1, num_cad);
	ft_print_width(argu1, num_pre);
	free (num_cad);
	free (num_pre);

}

void	ft_unumb(t_print *argu1)
{
	unsigned int    u_num;
	char			*num_cad;
	char			*num_pre;

	u_num = va_arg(argu1->argu, unsigned int);
    num_cad = ft_utoa(u_num);
	num_pre = ft_print_pre(argu1, num_cad);
	ft_print_width(argu1, num_pre);
	free (num_cad);
	free (num_pre);
}

void	ft_hex(t_print *argu1, char option)
{
	unsigned int    u_num;
	char			*num_cad;
	char			*num_pre;

	u_num = va_arg(argu1->argu, unsigned int);
	num_cad = ft_htoa(u_num, option);
	num_pre = ft_print_pre(argu1, num_cad);
	ft_print_width(argu1, num_pre);
	free (num_cad);
	free (num_pre);
}

void	ft_ptrhex(t_print *argu1)
{
	unsigned long long	u_num;
	char				*num_cad;
	char				*num_pre;

	u_num = va_arg(argu1->argu, unsigned long long);
	num_cad = ft_ptrtoa(u_num);
	if (argu1->dot == 0 && argu1->zero == 1 && argu1-> minus == 0 && argu1->width > 14 )
	{
		argu1->precision = argu1->width - 2;
		argu1->dot = 1;
	}
	num_pre = ft_print_pre_ptr(argu1, num_cad);
	if (num_pre == 0)
		num_pre = ft_strdup("0x");
	ft_print_width(argu1, num_pre);
	free (num_pre);
	free (num_cad);
}
void	ft_char(t_print *argu1)
{
	char	*car;
	int		i;

	car = ft_calloc(2, sizeof(char));
	car[0] = va_arg(argu1->argu, int);
	ft_print_width(argu1, car);
	i = argu1->width > 1 ? argu1->width : 1;
	if (argu1->minus == 0)
		argu1->strimp[i] = car[0];
	else
		argu1->strimp[0] = car[0];
	write(1, argu1->strimp, i);
	argu1->len += i;
	argu1->strimp[0] = 0;
	free (car);
}

int	ft_str(t_print *argu1)
{
	char	*str;
	char	*str_aux;
	char	*str_pre;

	str_aux = va_arg(argu1->argu, char *);
	if (str_aux == 0)
		str_aux = ft_strdup("(null)");
	if (!(str = malloc(ft_strlen(str_aux) + 1 * sizeof(char))))
		return(0);
	ft_strcpy(str, str_aux);
	str_pre = ft_print_pre_str(argu1, str);
	ft_print_width(argu1, str_pre);
	if (str_aux == NULL)
		free (str_aux);
	free (str);
	free (str_pre);
	return(0);
}

void	restart(t_print *argu1)
{
	argu1->minus = 0;
	argu1->zero = 0;
	argu1->dot = 0;
	argu1->precision = 0;
	argu1->width = 0;
	argu1->strimp = 0;
	argu1->neg = 0;
}

void	checkwidth_prec(t_print *argu1)
{
	int aux;

	aux = 0;
	if (ft_isdigit(argu1->format[argu1->pos]))
	{
		aux = ft_atoi(argu1->format + argu1->pos);
		while (ft_isdigit(argu1->format[argu1->pos]))
			argu1->pos++;
	}
	else if (argu1->format[argu1->pos] == '*')
	{
		aux = va_arg(argu1->argu, int);
		argu1->pos++;
	}
	if (argu1->dot == 1)
		argu1->precision = aux;
	else
	{
		if (aux < 0)
		{
			aux *= -1;
			argu1->zero = 0;
			argu1->minus = 1;
		}
		argu1->width = aux;
	}
}

int		procflags(t_print *argu1) // Format de I apunta a al %
{
    if (argu1->format == NULL)
        return (-1);
	argu1->pos++;
	while (argu1->format[argu1->pos] == '-' || argu1->format[argu1->pos] == '0')
	{
		if (argu1->format[argu1->pos] == '-' )
			argu1->minus = 1;
		else
			argu1->zero = 1;
		argu1->pos++;
	}
	checkwidth_prec(argu1);
	if (argu1->format[argu1->pos] == '.')
	{
		argu1->dot = 1;
		argu1->pos++;
		checkwidth_prec(argu1);
	}
	return(0);
}

int		procparam(t_print *argu1) // Format de I apunta a al %
{
	if (argu1->format == NULL)  //|| argu1->strimp == NULL)
		return(0);
	if (argu1->format[argu1->pos] == '%')
		ft_print_ptg(argu1);
	else if(argu1->format[argu1->pos] == 'd' || argu1->format[argu1->pos] == 'i' )
		ft_numb(argu1);
	else if(argu1->format[argu1->pos] == 'u')
		ft_unumb(argu1);
	else if(argu1->format[argu1->pos] == 'c')
		ft_char(argu1);
	else if(argu1->format[argu1->pos] == 's')
		ft_str(argu1);
	else if(argu1->format[argu1->pos] == 'p')
		ft_ptrhex(argu1);
	else if(argu1->format[argu1->pos] == 'x' || argu1->format[argu1->pos] == 'X' )
		ft_hex(argu1, argu1->format[argu1->pos]);
	else
		argu1->strimp = ft_strdup("");
	return (0);
}

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void 	ft_printstr(t_print *argu1)
{
    int i;

	i = 0;
	while(argu1->strimp[i])
	{
		ft_putchar(argu1->strimp[i]);
		i++;
		argu1->len++;
	}
	free(argu1->strimp);
}

int		ft_printf(const char *format, ...)
{
    t_print argu1;
	//argu1 = malloc(sizeof(t_print));
	va_start(argu1.argu, format);
    argu1.pos = 0;
	argu1.format = format;
	argu1.len = 0;
	while (format[argu1.pos] != '\0')
    {
		//restart(&argu1);
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
			//if (procparam == 0)
			ft_printstr(&argu1);
		}
		if (format[argu1.pos] != '\0')
			argu1.pos++;
	}
	return (argu1.len);
}

int	main()
{
    /*char c;
	int i;

	i = 18;
	c = 'a';*/
	ft_printf("%#x", 42);
	printf("%#x", 42);
	ft_printf("%.  %\n", "test");
	printf("%.  %\n", "test");
	/*ft_printf("%-7s\n", "hola");
	ft_printf("%i\n", 234);
	ft_printf("hola que tal %25s hola\n", "hola que tal");
	//printf("%.p\n", NULL);
	ft_printf("%.p", NULL);
	//printf ("%i",j);
	//int y = ft_printf("%c", '\0');
	//printf ("%i", y);
	//printf("s %*s s\n", -32, "abc");
	ft_printf("s %*s s\n", -32, "abc");
	//printf("%0*i s\n", -14, 98745);
	ft_printf("%0*i s\n", -14, 98745);
	//printf("%-5");
	ft_printf("%-5");
	ft_printf("%013p %050.32p\n", &i, &c);
	//printf("%013p %050.32p\n", &i, &c);
	ft_printf("hola que tal %25.s hola\n",  "hola que tal");
	//printf("hola que tal %25.s hola\n",  "hola que tal");
	ft_printf("%-6c %08c %4.6c\n", c, c, c);
	//printf("%-6c %08c %4.6c\n", c, c, c);
	ft_printf("%.5x %*.7X\n", 2558, 9, 2558);
	//printf("%.5x %*.7X\n", 2558, 9, 2558);
	ft_printf("%.4d %-5.8u %-8.25d %015.12i\n", 3, 17, 456, 1);
	//printf("%.4d %-5.8u %-8.25d %015.12i\n", 3, 17, 456, 1);
	//printf("%lli\n", (long long int)&i);
	ft_printf("hola que tal %s %d %i %u %c %s %X %p %p\n",  "hola que tal", -17, 852197, -25554, 0, "hola que tal", -10543, &i, &c);
	//printf("hola que tal %% %d %i %u %c %s %x %p %p\n", -17, 852197, -25554, 0, "hola que tal", -10543, &i, &c);
	//printf("hola que tal %% %d %i %u %c %s %X %p %p\n", -17, 852197, -25554, c, "hola que tal", -10543, &i, &c);*/
	//getchar(); //Estos es para ver los leaks.
	//Make CFLAGS=-Wall -Wextra -Werror -O3
	return (0);
}
