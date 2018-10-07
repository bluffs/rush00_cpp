.PHONY : all, clean, fclean, re, $(NAME)

STD  = c++98
CXX  = clang++ -std=$(STD)
LDXX = clang++ -std=$(STD)
RM   = rm -rf

INC_DIR = includes
SRC_DIR = srcs

CFLAGS  = -Wall -Wextra -Werror
LDFLAGS =
LDLIBS  = ncurses

ifneq ($(DEBUG),)
  BUILD_DIR = build/debug
  CFLAGS  += -g3 -O0 -fsanitize=address
  LDFLAGS += -fsanitize=address
  NAME_SUFFIX = -debug
else
  BUILD_DIR = build/release
  CFLAGS  += -flto -O2
  LDFLAGS += -flto
endif

NAME      = ft_retro
NAME_BIN := $(NAME)$(NAME_SUFFIX)

INC = $(INC_DIR)
SRC = main.cpp \
      Executor.cpp Player.cpp Ufo.cpp Laser.cpp Enemy.cpp Weak.cpp \
      Spawner.cpp Background.cpp Star.cpp Asteroid.cpp EnemyLaser.cpp \
	  Boss.cpp

V ?= @

all: $(NAME_BIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "  CXX     $(notdir $<)"
	@mkdir -p $(dir $@)
	$(V)$(CXX) $< -c $(CFLAGS) $(addprefix -I,$(INC)) \
		$(addprefix -D,$(DEF)) -MMD -MF $(@:.o=.d) -o $@

$(NAME_BIN): $(SRC:%.cpp=$(BUILD_DIR)/%.o)
	@echo "  LDXX    $(notdir $@)"
	$(V)$(LDXX) $^ $(LDFLAGS) $(addprefix -l,$(LDLIBS)) -o $@

clean:
	@$(RM) $(BUILD_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

-include $(SRC:%.cpp=$(BUILD_DIR)/%.d)
