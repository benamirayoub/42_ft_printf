#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	tab = (void *)malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}