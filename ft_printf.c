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