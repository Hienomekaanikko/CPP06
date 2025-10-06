CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++20
SRC = main.cpp ScalarConverter.cpp
OBJ = $(SRC:.cpp=.o)
NAME = converter
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
