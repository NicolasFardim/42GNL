#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main() {
	char	*read1;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	while ((read1 = get_next_line(fd)) != NULL)
	{
		printf("%s", read1);
		free(read1);
	}
	close(fd);
}
