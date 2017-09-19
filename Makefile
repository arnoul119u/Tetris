NAME		:=	projet

CC		:=	gcc
RM		:= 	rm -f

SRC_DIR 	:= 	src
OBJ_DIR 	:= 	obj
INC_DIR 	:= 	inc

LDFLAGS		:=	-I$(INC_DIR)

CFLAGS	:=	-W -Wextra -Wall  -Werror

#LIB		:=	-lpthread

SRC		:=	main.c

SRC 		:= 	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ 		:= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
													$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

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
