SRC	=	main

NAME	=	zappy_ai

all:	$(NAME)

$(NAME):
	cp $(SRC) ../$(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean

tests_run:
	@if [ -n "$$PYTHONPATH" ]; then \
        pytest --cov-report term-missing --cov=src tests; \
    else \
        echo "Set the PYTHONPATH environment variable in project root, to test"; \
    fi

re:	fclean all

.PHONY: all clean fclean tests_run re
