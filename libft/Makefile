# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkunduru <hkunduru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 12:55:46 by rschramm          #+#    #+#              #
#    Updated: 2017/03/07 07:28:48 by rschramm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS += -Wall -Wextra -Werror
SRCS = libft/ft_memset.c \
	   libft/ft_bzero.c \
	   libft/ft_memcpy.c \
	   libft/ft_memccpy.c \
	   libft/ft_memmove.c \
	   libft/ft_memchr.c \
	   libft/ft_memcmp.c \
	   libft/ft_strlen.c \
	   libft/ft_strdup.c \
	   libft/ft_strcpy.c \
	   libft/ft_strncpy.c \
	   libft/ft_strcat.c \
	   libft/ft_strncat.c \
	   libft/ft_strlcat.c \
	   libft/ft_strchr.c \
	   libft/ft_strrchr.c \
	   libft/ft_strstr.c \
	   libft/ft_strnstr.c \
	   libft/ft_strcmp.c \
	   libft/ft_strncmp.c \
	   libft/ft_atoi.c \
	   libft/ft_isalpha.c \
	   libft/ft_isdigit.c \
	   libft/ft_isalnum.c \
	   libft/ft_isascii.c \
	   libft/ft_isprint.c \
	   libft/ft_toupper.c \
	   libft/ft_tolower.c \
	   libft/ft_memalloc.c \
	   libft/ft_memdel.c \
	   libft/ft_strnew.c \
	   libft/ft_strdel.c \
	   libft/ft_strclr.c \
	   libft/ft_striter.c \
	   libft/ft_striteri.c \
	   libft/ft_strmap.c \
	   libft/ft_strmapi.c \
	   libft/ft_strequ.c \
	   libft/ft_strnequ.c \
	   libft/ft_strsub.c \
	   libft/ft_strjoin.c \
	   libft/ft_strtrim.c \
	   libft/ft_strsplit.c \
	   libft/ft_putchar.c \
	   libft/ft_putstr.c \
	   libft/ft_putendl.c \
	   libft/ft_putnbr.c \
	   libft/ft_putchar_fd.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_putendl_fd.c \
	   libft/ft_putnbr_fd.c \
	   libft/ft_lstnew.c \
	   libft/ft_lstdelone.c \
	   libft/ft_lstdel.c \
	   libft/ft_lstadd.c \
	   libft/ft_lstiter.c \
	   libft/ft_lstmap.c \
	   libft/ft_fill.c \
	   libft/ft_words.c \
	   libft/ft_letters.c \
	   libft/ft_malloc.c \
	   other/ft_strxcpy.c \
	   libft/ft_strndup.c \
	   other/ft_strnxdup.c \
	   libft/ft_strntrim.c \
	   other/ft_charfind.c \
	   other/ft_strxnew.c \
	   other/ft_charset.c \
	   other/ft_putwchar.c \
	   other/ft_putwstr.c \
	   other/ft_strwlen.c \
	   other/ft_wmemset.c \
	   other/ft_strwdup.c \
	   other/ft_charwset.c \
	   other/ft_strwxjoin.c \
	   other/ft_strwxcpy.c \
	   other/ft_strwdel.c \
	   other/ft_strwsub.c \
	   printf/ft_itoa.c \
	   printf/ft_decimal.c \
	   printf/ft_flags.c \
	   printf/ft_format.c \
	   printf/ft_format_simple.c \
	   printf/ft_gather_flags.c \
	   printf/ft_get_stuff.c \
	   printf/ft_hex.c \
	   printf/ft_init.c \
	   printf/ft_itoabase.c \
	   printf/ft_itoabasel.c \
	   printf/ft_itoau.c \
	   printf/ft_loader.c \
	   printf/ft_loaderu.c \
	   printf/ft_oct.c \
	   printf/ft_parse.c \
	   printf/ft_percent_found.c \
	   printf/ft_printf.c \
	   printf/ft_putbs.c \
	   printf/ft_reset_struct.c \
	   printf/ft_retrieve.c \
	   printf/ft_right_align.c \
	   printf/ft_size.c \
	   printf/ft_sizeu.c \
	   other/ft_strxjoin.c \
	   other/ft_strwxnew.c \
	   printf/ft_colors.c \
	   other/ft_strxdup.c \
	   libft/ft_itoal.c \
	   libft/ft_malloc.c \
	   libft/ft_sizel.c \
	   libft/ft_strdup2d.c \
	   libft/ft_strdel2d.c \
	   get_next_line/get_next_line.c \

HDIR =	./includes

%.o: %.c
	@gcc $(CFLAGS) -I$(HDIR) -c -o $@ $< -g

OBJS =	$(subst .c,.o,$(SRCS))

RM = @rm -f

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRCS) $?
	@ar -rc $(NAME) *.o $?
	@ranlib $(NAME) $?

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
