# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaltea <amaltea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 19:52:44 by amaltea           #+#    #+#              #
#    Updated: 2025/06/27 01:25:47 by amaltea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	utils/errors.c\
				utils/exec.c\
				utils/get_path.c\
				pipex.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -I./includes -I$(LIBFT_DIR)#-fsanitize=address,leak,undefined

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

norm:
	norminette $(SRCS) pipex.h

clean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
