#include "get_next_line.h"


int	main() {
	char	*read1;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	read1 = get_next_line(fd);
	printf("%s", read1);
	free(read1);
	close(fd);
}
