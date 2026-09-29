#include "libft.h"
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    int i;
    int j;
    str = malloc(sizeof(char )*(ft_strlen(s1) + ft_strlen(s2) + 1));
    i = 0;
    j = 0;
    while(s1[i] != '\0')
    {
        str[i] = s1[j];
        i++;
        j++;
    }
    j = 0;
    while(s2[j] != '\0')
    {
        str[i] = s2[j];
        j++;
        i++;
    }
    return str;
}