NAME    = Interface

CXX     = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98

SRCS    =	AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

OBJS    = $(SRCS:.cpp=.o)
HEADER  =	AMateria.hpp ICharacter.hpp IMateriaSource.hpp \
            Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\033[32mCompiled using\033[0m\n\n\t<<< c++ -Wall -Wextra -Werror -std=c++98 >>>\n"

%.o: %.cpp $(HEADER)
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "\033[34mCleaned\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mCleaned ALL\033[0m\n"

re: fclean all

.PHONY: all clean fclean re