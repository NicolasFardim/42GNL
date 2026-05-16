
OUT  = bin
SRCS = main.c get_next_line.c

all: run

run: $(SRCS)
	gcc -Wall -Werror -Wextra -g $^ -o $(OUT)

simple: $(SRCS)
	gcc $^ -o $(OUT)

sanitize: $(SRCS)
	gcc -Wall -Werror -Wextra -fsanitize=address $^ -o stest

leaks: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./$(OUT)

clean:
	rm -f $(OUT)

fclean:
	rm -f stest
