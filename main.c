#include "includes/ft_printf.h"
#include "stdio.h"

int		main()
{
	ft_putnbr(ft_printf("hello\n", 12456));
	//printf("hello %#-0 +10.4", 10);

	return(0);
}