#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libfts.h"

void	test_strlen(void)
{
}

int	main(int ac, char **av)
{
	char	*str;

	str = calloc(1, 50);
	test_strlen();
	printf("%ld\n", ft_read(0, str, 4));
	printf("%s", str);
	return (0);
}
