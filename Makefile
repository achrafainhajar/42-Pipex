SRC = pipex.c tools.c tools2_bonus.c 42-GNL/get_next_line.c 42-GNL/get_next_line_utils.c
SRC_BONUS = pipex_bonus.c tools.c tools2_bonus.c 42-GNL/get_next_line.c 42-GNL/get_next_line_utils.c
NAME = pipex
NAME_BONUS = pipex_bonus
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)
# @echo "✅✅✅"

bonus: $(NAME_BONUS)
$(NAME_BONUS):
	@gcc -Wall -Wextra -Werror $(SRC_BONUS)  -o $(NAME_BONUS)
# @echo "🎁🎁🎁"
clean:
	@rm -f $(NAME) 
fclean: clean
	@rm -f $(NAME_BONUS)
re: fclean all

.PHONY: all clean fclean re bonus