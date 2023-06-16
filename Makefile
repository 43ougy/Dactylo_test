CC = @gcc
RM = @rm -f
NAME = dact
FLAG = -Wall -Wextra -Werror -g -o $(NAME)
SRC = dactylo.c		\
	SRC/error.c		\
	SRC/file.c		\
	SRC/split.c		\
	SRC/text.c		\
	SRC/utils.c		\
	SRC/word.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) tmp.txt

re : fclean all
