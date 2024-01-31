# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 17:30:21 by bluzi             #+#    #+#              #
#    Updated: 2023/10/07 15:15:56 by bluzi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		=	violence

FLAGS		= 	-Wextra -Wall -Werror -std=c++98

SRCS		=	main.cpp		\
				Weapon.cpp		\
				HumanA.cpp		\
				HumanB.cpp

OBJS		=	${SRCS:.cpp=.o}

all:		$(NAME)


%.o: 		%.cpp
				@c++ $(FLAGS) -o $@ -c $<

$(NAME): 		$(OBJS)
				@c++ $(OBJS) -o $(NAME)

clean:
				@rm -f $(OBJS)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all

.PHONY:			all, clean, fclean, re