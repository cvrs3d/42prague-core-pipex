# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 14:22:54 by yustinov          #+#    #+#              #
#    Updated: 2024/11/07 19:10:26 by yustinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes
SRCS = mandatory/main.c mandatory/pipex.c tools/check_path.c tools/free_all.c \
	tools/ft_split.c tools/ft_strjoin.c tools/ft_strcpy.c tools/ft_strncmp.c \
	tools/print_error.c tools/ft_strlen.c

BONUS_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c tools/free_all.c \
	tools/check_path.c tools/ft_split.c tools/ft_strjoin.c tools/ft_strcpy.c \
	tools/ft_strncmp.c tools/print_error.c tools/ft_strlen.c bonus/main_bonus.c \
	bonus/pipex_bonus.c bonus/ft_itoa.c bonus/bonus_utils.c bonus/here_doc.c \
	
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
