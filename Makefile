.PHONY : clean, fclean, re, $(NAME)

CC = clang++

OPTION = -c

FLAG = #-Wall -Werror -Wextra

NCURSE = -lncurses

NAME = ft_retro

SRC = main.cpp Executor.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(NCURSE)

$(OBJ): $(SRC)
	@$(CC) $(FLAG) $(OPTION) $(SRC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
