#include <unistd.h>
#include <stdarg.h>

int stock_flags(t_format *format, char *message , int i);
int is_flags_valid(char * format, int i);
int is_length_valide(char *length , int i);
int is_valide_format(char c);
void init_format(t_format *format);
int	stock_precision(t_format *format, char *message, int i);
typedef struct s_format
{
    int width;
    int precesion;
    int point;
    int hash;
    int zero;
    int minus;
    int plus;
    int space;
    int length;
} t_format;
int stock_flags(t_format *format, char *message , int i)
{
	while (message[i] == '#' || message[i] == '0'
		|| message[i] == '-' || message[i] == '+'
		|| message[i] == ' ')
    {
        if(message[i] == '0')
            format->zero = 1;
        else if (message[i] == '#')
            format->hash = 1;
        else if(message[i] == '-')
            format->minus = 1;
        else if(message[i] == '+')
            format->plus = 1;
        else if(message[i] == ' ')
            format->space = 1;
        else 
            break;
        i++;
    }
    return i ;
}
int is_flags_valid(char * format, int i)
{
    int point;
    point = 0;
    while (format[i] == '.' || format[i] == '#' 
        ||(format[i] >= '0' && format[i] <= '9' ) 
        || format[i] == '+' || format[i] == '-'   )
    {
        if(point == 1 && (format[i] == '.'  || format[i] == '+'
                      || format[i] == '#'  || format[i] == '-' ))
            return 1;
        if(format[i] == '.' )
            {
                point++;
                if(point > 1)
                    return 1;
            }
        i++;
    }
    i = is_length_valide(format, i);
    if(!format[i])
        return 1;
    return 0;
}
int is_valide_format(char c)
{
    return ( c == 'd' || c == 'D' || c == 'p' || c == 's' || c == 'S'
            || c == 'o' || c == 'O' || c == 'u' || c == 'i'
            || c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || '%');
}
int is_length_valide(char *length , int i)
{
    while(length[i] == 'l' || length[i] == 'h' || length[i] == 'j' || length[i] == 'z')
    {
        if( length[i] == 'z' || length[i] == 'j')
            return i + 1;
        if(length[i +1] == 'h' || length[i + 1] == 'l')
            return i + 2;
        i++;
    }
    return i;
}
void init_format(t_format *format)
{
    format->width = 0;
    format->precesion= 0;
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
		format->width = format->width * 10 + (message[i] - '0');
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
	format->precesion = 0;
	while (message[i] >= '0' && message[i] <= '9')
	{
		format->precesion = format->precesion* 10 + (message[i] - '0');
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