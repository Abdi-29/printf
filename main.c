#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int len = ft_printf("hello %%\n");
	printf("%i", len);
}
