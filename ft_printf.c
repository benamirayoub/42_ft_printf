#include "ft_printf.h"

int	ft_printf(const char *Message, ...)
{
	int			i;
	int			count;
	t_format	format;
	va_list		args;

	i = 0;
	count = 0;
	va_start(args, Message);
	while (Message[i])
	{
		if (Message[i] == '%')
		{
			i++;
            init_format(&format);
			if (is_flags_valid((char *)Message, i) == 0)
			{
				i = stock_format(&format, (char *)Message, i);
				count += hundelConversation(Message[i], &args, &format);
			}
			else
			{
				write(1, &Message[i], 1);
				count++;
			}
		}
		else
		{
			write(1, &Message[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
#include "ft_printf.h"
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int	main(void)
{
	printf("===== FLAGS =====\n");
	ft_printf("===== FLAGS =====\n");

	printf("printf   : [%010d]\n", 42);
	ft_printf("ft_printf: [%010d]\n", 42);

	printf("printf   : [%-10d]\n", 42);
	ft_printf("ft_printf: [%-10d]\n", 42);

	printf("printf   : [%+10d]\n", 42);
	ft_printf("ft_printf: [%+10d]\n", 42);

	printf("printf   : [% 10d]\n", 42);
	ft_printf("ft_printf: [% 10d]\n", 42);

	printf("printf   : [%#10x]\n", 255);
	ft_printf("ft_printf: [%#10x]\n", 255);

	printf("===== PRECISION =====\n");
	ft_printf("===== PRECISION =====\n");

	printf("printf   : [%.5d]\n", 42);
	ft_printf("ft_printf: [%.5d]\n", 42);

	printf("printf   : [%10.5d]\n", 42);
	ft_printf("ft_printf: [%10.5d]\n", 42);

	printf("printf   : [%-10.5d]\n", 42);
	ft_printf("ft_printf: [%-10.5d]\n", 42);

	printf("printf   : [%.5u]\n", 42U);
	ft_printf("ft_printf: [%.5u]\n", 42U);

	printf("printf   : [%10.5u]\n", 42U);
	ft_printf("ft_printf: [%10.5u]\n", 42U);

	printf("===== OCTAL =====\n");
	ft_printf("===== OCTAL =====\n");

	printf("printf   : [%#o]\n", 255U);
	ft_printf("ft_printf: [%#o]\n", 255U);

	printf("printf   : [%#10o]\n", 255U);
	ft_printf("ft_printf: [%#10o]\n", 255U);

	printf("printf   : [%-#10o]\n", 255U);
	ft_printf("ft_printf: [%-#10o]\n", 255U);

	printf("printf   : [%#.5o]\n", 255U);
	ft_printf("ft_printf: [%#.5o]\n", 255U);

	printf("===== HEX =====\n");
	ft_printf("===== HEX =====\n");

	printf("printf   : [%#x]\n", 255U);
	ft_printf("ft_printf: [%#x]\n", 255U);

	printf("printf   : [%#10x]\n", 255U);
	ft_printf("ft_printf: [%#10x]\n", 255U);

	printf("printf   : [%-#10x]\n", 255U);
	ft_printf("ft_printf: [%-#10x]\n", 255U);

	printf("printf   : [%#.8x]\n", 255U);
	ft_printf("ft_printf: [%#.8x]\n", 255U);

	printf("printf   : [%#X]\n", 255U);
	ft_printf("ft_printf: [%#X]\n", 255U);

	printf("===== LENGTH =====\n");
	ft_printf("===== LENGTH =====\n");

	printf("printf   : [%10lld]\n", 42LL);
	ft_printf("ft_printf: [%10lld]\n", 42LL);

	printf("printf   : [%10llu]\n", 42ULL);
	ft_printf("ft_printf: [%10llu]\n", 42ULL);

	printf("printf   : [%10lo]\n", 255UL);
	ft_printf("ft_printf: [%10lo]\n", 255UL);

	printf("printf   : [%10llx]\n", 255ULL);
	ft_printf("ft_printf: [%10llx]\n", 255ULL);

	printf("printf   : [%10llX]\n", 255ULL);
	ft_printf("ft_printf: [%10llX]\n", 255ULL);

	printf("===== j / z =====\n");
	ft_printf("===== j / z =====\n");

	printf("printf   : [%10ju]\n", (uintmax_t)42);
	ft_printf("ft_printf: [%10ju]\n", (uintmax_t)42);

	printf("printf   : [%10jx]\n", (uintmax_t)255);
	ft_printf("ft_printf: [%10jx]\n", (uintmax_t)255);

	printf("printf   : [%10zu]\n", (size_t)42);
	ft_printf("ft_printf: [%10zu]\n", (size_t)42);

	printf("printf   : [%10zx]\n", (size_t)255);
	ft_printf("ft_printf: [%10zx]\n", (size_t)255);

	printf("===== ZERO VALUES =====\n");
	ft_printf("===== ZERO VALUES =====\n");

	printf("printf   : [%.0d]\n", 0);
	ft_printf("ft_printf: [%.0d]\n", 0);

	printf("printf   : [%5.0d]\n", 0);
	ft_printf("ft_printf: [%5.0d]\n", 0);

	printf("printf   : [%.0u]\n", 0U);
	ft_printf("ft_printf: [%.0u]\n", 0U);

	printf("printf   : [%.0o]\n", 0U);
	ft_printf("ft_printf: [%.0o]\n", 0U);

	printf("printf   : [%.0x]\n", 0U);
	ft_printf("ft_printf: [%.0x]\n", 0U);

	printf("===== POINTER =====\n");
	ft_printf("===== POINTER =====\n");

	printf("printf   : [%p]\n", (void *)0);
	ft_printf("ft_printf: [%p]\n", (void *)0);

	printf("printf   : [%20p]\n", (void *)&main);
	ft_printf("ft_printf: [%20p]\n", (void *)&main);

	printf("printf   : [%-20p]\n", (void *)&main);
	ft_printf("ft_printf: [%-20p]\n", (void *)&main);

	return (0);
}