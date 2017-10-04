NAME		:=	tetris

CC		:=	g++
RM		:= 	rm -f

SRC_DIR 	:= 	src
OBJ_DIR 	:= 	obj
INC_DIR 	:= 	inc

LDFLAGS		:=	-I$(INC_DIR)
LDFLAGS		+=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CXXFLAGS	:=	-W -Wextra -Wall  -Werror
CXXFLAGS	+=	-g

SRC		:=	main.cpp\
			tetrimino.cpp\
			menu.cpp\
			game.cpp\
			tools.cpp

SRC 		:= 	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ 		:= 	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.cpp
			$(CC) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

all:			$(NAME)

$(NAME): 		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)

clean:
			$(RM) $(OBJ)
			$(RM) $(SRC_DIR)/*~
			$(RM) $(OBJ_DIR)/*~
			$(RM) $(INC_DIR)/*~
			$(RM) *~
			$(RM) $(SRC_DIR)/*\#
			$(RM) $(OBJ_DIR)/*\#
			$(RM) $(INC_DIR)/*\#
			$(RM) *\#

fclean: 		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 		all clean fclean re
