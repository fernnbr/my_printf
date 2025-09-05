#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i; // index for copying characters from src to dst
	size_t	j; // will hold the length of src

	j = 0;
	i = 0;
	while (src[j] != '\0')  // count the length of src
	{
		j++;
	}
	if (size == 0)          // if destination buffer size is 0
	{
		return (j);         // return the length of src (dst can't be written at all)
	}
	while ((i < size - 1) && (src[i] != '\0')) // copy characters while space remains
	{
		dst[i] = src[i];    // copy one character from src to dst
		i++;
	}
	dst[i] = '\0';         // always null-terminate the destination string
	return (j);            // return the full length of src (not the copied length)
}

int	ft_strlen(const char *s)
{
	size_t	i;   // counter for characters

	i = 0;
	while (s[i] != '\0')  // loop until null terminator
	{
		i++;
	}
	return (i);            // return number of characters before '\0'
}

char	*ft_strchr(const char *s, int c)
{
	int	i;  // index to iterate through s

	i = 0;
	while (s[i] != '\0')              // scan until end of string
	{
		if (s[i] == (unsigned char)c) // if character matches c
			return ((char *)&s[i]);   // return pointer to first occurrence
		i++;
	}
	if ((unsigned char)c == '\0')     // special case: looking for '\0'
		return ((char *)&s[i]);       // return pointer to string terminator
	return (NULL);                    // if not found, return NULL
}

