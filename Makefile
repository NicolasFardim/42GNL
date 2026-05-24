
OUT  = bin
SRCS = main.c get_next_line.c get_next_line_utils.c

all: run

run: $(SRCS)
	gcc -Wall -Werror -Wextra -g $^ -o $(OUT)

simple: $(SRCS)
	gcc $^ -o $(OUT)

sanitize: $(SRCS)
	gcc -Wall -Werror -Wextra -fsanitize=address $^ -o $(OUT)

leaks: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./$(OUT)

clean:
	rm -f $(OUT)
