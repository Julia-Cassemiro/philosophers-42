# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 13:47:55 by jgomes-c          #+#    #+#              #
#    Updated: 2022/05/12 13:47:55 by jgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_INC		=	include/

P_SRC		=	src/
P_OBJ		=	obj/

F_SRC		=	main.c dinner.c actions.c init.c do_philo.c utils.c
F_FILES		=	$(FILES)

FILES		=	$(addprefix $(P_SRC), $(F_SRC))
OBJ			=	$(addprefix $(P_OBJ), $(F_FILES:.c=.o))

INC			=	-I$(P_INC)
CC			=	gcc
RM			=	rm -rf
PMK			=	mkdir -p $(@D)
CFLAGS		=	-Wall -Wextra -Werror -pthread -fsanitize=address

NAME		=	philo

all:			$(NAME)

$(NAME):		$(OBJ)
				@echo '.o created and moved to obj folder'
				$(CC) $(CFLAGS) $(INC)   -o $(NAME) $(OBJ)
				@echo 'File(philo) created'


$(P_OBJ)%.o:	%.c
				$(PMK)
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@$(RM) $(P_OBJ)
				@echo 'All clean'

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re


