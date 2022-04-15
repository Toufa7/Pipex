# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otoufah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 15:16:31 by otoufah           #+#    #+#              #
#    Updated: 2022/04/13 17:03:21 by otoufah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

CC = gcc

AR = ar rcs

FUNCTIONS =	my_library/ft_strsjoin.c\
			my_library/ft_strlen.c\
			my_library/ft_strstr.c\
			my_library/ft_split.c\
			my_library/ft_strlcpy.c\
			cmd_path.c\
			find_path.c\
			data_flow.c\
			first_cmd.c\
			second_cmd.c\
			errors_handling.c\

OBJECTS =	$(FUNCTIONS:.c=.o)

all : $(NAME)


$(NAME) :	$(OBJECTS)
			$(CC) $(CFLAGS) $(OBJECTS) pipex.c -o $(NAME)

clean :
			$(RM)	$(OBJECTS)
	
fclean : clean
			$(RM) $(NAME) $(BONUS)

re : fclean all
