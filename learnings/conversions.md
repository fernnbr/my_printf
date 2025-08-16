## %c | Character

**Expects an int that represents an ASCII character**
Prints a single character

**Translating: Imagine you’re receiving a single letter from a team member, like “A” for attendance**
%c just shows that one letter on your report

> printf("%c\n", 'A'); // Output: A

## %s | String

**Expects a char * (pointer to a null-terminated string)**
Prints all characters until \0

**Translating: You ask a team member for a full paragraph instead of a single letter**
%s prints the whole message until the “end of message” marker

> printf("%s\n", "Hello"); // Output: Hello

## %p | Pointer

**Expects a void * pointer**
Prints the memory address in hexadecimal

**Translating: You want to know where someone is sitting in the office, not their report**
%p shows the location rather than the actual data

> int x = 42;
> printf("%p\n", &x); // Output: memory address like 0x7ffee4b2


## %d / %i | Signed Decimal

**Expects int**
Prints the number with a possible '-' for negative numbers

**Translating: You’re collecting a signed report: positive for tasks done, negative for tasks delayed**

> printf("%d\n", -42); // Output: -42

## %u → Unsigned Decimal

**Expects unsigned int**
Prints only positive numbers (0 and up)

**Translating: You only want good news counts—no negatives allowed**

> printf("%u\n", 3000000000); // Output: 3000000000


## %x | Lowercase Hexadecimal

**Expects unsigned int**
Prints the number in base 16 using lowercase letters (a–f)

**Translating: You’re reporting in hex code—like using shorthand for complex tasks**
Lowercase letters are like casual notes

> printf("%x\n", 255); // Output: ff

## %X → Uppercase Hexadecimal

**Same as %x, but letters A–F are uppercase**

**Translating: Shorthand reports, but written in capital letters to show importance or priority**

> printf("%X\n", 255); // Output: FF

## %% → Percent Sign

**Prints a literal %**
No argument needed

**Translating: You need to write a percent sign on the report, not a number**
It’s like “marking a checkbox” instead of getting a report

> printf("Progress: 100%%\n"); // Output: Progress: 100%

