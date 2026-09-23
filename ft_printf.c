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

/*int	main(void)
{
	int a;
	int b;

	printf("----- BASIC -----\n");
	a = printf("printf   : [%s]\n", "hello");
	b = ft_printf("ft_printf: [%s]\n", "hello");
	printf("return: printf=%d | ft_printf=%d\n\n", a, b);

	printf("----- WIDTH -----\n");
	a = printf("printf   : [%10s]\n", "hello");
	b = ft_printf("ft_printf: [%10s]\n", "hello");
	printf("return: printf=%d | ft_printf=%d\n\n", a, b);

	printf("----- LEFT ALIGN -----\n");
	a = printf("printf   : [%-10s]\n", "hello");
	b = ft_printf("ft_printf: [%-10s]\n", "hello");
	printf("return: printf=%d | ft_printf=%d\n\n", a, b);

	printf("----- PRECISION -----\n");
	a = printf("printf   : [%.3s]\n", "hello");
	b = ft_printf("ft_printf: [%.3s]\n", "hello");
	printf("return: printf=%d | ft_printf=%d\n\n", a, b);

	printf("----- WIDTH + PRECISION -----\n");
	a = printf("printf   : [%10.3s]\n", "hello");
	b = ft_printf("ft_printf: [%10.3s]\n", "hello");
	printf("return: printf=%d | ft_printf=%d\n\n", a, b);

	printf("----- LEFT + PRECISION -----\n");
	a = printf("printf   : [%-10.3s]\n", "hello");
	b = ft_printf("ft_printf: [%-10.3s]\n", "hello");
	printf("return: printf=%d | ft_printf=%d\n\n", a, b);

	return (0);
}*/