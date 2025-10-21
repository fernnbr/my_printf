#include "ft_printf.h"

int	ft_print_hex_lower(unsigned int nbr)
{
	char	*hex_chars_lower;
	int		count;

	count = 0;
	hex_chars_lower = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_print_hex_lower(nbr / 16);
	count += write(1, &hex_chars_lower[nbr % 16], 1);
	return (count);
}

int	ft_print_hex_upper(unsigned int nbr)
{
	char	*hex_chars;
	int		count;

	count = 0;
	hex_chars = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_print_hex_upper(nbr / 16);
	count += write(1, &hex_chars[nbr % 16], 1);
	return (count);
}

int	ft_print_mem(unsigned long nbr)
{
	int		count;

	count = 0;
	if (nbr == 0)
		return (ft_print_s("(nil)"));
	write(1, "0x", 2);
	count += 2;
	count += ft_print_mem2(nbr);
	return (count);
}

int	ft_print_mem2(unsigned long nbr)
{
	int		count;
	char	*hex_chars_lower;

	count = 0;
	hex_chars_lower = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_print_mem2(nbr / 16);
	count += write(1, &hex_chars_lower[nbr % 16], 1);
	return (count);
}
