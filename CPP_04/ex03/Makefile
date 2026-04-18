# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 00:15:35 by pbongiov          #+#    #+#              #
#    Updated: 2026/04/18 16:10:01 by pbongiov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

SRCS = main.cpp Character.cpp AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98 -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re