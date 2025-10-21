#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			if (ft_strchr("%cspdiuxX", s[i + 1]))
			{
				count += ft_function_type(&s[i + 1], ap);
				i += 2;
			}
			else
			{
				count += write(1, &s[i], 1);
				i++;
			}
		}
		else
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
