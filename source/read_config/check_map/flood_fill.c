#include "cub3d.h"

void	flood_fill(char **map, t_int size, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'x')
		return ;
	if (map[y][x] == ' ' || ((y == 0 || x == 0 || x == size.x - 1 \
		|| y == size.y - 1) && map[y][x] != 1))
		print_error("Invalid map");
	if (map[y][x] == '0')
		map[y][x] = 'x';
	flood_fill(map, size, x + 1, y);
	flood_fill(map, size, x - 1, y);
	flood_fill(map, size, x, y + 1);
	flood_fill(map, size, x, y - 1);
	flood_fill(map, size, x + 1, y + 1);
	flood_fill(map, size, x + 1, y - 1);
	flood_fill(map, size, x - 1, y - 1);
	flood_fill(map, size, x - 1, y + 1);
}
