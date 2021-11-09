# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 12:16:46 by tnard             #+#    #+#              #
#    Updated: 2021/11/09 16:36:36 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c utils/ft_putchar.c utils/ft_putnbr_base.c utils/ft_putnbr.c utils/ft_putstr.c utils/ft_putmemory.c

#LIBFT = ./libft/libft.a	

INCLUDES = #-Ift_print.h

NAME = libftprintf.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c ft_printf.h
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)utils
	echo "Compil: $<"
	$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
#	$(MAKE) bonus -C ./libft
#	cp libft/libft.a $(NAME)
	ar r $(NAME) $(OBJECTS_PREFIXED)
	echo "libftprintf.a compiled !"

all: $(NAME)

clean:
#	$(MAKE) clean -C ./libft
	rm -rf $(OBJS_DIR)

fclean: clean
#	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus