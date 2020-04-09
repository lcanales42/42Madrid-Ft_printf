#include "ft_printf.h"

int	main()
{
    char c;
	int i;

	i = 18;
	c = 'a';
	ft_printf("%-7s\n", "hola");
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
	getchar(); //Estos es para ver los leaks.
	return (0);
}