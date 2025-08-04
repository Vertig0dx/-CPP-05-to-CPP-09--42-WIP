# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 18:39:02 by lmiguel-          #+#    #+#              #
#    Updated: 2025/03/25 18:25:43 by lmiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat0

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp Bureaucrat.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re