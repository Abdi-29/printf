#include "libft.h"

static int	ft_size(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (len + 1);
	}
	while (n != 0)
	{
		if (n / 10 != 0)
		{
			n /= 10;
			len++;
		}
		else
		{
			n %= 10;
			n = 0;
			len++;
		}
	}
	return (len);
}

static char	*ft_positive(int len, unsigned int n)
{
	char	*s;
	int		i;

	i = len;
	s = malloc(len * sizeof(char) + 1);
	if (s == 0)
		return (0);
	len -= 1;
	while (len > -1)
	{
		s[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*s;
	int		len;

	len = ft_size(n);
	s = ft_positive(len, n);
	return (s);
}
