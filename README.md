*This project has been created as part of the 42 curriculum by alball*

# Libft

A custom C utility library built as part of the 42 common core. It reimplements core libc functions and adds additional utilities including linked list management and a custom `ft_printf`.

The library compiles to a static archive `libft.a` and is designed to be included in future 42 projects.

---

## Build

```shell
make all
```

To include in another project:

```shell
cc -Wall -Wextra -Werror -g my_main.c -I/path/to/libft.h -L/path/to/libft.a -lft -o my_program
```

---

## Function Reference

### Character Classification

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_isalpha` | `int ft_isalpha(int c)` | Returns 1 if `c` is A–Z or a–z, else 0 |
| `ft_isdigit` | `int ft_isdigit(int c)` | Returns 1 if `c` is 0–9, else 0 |
| `ft_isalnum` | `int ft_isalnum(int c)` | Returns 1 if `c` is alphanumeric, else 0 |
| `ft_isascii` | `int ft_isascii(int c)` | Returns 1 if `c` is in ASCII range (0–127), else 0 |
| `ft_isprint` | `int ft_isprint(int c)` | Returns 1 if `c` is a printable character (32–126), else 0 |

### Character Conversion

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_toupper` | `int ft_toupper(int c)` | Converts lowercase letter to uppercase |
| `ft_tolower` | `int ft_tolower(int c)` | Converts uppercase letter to lowercase |

### String Length

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Returns length of null-terminated string |

### Memory Manipulation

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | Fills `n` bytes of memory with byte value `c` |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Fills `n` bytes with null bytes |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest` (no overlap) |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n)` | Copies `n` bytes, handles overlapping regions safely |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Finds first occurrence of byte `c` in `n` bytes |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares `n` bytes; returns difference of first differing byte |

### String Search & Comparison

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Finds first occurrence of `c` in string |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Finds last occurrence of `c` in string |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares first `n` bytes of two strings |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | Finds `little` within first `len` bytes of `big` |

### String Copy & Concatenation

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Copies `src` to `dst` with size limit; null-terminates; returns length of `src` |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Appends `src` to `dst` with size limit; returns total concatenated length |

### Number Conversion

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_atoi` | `int ft_atoi(const char *nptr)` | Converts string to integer, handles leading whitespace and sign |
| `ft_itoa` | `char *ft_itoa(int n)` | Returns allocated string representation of integer (handles `INT_MIN`) |
| `ft_ltoa` | `char *ft_ltoa(long n)` | Returns allocated string representation of long integer |
| `ft_ltoh` | `char *ft_ltoh(unsigned long n, int lower, int pointer)` | Returns allocated hex string; `lower=1` for lowercase, `pointer=1` prepends `0x` |

### Memory Allocation

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | Allocates zero-initialised block of `nmemb * size` bytes |
| `ft_realloc` | `void *ft_realloc(void *ptr, size_t size)` | Reallocates `ptr` to new `size`, copies old data, zeroes new area |

### String Duplication & Manipulation

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_strdup` | `char *ft_strdup(const char *s)` | Returns allocated duplicate of string `s` |
| `ft_substr` | `char *ft_substr(const char *s, unsigned int start, size_t len)` | Returns allocated substring starting at `start` of length `len` |
| `ft_strjoin` | `char *ft_strjoin(const char *s1, const char *s2)` | Returns allocated concatenation of `s1` and `s2` |
| `ft_strtrim` | `char *ft_strtrim(const char *s1, const char *set)` | Returns allocated string with leading/trailing chars from `set` removed |
| `ft_split` | `char **ft_split(const char *s, char c)` | Returns null-terminated array of strings split by delimiter `c` |

### String Transformation

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_strmapi` | `char *ft_strmapi(const char *s, char (*f)(unsigned int, char))` | Returns new string with `f` applied to each character (passed index and char) |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies `f` to each character of `s` in-place (passed index and pointer to char) |

### File Descriptor Output

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Writes character `c` to file descriptor `fd` |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Writes string `s` to `fd` |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Writes string `s` to `fd` followed by newline |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Writes integer `n` to `fd` (handles `INT_MIN`) |

### Linked List

Uses the `t_list` type: `{ void *content; struct s_list *next; }`

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Creates a new list node with `content` |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Prepends `new` to the list |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Appends `new` to the list |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Returns number of nodes |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Deletes a single node, calling `del` on its content |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes entire list, calling `del` on each node's content |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies `f` to the content of each node |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Returns new list built by applying `f` to each node's content; calls `del` on failure |

### Formatted Printing

| Function | Signature | Description |
|----------|-----------|-------------|
| `ft_printf` | `int ft_printf(const char *str, ...)` | Prints formatted output; returns total characters written, or -1 on error |

**Supported format specifiers:**

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String (`"(null)"` if NULL) |
| `%p` | Pointer in hex with `0x` prefix (`"(nil)"` on Linux for NULL) |
| `%d` | Signed decimal integer |
| `%i` | Signed integer (base 10) |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal lowercase |
| `%X` | Hexadecimal uppercase |
| `%%` | Literal `%` |
