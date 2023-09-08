# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    template.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 20:24:35 by hyeonjan          #+#    #+#              #
#    Updated: 2023/03/23 20:24:36 by hyeonjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef NAME
	NAME = test
endif

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# CXXFLAGS = -fsanitize=address -fsanitize=undefined -g
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all : $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(addprefix $(OBJS_DIR), %.o) : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re

