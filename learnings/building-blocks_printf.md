## In libftc 
It uses ft_strlen + ft_strchr + ft_strlcpy
These three functions are like building blocks that printf reuses in different stages:

ft_strchr → format parsing
printf must scan the format string ("Hello %s %d") to find the next %.
ft_strchr is perfect for this: "does this string contain a %? Where is it?

ft_strlen → string output
When printf prints a string (%s), it must know how many characters to write.

ft_strlcpy → safe buffer handling
Some printf implementations build parts of the output into a buffer before writing.
ft_strlcpy ensures strings are copied safely, null-terminated, and truncated if needed.
