#include "cub3d.h"

void	tex_num(int side, t_walls *walls, int **texture, t_textures *textures)
{
	if (side == 0 && walls->ray.x < 0)
	{
		*texture = textures->north;
	}
	else if (side == 0)
	{
		*texture = textures->south;
	}
	else if (side == 1 && walls->ray.y < 0)
	{
		*texture = textures->west;
	}
	else if (side == 1)
	{
		*texture = textures->east;
	}
}
