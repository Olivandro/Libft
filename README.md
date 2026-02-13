*This project has been created as part of the 42 curriculum by alball*

# Description
This is my Libft, created as part of the 42 common core. 
It is the complete Libft project with linked list bonus.

The Libft project is essentially a recreation of core functions from
libc.

## ft_printf
Flags that can be used for variadic variable printing are:

- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` The void * pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

Note: this version of print have does not include teh bonus.

## Road map
- add ft_printf
- add get_next_line

# Instructions
To compile the library please follow the instructions below:

```shell
$ make all
```

This cmd will compile and produce the .a file, specifically `libft.a`.
All that is need to included into your own projects (to included libft functions use)
is `libft.h` and `libft.a`.

basic compiling instructions for projects wanting to include libft:

```shell
$ cc -Wall -Wextra -Werror -g my_main.c -I/path/to/libft.h -L/path/to/libft.a -lft -o my_program
```
