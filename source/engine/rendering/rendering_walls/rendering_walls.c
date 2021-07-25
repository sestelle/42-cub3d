#include "cub3d.h"

void	rendering_walls(t_img *img, t_cfg cfg, t_textures textures,
					double *buffer)
{
	t_walls	walls;
	t_plr	plr;
	t_res	res;
	int		*texture;
	int		x;

	res = cfg.res;
	plr = cfg.plr;
	x = 0;
	while (x < res.width)
	{
		calculation_1(&walls, plr, x, res);
		dda_alg(&walls, plr, cfg.map);
		calculation_2(&walls, plr, res);
		calculation_3(&walls, plr, res);
		tex_num(walls.side, &walls, &texture, &textures);
		draw_textures(&walls, img, texture, x);
		buffer[x] = walls.perp_wall_dist;
		x++;
	}
}
