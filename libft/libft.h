#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
#define int size_t

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
int     ft_put_char(char c );
char	*ft_strdup(const char *src);   
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_fd(int n, int fd)
size_t	ft_strlcat(char *dst, const char *src, size_t size);
