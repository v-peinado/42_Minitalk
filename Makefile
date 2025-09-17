# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 14:59:17 by vpeinado          #+#    #+#              #
#    Updated: 2025/09/17 20:24:18 by vpeinado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= server
NAME_C		= client

CC			= gcc
RM			= rm -fr
CFLAGS		= -Wall -Wextra -Werror

SRCS		= utils.c \
			  server.c

SRCS_C		= utils.c \
			  client.c

LIBFT_DIR	= libft/
LIBFT		= $(LIBFT_DIR)libft.a

OBJS		= $(SRCS:%.c=%.o)
OBJS_C		= $(SRCS_C:%.c=%.o)

# Agregar include path para libft
INCLUDES	= -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME) $(NAME_C)
	@echo "\033[0;32mServer: OK!\033[0m"
	@echo "\033[0;32mClient: OK!\033[0m"

$(LIBFT):
	@cd $(LIBFT_DIR) && make

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(NAME_C): $(OBJS_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_C)
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_C)
	@cd $(LIBFT_DIR) && make fclean
	@echo "\033[0;32mAll cleaned\033[0m"

re: fclean all

.PHONY: all clean fclean re