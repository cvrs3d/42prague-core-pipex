# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 14:22:54 by yustinov          #+#    #+#              #
#    Updated: 2024/11/02 16:10:46 by yustinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes
SRCS = src/pipex.c src/ft_split.c src/ft_strncmp.c src/ft_strlen.c src/ft_strcat.c src/ft_strchr.c src/ft_strdup.c \
       src/main.c src/pipex_utils.c src/ft_strcpy.c src/ft_strncpy.c src/here_doc.c src/ft_io.c src/ft_strjoin.c \
	   src/get_next_line.c src/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	$(RM) $(OBJS) 

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
