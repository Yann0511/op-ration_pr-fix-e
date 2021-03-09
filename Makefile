NAME 	=	operation

CFLAGS	=	-g

HEADERS_DIR 	=	 $(shell find -name "*.h")

SRC 	=	 $(shell find  -name "*.c")

OBJ  	=	$(SRC:.c=.o)

all: 	$(NAME)

tableau:	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(HEADERS_DIRS) -DTABLEAU

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(HEADERS_DIRS)

clean:   $(OBJ)
	rm -f $(OBJ)

fclean:  clean
	rm -f $(NAME)

re: 	 fclean  all


