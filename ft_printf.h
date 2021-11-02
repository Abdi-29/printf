#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa_unsigned(unsigned int n);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base(size_t nbr);
void	conversation_hex(va_list start, int *len);
void	conversation_hex_up(va_list start, int *len);
void	ft_check_type(char type, va_list start, int *len);
void	conversation_char(va_list start, int *len);
void	conversation_str(va_list start, int *len);
void	conversation_pointer(va_list start, int *len);
void	conversation_integer(va_list start, int *len);
void	conversation_unsigned(va_list start, int *len);

#endif 
