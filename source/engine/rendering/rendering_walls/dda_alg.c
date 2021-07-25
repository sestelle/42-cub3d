#include "cub3d.h"

static void	dda_prep(t_walls *walls, t_plr plr)
{
	if (walls->ray.x < 0)
	{
		walls->step.x = -1;
		walls->side_dist.x = (plr.pos.x - walls->map.x) * walls->delta_dist.x;
	}
	else
	{
		walls->step.x = 1;
		walls->side_dist.x = (walls->map.x + 1.0 - plr
				.pos.x) * walls->delta_dist.x;
	}
	if (walls->ray.y < 0)
	{
		walls->step.y = -1;
		walls->side_dist.y = (plr.pos.y - walls->map.y) * walls->delta_dist.y;
	}
	else
	{
		walls->step.y = 1;
		walls->side_dist.y = (walls->map.y + 1.0 - plr.pos.y) * walls
			->delta_dist.y;
	}
}

static void	dda_perf(t_walls *walls, char **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (walls->side_dist.x < walls->side_dist.y)
		{
			walls->side_dist.x += walls->delta_dist.x;
			walls->map.x += walls->step.x;
			walls->side = 0;
		}
		else
		{
			walls->side_dist.y += walls->delta_dist.y;
			walls->map.y += walls->step.y;
			walls->side = 1;
		}
		if (map[walls->map.x][walls->map.y] == '1')
			hit = 1;
	}
}

void	dda_alg(t_walls *walls, t_plr plr, char **map)
{
	dda_prep(walls, plr);
	dda_perf(walls, map);
}
