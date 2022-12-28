SRC = pipex.c tools.c tools2.c 42-GNL/get_next_line.c 42-GNL/get_next_line_utils.c
SRC_BONUS = pipex_bonus.c tools.c tools2.c 42-GNL/get_next_line.c 42-GNL/get_next_line_utils.c
.PHONY: all bonus clean fclean re
NAME = pipex
NAME_BONUS = pipex_bonus
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)
$(NAME):
		@gcc -Wall -Wextra -Werror $(SRC) -o pipex
bonus:
	@gcc -Wall -Wextra -Werror $(SRC_BONUS) -o pipex
clean:
	@rm -f $(OBJECT) $(OBJECT_BONUS)
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
re: fclean all bonus