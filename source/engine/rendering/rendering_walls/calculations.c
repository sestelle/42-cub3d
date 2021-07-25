#include "cub3d.h"

void	calculation_1(t_walls *walls, t_plr plr, int x, t_res res)
{
	walls->camera_x = 2 * x / (double) res.width - 1;
	walls->ray.x = plr.dir.x + plr.plane.x * walls->camera_x;
	walls->ray.y = plr.dir.y + plr.plane.y * walls->camera_x;
	walls->map.x = (int) plr.pos.x;
	walls->map.y = (int) plr.pos.y;
	walls->delta_dist.x = fabs(1 / walls->ray.x);
	walls->delta_dist.y = fabs(1 / walls->ray.y);
}

void	calculation_2(t_walls *walls, t_plr plr, t_res res)
{
	if (walls->side == 0)
		walls->perp_wall_dist = (walls
				->map.x - plr.pos.x + (1 - walls->step.x) / 2) / walls->ray.x;
	else
		walls->perp_wall_dist = (walls->map.y - plr.pos.y + (1 - walls
					->step.y) / 2) / walls->ray.y;
	walls->line_height = (int)(res.height / walls->perp_wall_dist);
	walls->draw_start = -(walls->line_height) / 2 + res.height / 2;
	if (walls->draw_start < 0)
		walls->draw_start = 0;
	walls->draw_end = walls->line_height / 2 + res.height / 2;
	if (walls->draw_end >= res.height)
		walls->draw_end = res.height;
}

void	calculation_3(t_walls *walls, t_plr plr, t_res res)
{
	if (walls->side == 0)
		walls->wall_x = plr.pos.y + walls->perp_wall_dist * walls->ray.y;
	else
		walls->wall_x = plr.pos.x + walls->perp_wall_dist * walls->ray.x;
	walls->wall_x -= floor(walls->wall_x);
	walls->tex_x = (int)(walls->wall_x * (double) 64);
	if (walls->side == 0 && walls->ray.x > 0)
		walls->tex_x = 64 - walls->tex_x - 1;
	if (walls->side == 1 && walls->ray.y < 0)
		walls->tex_x = 64 - walls->tex_x - 1;
	walls->_step = 1.0 * 64 / walls->line_height;
	walls->tex_pos = (walls
			->draw_start - res.height / 2 + walls->line_height / 2) \
				* walls->_step;
}
