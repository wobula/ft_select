#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2015/05/15 19:47:33 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =				ft_select

CC =				gcc
CFLAGS =			-Wall -Werror -Wextra

SRCS =				srcs
INCLUDES =			includes
LIBFT =         	libft
LIBFT_INCLUDES =	$(LIBFT)/includes

INC_FLAGS =         -I $(INCLUDES) -I $(LIBFT_INCLUDES)
LIB_FLAGS =         -L $(LIBFT) -lftprintf -ltermcap\

COMPILED =			main.o \
					ft_putstrfd.o \
					user_input.o \
					print_text.o \

all: $(NAME)

$(NAME): $(COMPILED)
	@make re -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB_FLAGS) $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: $(SRCS)/%.c
	@$(CC) -c $(CFLAGS) $(INC_FLAGS) $< -o $@ -g

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
