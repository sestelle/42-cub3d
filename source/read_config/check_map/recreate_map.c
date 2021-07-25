#include "cub3d.h"

static void	get_size(t_int *size, char **map)
{
	static t_int	point;

	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			point.x += 1;
			if (point.x > size->x)
				size->x = point.x;
		}
		point.y += 1;
	}
	size->y = point.y;
}

static void	cpy_map(char **map, char **new_map)
{
	static int	i;
	int			j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				new_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

char	**recreate_map(char **map, t_int *size)
{
	char			**new_map;
	int				i;

	new_map = NULL;
	get_size(size, map);
	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (size->y + 1));
	new_map[size->y] = 0;
	while (i < size->y)
	{
		new_map[i] = (char *)malloc(sizeof(char) * (size->x + 1));
		ft_memset(new_map[i], '0', size->x);
		new_map[i][size->x] = '\0';
		i++;
	}
	cpy_map(map, new_map);
	return (new_map);
}
