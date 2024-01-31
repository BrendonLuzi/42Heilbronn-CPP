
NAME		=	bureaucracy

FLAGS		= 	-Wextra -Wall -Werror -std=c++98

SRCS		=	main.cpp					\
				Bureaucrat.cpp				\
				AForm.cpp					\
				ShrubberyCreationForm.cpp	\
				PresidentialPardonForm.cpp	\
				RobotomyRequestForm.cpp

OBJS		=	${SRCS:.cpp=.o}

all:		$(NAME)


%.o: 		%.cpp
				c++ $(FLAGS) -o $@ -c $<

$(NAME): 		$(OBJS)
				c++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
				@rm -f $(OBJS)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all

.PHONY:			all, clean, fclean, re