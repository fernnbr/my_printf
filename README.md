```
"For a moment, nothing happened.
Then, after a second or so, nothing continued to happen" 
- The Hitchhiker's Guide to the Galaxy, Douglas Adams
```

<br></br>

<div align="center">
  
# Welcome, Stranger! 
This is the **printif** repo

<p align="center">
  <img src="https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExd3NwaW81bHd6ZTJwemtrbWY2ZDVlZDVxa3RpYjIwODd1cHpjd2lvbyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/yUrUb9fYz6x7a/giphy.gif">
</p></figcaption>
<p align="center">
  (print, print, print)
</p>

</div>

## About this Repo

This repository will contain my implementation, learning (and attempts) of ft_printf, 
a custom version of the well-known C standard library function printf().


## The Goal(s) 

**The project’s main goal is to understand and recreate the inner workings of printf() while learning how to:**

- Work with variadic functions in C (va_list, va_start, va_arg, va_end) [handling a variable number of arguments]

- Parse and process format strings [characters, strings, integers, hexadecimals, etc]

- Print different data types with custom formatting 

- Build and manage a static library (libftprintf.a)

- Write modular and maintainable C code that can be reused in other projects
  
- Learn how to manage a project with Makefile, memory safety, and coding standards 



## Conversions Supported

This version of ft_printf supports the following conversions:

- %c (character), 
- %s (string), 
- %p (pointer), 
- %d/%i (signed decimal), 
- %u (unsigned decimal), 
- %x (lowercase hex), 
- %X (uppercase hex),
- %% (percent sign)


## Suggested Steps to Build the Project

**1. Understand the Problem**

1.1. Understand the behavior of the original printf()
[please read the /learnings repo here]

1.2. Identify supported conversions in the subject:
%c, %s, %p, %d, %i, %u, %x, %X, %%
[please read the /learnings repo here]

**2. Plan the Architecture**

2.1. Core file: ft_printf.c
(It parses the format string, handles conversions, calls helpers)

**Helper functions:**

- ft_print_char,
- ft_print_string,
- ft_print_pointer,
- ft_print_int,
- ft_print_unsigned,
- ft_print_hex_lower,
- ft_print_hex_upper,
- ft_print_percent

**Utilities:**

- String length (ft_strlen)

- Number-to-string conversions

- Hexadecimal conversion

- Header file: ft_printf.h — prototypes, includes, macros

- Makefile (compiles into libftprintf.a)

**3. Learn Variadic Functions**

3.1. Study and practice and remember to write a simple variadic test function before starting ft_printf

1. va_list

2. va_start

3. va_arg

4. va_end


**4. Implement Mandatory Conversions One by One**

Suggested order:

1. %c → print a single character

2. %% → print a percent sign

3. %s → print strings

4. %d / %i → print integers (signed)

5. %u → print unsigned integers

6. %x / %X → print hexadecimals

7. %p → print memory addresses in hex


**5. Integrate and Test**

5.1. Combine all helpers into ft_printf.c.

5.2. Ensure each format is parsed and handled correctly.

5.3. Use both:

- Your own tests

- Comparison against real printf()


**6. Build the Static Library**

6.1. Use ar rcs to create libftprintf.a

6.2. Ensure make, make clean, make fclean, make re work.

6.3. Confirm no unnecessary relinking


**7. Optional Bonus**
Plan bonuses before coding if possible to avoid major rewrites

7.1. Implement flags:

1. - (left-align)

2. 0 (zero padding)

3. . (precision)

4. Field width

5. #, space, +


## Tips for Success (my opinion) 

1. Start small: implement one conversion fully before moving to the next

2. Write mini-test mains for each helper function

3. Use modular functions to avoid huge functions

4. Compare outputs with the real printf() to spot differences


## Gotchas to Avoid

(!) FAIL IF: You forget to count and return the total printed characters (mandatory for ft_printf)

(!) FAIL IF you mix signed and unsigned printing  (%u must never print negatives)

(!) FAIL IF: %p format always starts with 0x, and must handle NULL as (nil)

(!) FAIL IF there are memory leaks (even though most prints don’t allocate, some conversions may require malloc() for strings)

(!) FAIL IN bonus implementation, if the mandatory part isn’t perfect


## Hints

1. Use recursion or iterative division/modulo to handle number printing in any base

2. Store hex digits in a string like "0123456789abcdef" for lowercase and "0123456789ABCDEF" for uppercase

3. Handle edge cases early (e.g., empty strings, zero values, NULL pointers)

4. Test with edge cases like INT_MIN, INT_MAX, UINT_MAX, NULL, empty strings, and large widths


## Other Uses

Once completed, this library can be linked with future C projects, 
replacing the system printf() in environments where it is restricted

