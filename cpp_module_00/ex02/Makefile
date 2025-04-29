NAME		=	account

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Account.cpp tests.cpp
OBJ			=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "\033[32mCompiled using\033[0m\n\n\t<<< c++ -Wall -Wextra -Werror -std=c++98 >>>\n"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[34mCleaned\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mCleaned ALL\033[0m\n"

re: fclean all

.PHONY: all clean fclean re