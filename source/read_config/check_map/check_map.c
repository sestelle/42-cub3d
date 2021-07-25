#include "cub3d.h"

void	check_map(char **map, t_double pos)
{
	char		**new_map;
	t_int		size;

	ft_bzero(&size, sizeof(t_int));
	new_map = recreate_map(map, &size);
	flood_fill(new_map, size, (int)pos.y, (int)pos.x);
	while (size.y--)
	{
		free(new_map[size.y]);
	}
	free(new_map);
}
