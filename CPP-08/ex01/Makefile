# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 14:11:08 by lmiguel-          #+#    #+#              #
#    Updated: 2025/05/16 15:43:43 by lmiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Algorithm1

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp Span.cpp

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