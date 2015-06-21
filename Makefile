
SRC_NAME = main.cpp \
		   AObject.class.cpp \
		   AShip.class.cpp \
		   ASpace.class.cpp \
		   AsteroideObject.class.cpp \
		   BlockObject.class.cpp \
		   Character.class.cpp \
		   Gameplay.cpp \
		   TirObject.class.cpp \
		   VBShip.class.cpp \
		   VLShip.class.cpp
OBJ_NAME = $(SRC_NAME:.cpp=.o)
NAME = ft_retro
SRC_PATH = ./
OBJ_PATH = ./
INC_PATH = ./
CFLAGS = -Wall -Werror -Wextra
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

$(NAME): $(OBJ)
	clang++ $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -lncurses

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	clang++ $(CFLAGS) $(INC) -o $@ -c $< 

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -fv $(NAME)

re: fclean all

.PHONY: all clean fclean re

