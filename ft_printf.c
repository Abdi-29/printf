#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	ft_check_type(int type, va_list start, int *len)
{
	int				i;
	const t_type	option[] = {
	{'s', string_function}, {'c', char_function},
	{'d', decimal_function}, {'i', decimal_function},
	{'X', upper_hex_function}, {'x', lower_hex_function},
	{'p', pointer_function}, {'u', unsigned_int_function},
	{0, 0}
	};

	i = 0;
	(void)type;
	while (option[i].type)
	{
		if (option[i].type == type)
			return (option[i].function_pointer(start, len));
		i++;
	}
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
