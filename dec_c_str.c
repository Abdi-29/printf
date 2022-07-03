#include "ft_printf.h"
#include "libft.h"

void	char_function(va_list start, int *len)
{
	char	c;

	c = va_arg(start, int);
	ft_putchar_fd(c, 1);
	*len += 1;
}

void	string_function(va_list start, int *len)
{
	char	*str;

	str = va_arg(start, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
		ft_putstr_fd(str, 1);
		*len += ft_strlen(str);
		free(str);
	}
	else
	{
		ft_putstr_fd(str, 1);
		*len += ft_strlen(str);
	}
}

void	decimal_function(va_list start, int *len)
{
	int		nbr;
	char	*str;

	nbr = va_arg(start, int);
	str = ft_itoa(nbr);
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	*len += ft_strlen(str);
	free(str);
}

void	unsigned_int_function(va_list start, int *len)
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(start, unsigned int);
	str = ft_itoa_unsigned(nbr);
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	*len += ft_strlen(str);
	free(str);
}
