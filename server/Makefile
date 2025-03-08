##
## EPITECH PROJECT, 2023
## zappy
## File description:
## Makefile
##

SRC_UTILS	=	check_args.c		\
				is_numeric.c		\
				send_msg.c			\
				free_lists.c		\
				player.c			\
				uuid.c				\
				user_id.c			\
				display_player.c	\
				server_loop_utils.c	\
				count_player.c		\

SRC_GAME	=	game_init.c				\
				add_player.c			\
				map.c					\
				spawn_ressources.c		\
				init_player.c			\
				remove_dead_players.c	\
				time_handler.c			\

SRC_BUFFER	=	init_buffer.c			\
				add_to_buffer.c			\
				rotate_buffer.c			\

SRC_COMMAND	=	check_command.c			\
				connection_sequence.c	\
				exec_command.c			\

AI_COMMAND	=	inventory.c			\
				move_commands.c		\
				look.c				\
				look_content.c		\
				look_direction.c	\
				take/deraumere.c	\
				take/take.c			\
				take/food.c			\
				take/linemate.c		\
				take/mendiane.c		\
				take/phiras.c		\
				take/sibur.c		\
				take/thystame.c		\
				connect_nbr.c		\
				eject.c				\
				eject_utils.c		\
				fork.c				\
				handle_death.c		\
				incantation.c		\
				check_incantation.c	\
				broadcast.c			\
				broadcast_utils.c	\

GUI_COMMAND	=	connect_gui.c		\
				player_position.c	\
				errors_command.c	\
				gui_map.c			\
				validity_checker.c	\
				time_unit.c			\
				teams.c				\
				send_event.c		\
				incantation_event.c	\
				inventory_command.c	\
				gui_player_level.c	\
				server_message.c	\
				time_unit_modif.c	\
				check_game_state.c	\
				broadcast_event.c	\

SRC_PARSING	=	parse.c			\
				free_parsing.c	\
				check_parsing.c	\

SRC_SIGNAL	=	signal_handler.c	\

SRC_MAIN	=	src/main.c	\

SRC	=	src/server.c				\
		src/socket_handler.c		\
		src/client_handler.c		\
		src/my_str_to_word_array.c	\
		src/exit_program.c			\
		src/reset_game.c			\
		$(addprefix src/utils/, $(SRC_UTILS))	\
		$(addprefix src/game/, $(SRC_GAME))	\
		$(addprefix src/buffer/, $(SRC_BUFFER))	\
		$(addprefix src/command_handling/, $(SRC_COMMAND))	\
		$(addprefix src/parsing/, $(SRC_PARSING))	\
		$(addprefix src/ai_command/, $(AI_COMMAND))	\
		$(addprefix src/gui_command/, $(GUI_COMMAND))	\
		$(addprefix src/signal/, $(SRC_SIGNAL))	\

OBJ	=	$(SRC:.c=.o)	\
		$(SRC_MAIN:.c=.o)

TEST	=	tests/incantation_test.c		\
			tests/nb_connect.c				\
			tests/inventory_test.c			\
			tests/forward_test.c			\
			tests/check_valid.c				\
			tests/look_test.c				\
			tests/eject_test.c				\
			tests/take_set_tests.c			\
			tests/fork_test.c				\
			tests/broadcast_test.c			\
			tests/handle_death_tests.c		\
			tests/buffer_tests.c			\
			tests/client_handler_tests.c	\
			tests/command_handling_tests.c	\
			tests/check_connection_tests.c	\
			tests/exec_command_tests.c		\
			tests/exit_program_tests.c		\
			tests/game_init_tests.c			\
			tests/players_tests.c			\
			tests/time_handler_tests.c		\
			tests/server_tests.c			\
			tests/utils_tests.c				\

DEBUG = -W -Wall -Wextra -Werror

NAME	=	zappy_server

CPPFLAGS	=	-I./include

LDLIBS	=	-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS)
	mv $(NAME) ../$(NAME)
clean:
	rm -f $(OBJ);
	rm -f *~;
	rm -f *.gc*
	rm -f vgcore*

fclean : clean
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

debug: fclean
	gcc -o $(NAME) $(SRC) $(SRC_MAIN) $(CPPFLAGS) $(DEBUG) -ggdb3 $(LDLIBS)

tests_run: clean
	gcc -o unit_tests $(TEST) $(SRC) $(CPPFLAGS) \
	-lcriterion --coverage $(LDLIBS)
	./unit_tests

.PHONY: tests_run debug re fclean all clean
