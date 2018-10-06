.PHONY : clean, fclean, re, $(NAME)

CC = clang++

OPTION = -c -I./includes

FLAG = #-Wall -Werror -Wextra

NCURSE = -lncurses

NAME = ft_retro

SRC = main.cpp Executor.cpp Player.cpp Ufo.cpp Laser.cpp Enemy.cpp Weak.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(NCURSE)

$(OBJ): $(addprefix srcs/, $(SRC))
	@$(CC) $(FLAG) $(OPTION) $(addprefix srcs/, $(SRC))

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
