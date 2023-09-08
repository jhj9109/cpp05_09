ifndef NAME
	NAME = test
endif

ifndef SRCS
	SRCS =
endif

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
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

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re