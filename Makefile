##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME	=	zappy_ai \
			zappy_gui \
			zappy_server

all: zappy_ai zappy_gui zappy_server

zappy_ai:
	make -C./ai

zappy_gui:
	make -C./gui

zappy_server:
	make -C./server

clean:
	find . -name "*.o" -delete
	find . -name "*~" -delete
	find . -name '#'*'#' -delete
	find . -name '*.gc*' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re zappy_ai zappy_gui zappy_server
