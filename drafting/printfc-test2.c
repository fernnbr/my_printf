int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			count += write(1, &s[i], 1);
			i++;
		}
		else if (s[i] == '%')
		{
			i++;
			if (ft_strchr("%cspdiuxX", s[i]))
				count += ft_function_type(&s[i], ap);
			else if (s[i] != '\0')
				count += write(1, &s[i], 1);
			if (s[i] != '\0')
				i++;
		}	
	}
	va_end(ap);
	return (count);
}
