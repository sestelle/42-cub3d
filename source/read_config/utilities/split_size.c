#include "cub3d.h"

int	split_size(char **split)
{
	int	size;

	size = 0;
	while (*split)
	{
		size += 1;
		split++;
	}
	return (size);
}
