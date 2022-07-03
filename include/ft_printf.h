#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_type {
	int	type;
	void	(*function_pointer)(va_list start, int *len);
}				t_type;

char	*ft_itoa_unsigned(unsigned int n);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base(size_t nbr);
void	ft_check_type(int type, va_list start, int *len);
void	lower_hex_function(va_list start, int *len);
void	upper_hex_function(va_list start, int *len);
void	char_function(va_list start, int *len);
void	string_function(va_list start, int *len);
void	pointer_function(va_list start, int *len);
void	decimal_function(va_list start, int *len);
void	unsigned_int_function(va_list start, int *len);

#endif 
