FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT = libft.a

HDR = hdr/

SRC = src/ft_putchar_fd.c \
	  src/ft_atoi.c \
	  src/ft_calloc.c \
	  src/ft_itoa.c \
	  src/ft_memset.c \
	  src/ft_putchar_fd.c \
	  src/ft_putstr_fd.c \
	  src/ft_strjoin.c \
	  src/ft_strlen.c \
	  src/ft_substr.c \
	  src/print_u.c \
	  src/print_p.c \
	  src/print_di_x.c \
	  src/print_c_s.c \
	  src/ft_printf.c \
	  src/ft_printf_struct.c \
	  src/ft_bzero.c \
	  src/ft_itoa_base.c \
	  src/ft_strlcat.c \
	  src/ft_strlcpy.c \
	  src/putchar_width.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.c.o:
	gcc -I $(HDR) $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "ok"

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
