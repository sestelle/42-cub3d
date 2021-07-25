#include "cub3d.h"

static void	count(t_sprites *sprites, char **map)
{
	t_int	point;
	int		i;

	i = 0;
	sprites->count = 0;
	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			if (map[point.y][point.x] == '2')
				sprites->count += 1;
			point.x += 1;
		}
		point.y += 1;
	}
}

static void	read_sprites(t_sprites *sprites, char **map)
{
	t_int	point;
	int		i;

	i = 0;
	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			if (map[point.y][point.x] == '2')
			{
				sprites->sprites[i].x = point.y + 0.5;
				sprites->sprites[i].y = point.x + 0.5;
				i++;
			}
			point.x += 1;
		}
		point.y += 1;
	}
}

void	find_sprites(t_sprites *sprites, char **map)
{
	count(sprites, map);
	sprites->sprites = (t_double *)malloc(sizeof(t_double) * \
		sprites->count);
	if (!sprites->sprites)
		print_error("Malloc error");
	read_sprites(sprites, map);
}
