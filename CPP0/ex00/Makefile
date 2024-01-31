# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 17:30:21 by bluzi             #+#    #+#              #
#    Updated: 2023/10/02 18:32:09 by bluzi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		=	megaphone

FLAGS		= 	-Wextra -Wall -Werror -std=c++98

SRCS		=	megaphone.cpp

OBJS		=	${SRCS:.cpp=.o}

all:			$(NAME)

%.o: 			%.cpp
				@c++ $(FLAGS) -o $@ -c $<

$(NAME): 		$(OBJS)
				@c++ $(OBJS) -o $(NAME)

clean:
				@rm -f $(OBJS)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all

.PHONY:			all, clean, fclean, re