# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/31 21:08:48 by pbongiov          #+#    #+#              #
#    Updated: 2026/03/31 23:55:52 by pbongiov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamond

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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