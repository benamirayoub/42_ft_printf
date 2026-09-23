#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_format
{
	int	width;
	int	precision;
	int	point;
	int	hash;
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	length;
}	t_format;

int	stock_flags(t_format *format, char *message, int i)
{
	while (message[i] == '#' || message[i] == '0'
		|| message[i] == '-' || message[i] == '+'
		|| message[i] == ' ')
	{
		if (message[i] == '#')
			format->hash = 1;
		else if (message[i] == '0')
			format->zero = 1;
		else if (message[i] == '-')
			format->minus = 1;
		else if (message[i] == '+')
			format->plus = 1;
		else if (message[i] == ' ')
			format->space = 1;
		i++;
	}
	return (i);
}
int	is_length_valide(char *length, int i)
{
	while (length[i] == 'l' || length[i] == 'h'
		|| length[i] == 'j' || length[i] == 'z')
	{
		if (length[i] == 'z' || length[i] == 'j')
			return (i + 1);
		if (length[i + 1] == 'h' || length[i + 1] == 'l')
			return (i + 2);
		i++;
	}
	return (i);
}

int	is_flags_valid(char *format, int i)
{
	int	point;

	point = 0;
	while (format[i] == '.' || format[i] == '#'
		|| (format[i] >= '0' && format[i] <= '9')
		|| format[i] == '+' || format[i] == '-')
	{
		if (format[i] == '.')
		{
			point++;
			if (point > 1)
				return (1);
		}
		i++;
	}
	i = is_length_valide(format, i);
	if (!format[i])
		return (1);
	return (0);
}


int	is_valide_format(char c)
{
	return (c == 'd' || c == 'D' || c == 'p' || c == 's'
		|| c == 'S' || c == 'o' || c == 'O' || c == 'u'
		|| c == 'i' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == '%');
}

void	init_format(t_format *format)
{
	format->width = 0;
	format->precision = 0;
	format->point = 0;
	format->hash = 0;
	format->zero = 0;
	format->minus = 0;
	format->plus = 0;
	format->space = 0;
	format->length = 0;
}

int	stock_width(t_format *format, char *message, int i)
{
	while (message[i] >= '0' && message[i] <= '9')
	{
		format->width = format->width * 10 + message[i] - '0';
		i++;
	}
	return (i);
}

int	stock_precision(t_format *format, char *message, int i)
{
	if (message[i] != '.')
		return (i);
	format->point = 1;
	i++;
	format->precision = 0;
	while (message[i] >= '0' && message[i] <= '9')
	{
		format->precision = format->precision * 10 + message[i] - '0';
		i++;
	}
	return (i);
}

int	stock_length(t_format *format, char *message, int i)
{
	if (message[i] == 'h' && message[i + 1] == 'h')
	{
		format->length = 2;
		return (i + 2);
	}
	if (message[i] == 'h')
	{
		format->length = 1;
		return (i + 1);
	}
	if (message[i] == 'l' && message[i + 1] == 'l')
	{
		format->length = 4;
		return (i + 2);
	}
	if (message[i] == 'l')
	{
		format->length = 3;
		return (i + 1);
	}
	if (message[i] == 'j')
	{
		format->length = 5;
		return (i + 1);
	}
	if (message[i] == 'z')
	{
		format->length = 6;
		return (i + 1);
	}
	return (i);
}

int	stock_format(t_format *format, char *message, int i)
{
	init_format(format);
	i = stock_flags(format, message, i);
	i = stock_width(format, message, i);
	i = stock_precision(format, message, i);
	i = stock_length(format, message, i);
	return (i);
}

void	put_char_i(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

int	num_len(long long nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	put_number(long long nb)
{
	char	c;

	if (nb >= 10)
		put_number(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

long long	signed_value(va_list *args, t_format *format)
{
	if (format->length == 2)
		return ((signed char)va_arg(*args, int));
	if (format->length == 1)
		return ((short)va_arg(*args, int));
	if (format->length == 3)
		return (va_arg(*args, long));
	if (format->length == 4)
		return (va_arg(*args, long long));
	return (va_arg(*args, int));
}

void	print_signed(long long nb, int sign, int padding, t_format *format)
{
	if (!format->minus && !format->zero)
		put_char_i(' ', padding);
	if (sign == -1)
		write(1, "-", 1);
	else if (sign == 1)
		write(1, "+", 1);
	if (!format->minus && format->zero)
		put_char_i('0', padding);
	put_number(nb);
	if (format->minus)
		put_char_i(' ', padding);
}

int	handel_signed(va_list *args, t_format *format)
{
	long long	nb;
	int			count;
	int			sign;
	int			padding;

	nb = signed_value(args, format);
	sign = 0;
	if (nb < 0)
	{
		sign = -1;
		nb = -nb;
	}
	else if (format->plus)
		sign = 1;
	count = num_len(nb) + (sign != 0);
	padding = format->width - count;
	if (padding < 0)
		padding = 0;
	print_signed(nb, sign, padding, format);
	return (count + padding);
}

int	hundelConversation(char c, va_list *args, t_format *format)
{
	if (c == 'd' || c == 'i')
		return (handel_signed(args, format));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

#endif