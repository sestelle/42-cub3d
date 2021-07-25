#include "cub3d.h"

void	rendering_sprites(t_cfg cfg, t_engine *engine)
{
	t_sprites	sprites;
	t_plr		plr;
	t_res		res;
	int			i;

	plr = cfg.plr;
	res = cfg.res;
	calculations_sprites_1(&sprites, plr, cfg.map);
	i = 0;
	while (i < sprites.count)
	{
		calculations_sprites_2(&sprites, res, plr, i);
		calculations_sprites_3(&sprites, res);
		draw_sprite_textures(&sprites, engine->textures.sprite, engine);
		i++;
	}
	free(sprites.sprites);
	free(sprites.sprite_order);
	free(sprites.sprite_distance);
}
