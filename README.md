*This project has been created as part of the 42 curriculum by dserrano*
# Description
This project involves recreating a simplified version of the standard C function `printf`. This function prints a message to the screen and can use “format specifiers”, which are instructions for displaying different data types and combining them with the final string to be displayed on the screen.
The main objective of this project is to learn how to handle **variable arguments** and manage the parsing of different types of output formats.
## Supported formats
My implementation supports the following conversions:
| Specifier | Description |
| - | - |
| `%c` | Prints a char |
| `%s` | Prints a string |
| `%p` | Prints a memory address (pointer) in hex format |
| `%d`/`%i` | Prints a decimal integer (base 10) |
| `%u` | Prints an unsigned decimal integer (base 10) |
| `%x` | Prints a hex number in lowercase |
| `%X` | Prints a hex number in uppercase |
| `%%` | Prints the percent symbol |
# Instructions
## Compilation and use
1. In your terminal, run the `make` command to generate the libftprintf.a file.
2. In the project root dir, create a `.c` file, include the header, for example:

		#include "ft_printf.h"

		int	main(void)
		{
			ft_printf("Hello world! %s %d\n", "test", 42);
			return (0);
		}
3. Link your file to the library and compile: `cc -Wall -Wextra -Werror main.c libftprintf.a -o test`
# Resources
- [Printf function](https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_es.html)
- C Programming A Modern Approach 2nd edition. K. N. King
- Man pages
## Use of AI
In this project, AI was used to improve the README file.
# Algorithm and data structure
## Data Structure: Auto-Grow Dynamic Buffer
To manage the output, I have implemented a custom data structure that acts as a dynamic buffer. This structure contains:
- `char *data`: The pointer to the string's content.
- `size_t data_len`: The current length of the stored characters.
- `size_t size`: The current total buffer capacity.

This approach allows all write operations to be grouped into a single final call to `write`. Storing the data in memory before printing it drastically **reduces the number of system calls**, improving the function's overall performance.
## Memory Management Algorithm: Resizing Strategy
Every time the buffer reaches its maximum capacity, the algorithm allocates a new block of memory that is twice the size of the previous one. The existing data is then copied, the old memory is freed, and the operation continues.
## Execution Flow and Parsing
The process is divided into three distinct stages:
1. **Scanning**: The format string is scanned. Ordinary characters are added directly to the dynamic buffer.
2. **Parsing**: When a `%` is detected, the flow is redirected to a parsing function that evaluates the next character. If the specifier is valid, the conversion is performed and the result is appended to the buffer; if it is invalid, it is treated as a literal character to ensure the function’s robustness.
3. **Completion**: Once the entire string has been processed, the buffer is flushed to the console, all dynamic memory used is released, and the variable arguments are closed using `va_end`.
