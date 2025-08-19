## #ifndef FT_PRINTF_H
“If not defined”: starts a header guard so this file’s contents 
are only included once per compilation unit

## # define FT_PRINTF_H
Defines the guard macro FT_PRINTF_H (42-style spacing after #). 
From now on, any further inclusion of this header in the same TU will be skipped

## # include <stdlib.h>
Pulls in standard library declarations. 
Important because it defines size_t (used later by strlcpy). 
It also declares malloc/free, etc.

## # include <stdint.h>
Fixed-width integer types (uint32_t, uintptr_t, …). 
Not strictly required by the prototypes shown, 
but useful if implementations use e.g. uintptr_t for pointer printing

## # include <unistd.h>
POSIX I/O declarations, notably write(), 
which your print helpers likely use

## # include <stdarg.h>
Variadic-arguments support (va_list, va_start, va_arg, va_end). 
Required by ft_printf and any dispatcher that consumes va_list

## int ft_printf(const char *s, ...);
printf-like entry point. s is the format string; ... 
means “variadic” arguments follow. 
Conventionally returns the number of characters written, 
or a negative value on error

## int ft_function_type(const char *s, va_list ap);
Likely a dispatcher that looks at a conversion specifier in *s (e.g., %d, %x) 
and pulls the next argument from ap, then calls the right helper. 
Returns the number of characters printed for that specifier.

## int ft_print_hex_upper(unsigned int nbr);
Prints nbr in base-16 using uppercase digits (A–F). 
Returns how many chars were written.

## int ft_print_hex_lower(unsigned int nbr);
Same as above but lowercase digits (a–f). 
Returns count

## int ft_print_c(int letter);
Prints a single character (typically cast to unsigned char). 
Returns 1 on success (or maybe -1 on error)

## int ft_print_s(char *str);
Prints a C-string. 
Returns the number of characters written

## int ft_print_nbr(int n);
Prints a signed decimal integer. 
Returns count

## int ft_print_unbr(unsigned int n);
Prints an unsigned decimal integer. 
Returns count

## char *ft_strchr(const char *s, int c);
Prototype of the standard strchr: finds the 
first occurrence of c (converted to unsigned char) in s. 
Returns a pointer to it or NULL

## int ft_strlen(const char *s);
Length of string s, not counting the null terminator.
Note: the conventional return type is size_t, not int
Using int risks overflow on very long strings 
and may mismatch with other code expecting size_t

## size_t ft_strlcpy(char *dst, const char *src, size_t size);
BSD strlcpy: copies up to size-1 bytes from src to dst, 
NUL-terminates if size > 0, and returns the full length of src 
(so you can detect truncation).

## int ft_print_mem(unsigned long nbr);
Prints a memory address (usually with the 0x prefix). 
Unsigned long is commonly used to hold a casted pointer on many platforms. 
Returns count

## int ft_print_mem2(unsigned long nbr);
Likely an internal helper for the recursive/iterative hex 
printing part without the 0x prefix, separated for reuse. 
Returns count.

#endif
Closes the header guard started at line 1
