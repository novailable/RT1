#include "rt1.h"

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.rt", O_RDONLY);
	printf("fd : %d\n", fd);
	line = gnl(fd);
	printf("line : %s\n", line);
	free(line);
	close(fd);	
}