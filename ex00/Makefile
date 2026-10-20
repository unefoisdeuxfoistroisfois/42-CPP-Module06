.PHONY : all clean fclean re
.SILENT :

NAME			= convert
CXX     	= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC     	= main.cpp ScalarConverter.cpp
OBJ     	= $(SRC:.cpp=.o)
RM      	= rm -f

NC  	= \033[0m
GREEN	= \033[1;32m
RED		= \033[1;31m

all:    $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)COMPILATION SUCCESSFUL$(NC)\n"

clean:
	$(RM) $(OBJ)
	@printf "$(RED)REMOVING .O FILES$(NC)\n"

fclean: clean
	$(RM) $(NAME)
	@printf "$(RED)REMOVING BINARY$(NC)\n"

re: fclean all