# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by krochefo          #+#    #+#              #
#    Updated: 2022/09/13 20:43:13 by krochefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server


SRCS_SERVER = server.c includes/ft_putnbr_fd.c includes/ft_putstr_fd.c \
				includes/ft_strlen.c
SRCS_CLIENT = client.c includes/ft_atoi.c includes/ft_putendl_fd.c includes/ft_strlen.c \
				includes/ft_isdigit.c includes/ft_putstr_fd.c
SRCS_PATH = ./
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

AR = ar
CC = gcc
RM = rm -f

ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

REMOVE = rm -rf
COMMIT = $(shell date "+%d %B %T")

all: $(NAME)
	@echo "\033[32m       ██████        ██████      \033[0m"                            
	@echo "\033[32m     ██▒▒░░░░██    ██░░░░▒▒██    \033[0m"                            
	@echo "\033[32m     ██\033[96m████████████████████\033[32m██    \033[0m"                            
	@echo "\033[32m   ████▒▒\033[96m██████\033[32m▒▒▒▒\033[96m██████\033[32m▒▒████  \033[0m"                            
	@echo "\033[32m ██▒▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▒▒▒▒▒▒▒██ \033[0m    DONE!"                            
	@echo "\033[32m ██▒▒▒▒▒▒░░░░██░░░░██░░░░▒▒▒▒▒▒██\033[0m     Minitalk Compiled!"                            
	@echo "\033[32m ██▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒▒▒▒▒▒▒██\033[0m"                            
	@echo "\033[32m   ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████  \033[0m"                            
	@echo "\033[32m       ████▒▒▒▒▒▒▒▒▒▒▒▒████       \033[0m"                           
	@echo "\033[32m   ████  ████████████████  ████   \033[0m"                           
	@echo "\033[32m ██░░▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒░░██\033[0m"                            
	@echo "\033[32m ██▒▒▒▒▒▒██▒▒██▒▒▒▒██▒▒██▒▒▒▒▒▒██\033[0m"                            
	@echo "\033[32m ██▒▒██▒▒██▒▒██░░░░██▒▒██▒▒██▒▒██\033[0m"                            
	@echo "\033[32m   ██▒▒████▒▒████████▒▒████▒▒██  \033[0m"                            
	@echo "\033[32m     ██▒▒██░░░░████░░░░██▒▒██     \033[0m"                           
	@echo "\033[32m   ████████████████████████████   \033[0m"  


$(NAME):

client:
	@$(CC) $(SRCS_CLIENT) $(CFLAGS) -o client

server:
	@$(CC) $(SRCS_SERVER) $(CFLAGS) -o server

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

