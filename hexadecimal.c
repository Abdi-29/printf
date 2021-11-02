#include "ft_printf.h"
#include "libft.h"

static int	ft_size(size_t n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (len + 1);
	}
	while (n != 0)
	{
		if (n / 16 != 0)
		{
			n /= 16;
			len++;
		}
		else
		{
			n %= 16;
			n = 0;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa_base(size_t nbr)
{
	int		remainder;
	char	*tmp;
	int		i;

	i = ft_size(nbr);
	tmp = ft_calloc((i + 1), sizeof(char));
	if (!tmp)
		return (0);
	while (i)
	{
		remainder = nbr % 16;
		if (remainder < 10)
			tmp[i - 1] = remainder + '0';
		else
			tmp[i - 1] = remainder + '7';
		i--;
		nbr /= 16;
		if (nbr == 0)
			break ;
	}
	return (tmp);
}

void	conversation_hex(va_list start, int *len)
{
	unsigned int	i;
	char			*hex;
	int				j;
	int				k;

	j = *len;
	k = 0;
	i = va_arg(start, unsigned int);
	hex = ft_itoa_base(i);
	while (hex[k])
	{
		ft_putchar_fd(ft_tolower(hex[k]), 1);
		k++;
		j++;
	}
	free(hex);
	*len = j;
}	

void	conversation_hex_up(va_list start, int *len)
{
	unsigned int	i;
	char			*hex;
	int				j;
	int				k;

	j = *len;
	k = 0;
	i = va_arg(start, unsigned int);
	hex = ft_itoa_base(i);
	while (hex[k])
	{
		ft_putchar_fd(ft_toupper(hex[k]), 1);
		k++;
		j++;
	}
	free(hex);
	*len = j;
}

void	conversation_pointer(va_list start, int *len)
{
	char	*ptr;
	size_t	i;
	int		j;
	int		k;

	j = 2;
	k = 0;
	i = va_arg(start, size_t);
	ptr = ft_itoa_base(i);
	ft_putstr_fd("0x", 1);
	while (ptr[k])
	{
		ft_putchar_fd(ft_tolower(ptr[k]), 1);
		k++;
		j++;
	}
	free(ptr);
	*len += j;
}
