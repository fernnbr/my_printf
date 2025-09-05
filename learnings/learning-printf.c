int	ft_printf(const char *s, ...)
{
	va_list	ap;     // special type to hold arguments passed with "..."
	int		count;  // total characters printed (return value of printf)
	int		i;      // index to walk through the format string

	i = 0;
	count = 0;
	va_start(ap, s);  // initialize ap to retrieve the "..." arguments, starting after 's'

//Main loop: scanning the format string

	while (s[i] != '\0')      // go through each character until end of format string
	{
		if (s[i] != '%')      // normal characters (not a format specifier)
		{
			count += write(1, &s[i], 1);  // print it directly
			i++;
		}
		else if (s[i] == '%') // found a '%', so maybe a specifier follows
		{
			i++; // move to the character *after* '%'
      
//Checking valid specifiers
			if (ft_strchr("%cspdiuxX", s[i]))
				count += ft_function_type(&s[i], ap);
			i++;
		}	
	}

//Closing 
	va_end(ap);       // clean up the variable argument list
	return (count);   // return total characters printed (like real printf)
}

// The dispatcher 

int	ft_function_type(const char *s, va_list ap)
{
	int	type_count;

	type_count = 0;  // number of chars printed for this specifier


// Each Case 

	if (*s == '%')
		type_count += write(1, "%", 1);  // "%%" prints a single '%'

	if (*s == 'c')
		type_count += ft_print_c(va_arg(ap, int));  
		// %c → extract an int (char is promoted in va_args) and print as character

	if (*s == 's')
		type_count += ft_print_s(va_arg(ap, char *));  
		// %s → extract a char* and print string

	if (*s == 'p')
		type_count += ft_print_mem(va_arg(ap, unsigned long));  
		// %p → extract pointer (usually casted to unsigned long) and print in hex with "0x"

	if ((*s == 'd') || (*s == 'i'))
		type_count += ft_print_nbr(va_arg(ap, int));  
		// %d / %i → extract int and print decimal number

	if ((*s == 'u'))
		type_count += ft_print_unbr(va_arg(ap, unsigned int));  
		// %u → extract unsigned int and print decimal number

	if (*s == 'x')
		type_count += ft_print_hex_lower(va_arg(ap, unsigned int));  
		// %x → extract unsigned int and print hexadecimal (lowercase)

	if (*s == 'X')
		type_count += ft_print_hex_upper(va_arg(ap, unsigned int));  
		// %X → extract unsigned int and print hexadecimal (UPPERCASE)

	return (type_count);  // return how many chars this specifier printed
}

