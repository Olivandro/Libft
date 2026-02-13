# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alball <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/22 14:45:06 by alball            #+#    #+#              #
#    Updated: 2025/11/22 14:45:21 by alball           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_strlen.c \
      ft_memset.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_strnstr.c \
      ft_atoi.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_strtrim.c \
      ft_split.c \
      ft_itoa.c \
      ft_strmapi.c \
      ft_striteri.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c

BONUS_SRC = ft_lstnew.c \
	    ft_lstadd_front.c \
	    ft_lstsize.c \
	    ft_lstlast.c \
	    ft_lstadd_back.c \
	    ft_lstdelone.c \
	    ft_lstclear.c \
	    ft_lstiter.c \
	    ft_lstmap.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

REMOVE = rm -f

UNAME_S := $(shell uname -s)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(NAME) $(BONUS_OBJ)
	ar -rcs $(NAME) $(BONUS_OBJ)

# libft-unit-tester pre-req
ifeq ($(UNAME_S), Darwin)
so:
	$(CC) -fPIC $(CFLAGS) $(SRC) $(BONUS_SRC)
	@gcc -shared -o libft.so $(OBJ) $(BONUS_OBJ)
endif

ifeq ($(UNAME_S), Linux)
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BONUS_SRC)
	@gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)
endif
# end of libft-unit-test pre-req

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
 
fclean: clean
	@$(REMOVE) $(NAME)

re: fclean $(NAME)

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
