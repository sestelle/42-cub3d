#include "cub3d.h"

int	rendering(t_engine *engine)
{
	events(engine->cfg.map, &engine->cfg.plr, &engine->events);
	rendering_background(engine->cfg, &engine->img);
	rendering_walls(&engine->img, engine->cfg, engine->textures,
		engine->z_buffer);
	rendering_sprites(engine->cfg, engine);
	if (engine->cfg.save == true)
	{
		create_screenshot(engine->cfg.res, engine->img);
		exit(0);
	}
	mlx_put_image_to_window(engine->mlx.mlx, engine->mlx.win, engine->img.img,
		0, 0);
	return (0);
}
