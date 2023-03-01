# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:15:47 by smayrand          #+#    #+#              #
#    Updated: 2023/02/22 15:27:34 by smayrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = '\033[32m'
NONE = '\033[0m'

NAME = minishell

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
MSFLAGS = -lreadline -lncurses
AR = ar -rcs

RM = rm -f

SRCS = minishell.c\
./src/mini_cd.c\
./src/mini_checker.c\
./src/mini_echo.c\
./src/mini_env.c\
./src/mini_execution.c\
./src/mini_export.c\
./src/mini_heredoc.c\
./src/mini_lexer.c\
./src/mini_open.c\
./src/mini_path.c\
./src/mini_reader.c\
./src/mini_signal.c\
./src/mini_unset.c\
./src/mini_utils.c\
./src/mini_utils2.c\
./src/the_parser.c\

LIBFT_A 	= ./lib/libft/libft.a
LIBRL_A 	= ./lib/libreadline.a ./lib/libhistory.a
OBJS		= $(SRCS:.c=.o)

all: alibft $(NAME)
	@echo " ==============="
	@echo $(GREEN) "FULLY	COMPILED" $(NONE)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MSFLAGS) $(LIBFT_A) $(LIBRL_A) $(OBJS) -o $(NAME)
	
alibft:
	@(cd ./lib/libft && make all)
	@echo $(GREEN) "LIBFT COMPILED" $(NONE)
	@(cd ..)

libftclean:
	@(cd ./lib/libft && make fclean)
	@echo $(GREEN) "LIBFT CLEANED" $(NONE)
	@(cd ..)
	
clean:
	@$(RM) $(OBJS)

fclean: clean libftclean
	@$(RM) $(NAME)
	@echo $(GREEN) "FULLY	CLEANED" $(NONE)
	
re: fclean all