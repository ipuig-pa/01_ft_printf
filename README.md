# ft_printf

This project was developed individually by:

- ipuig-pa

## Project Overview

---

This project is a custom implementation of the standard C library function `printf()`, focusing on handling variable arguments and producing formatted output. The function closely mimics the behavior of the original `printf()`, but without implementing the buffer management of the standard function.

## Compilation

---

Compiling the library creates a static library archive file named `ft_print.a`.

```
[ ]

make        # Compile
make clean  # Remove object files
make fclean # Remove object files and library archive
make re     # Recompile everything

```

## Usage

---

After compilation, include the header file in your C projects and link with the library:

```c

#include "ft_printf.h"

int main(void)
{
   //use ft_printf function in your project
}

```

Compile with:

```
[ ]

cc -Wall -Wextra -Werror -L. -lftprintf your_program.c -o your_program
```

Use ft_printf just like the standard printf:

```c
[ ]

c
ft_printf("Hello, %s! The answer is %d.\n", "world", 42);

```

## Features

---

Handles the following conversion specifiers:

- `%c`: Prints a single character
- `%s`: Prints a string (as defined by the common C convention)
- `%p`: Prints a void pointer in hexadecimal format
- `%d`: Prints a decimal (base 10) number
- `%i`: Prints an integer in base 10
- `%u`: Prints an unsigned decimal (base 10) number
- `%x`: Prints a number in hexadecimal (base 16) lowercase format
- `%X`: Prints a number in hexadecimal (base 16) uppercase format
- `%%`: Prints a percent sign

### Return Value

Like the original `printf()`, the function returns the number of characters printed, or a negative value if an error occurs.

## Implementation Details

---

This project utilizes variadic functions in C (`va_list`, `va_start`, `va_arg`, `va_copy`, `va_end`) to handle a variable number of arguments. The implementation focuses on:

- Parsing format strings to identify conversion specifiers
- Handling each data type appropriately based on the conversion
- Converting numbers to different bases (decimal, hexadecimal)

## License

---

This project was developed as part of the curriculum at 42 School. Use of this code must comply with the school's academic integrity policies.
