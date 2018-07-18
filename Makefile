COMPILER = gcc
FLAGS = -Wall -Wextra -Werror

COLOR="\033[95m"

SRC = vector.c string.c anytos.c

SRC_REL = $(SRC) #$(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(SRC:.c=.o)

NAME = dsalgo.a

all: $(NAME)

mprint:
	@echo $(COLOR)"make" $(NAME) "\033[0m"
clprint:
	@echo $(COLOR)"clean" $(NAME) "\033[0m"
clfprint:
	@echo $(COLOR)"fclean" $(NAME) "\033[0m"

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC_REL) $(PRINT_MAKE)
	@$(MAKE) mprint
	$(COMPILER) $(FLAGS) -c $(SRC_REL) -I./include

clean:
	@$(MAKE) clprint
	rm -rf $(OBJ)

fclean: clean
	@$(MAKE) clfprint
	rm -rf $(NAME) $(LIB_NAME)

main: $(NAME)
	@$(COMPILER) $(FLAGS) -o a.out main.c $(NAME) -I ./include
	@./a.out
	@rm a.out
test: $(NAME)
	$(COMPILER) $(FLAGS) -o test test.c $(NAME) -I ./include
	./test
	echo $?
	rm test

re: fclean all

.PHONY: clean fclean re test
