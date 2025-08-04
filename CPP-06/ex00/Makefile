# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 14:02:23 by lmiguel-          #+#    #+#              #
#    Updated: 2025/04/07 14:05:07 by lmiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Conversion0

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp ScalarConverter.cpp

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