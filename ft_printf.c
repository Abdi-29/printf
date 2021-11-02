#include "ft_printf.h"
#include "libft.h"

void	ft_check_type(char type, va_list start, int *len)
{
	if (type == '%')
	{
		ft_putchar_fd(type, 1);
		*len += 1;
	}
	else if (type == 'c')
		conversation_char(start, len);
	else if (type == 's')
		conversation_str(start, len);
	else if (type == 'p')
		conversation_pointer(start, len);
	else if (type == 'd' || type == 'i')
		conversation_integer(start, len);
	else if (type == 'u')
		conversation_unsigned(start, len);
	else if (type == 'x')
		conversation_hex(start, len);
	else if (type == 'X')
		conversation_hex_up(start, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (0);
	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_check_type(*(format + 1), args, &len);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
