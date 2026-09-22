#include "ft_printf.h"

int stock_format(t_format *format, char *Message, int i)
{
    init_format(format);
    i = stock_flags(format, Message, i);
    i = stock_width(format, Message, i);
    i = stock_precision(format, Message,i);
    i = stock_length(format, Message, i);
    return i ;
}
int ft_printf(const char *Message, ...)
{
    int i;
    t_format format;
    int count;
    va_list args;
    i = 0;
    count = 0;
    va_start(args, Message)
    while(Message[i])
    {
        if(Message[i] == '%')
        {
            i++;
            if(is_flags_valid(Message, i) == 0 )
            { 
                i = stock_format(&format , Message, i);
                count += hundelConversation(Message[i], &args, format);
            }
            else
            {
                write(1, &Message[i], 1);
                count++;
            }
        }
        i++;
    }
    va_end(args);
    return count ;
}