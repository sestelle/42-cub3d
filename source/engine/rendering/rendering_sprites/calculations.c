#include "cub3d.h"

void	calculations_sprites_1(t_sprites *sprites, t_plr plr, char **map)
{
	int	i;

	find_sprites(sprites, map);
	sprites->sprite_order = (int *)malloc(sizeof(int) * sprites->count);
	sprites->sprite_distance = (double *)malloc(sizeof(double) * sprites \
		->count);
	i = 0;
	while (i < sprites->count)
	{
		sprites->sprite_order[i] = i;
		sprites->sprite_distance[i] = ((plr.pos.x - sprites->sprites[i] \
			.x) * (plr.pos.x - sprites->sprites[i].x) + (plr.pos \
			.y - sprites->sprites[i].y) * (plr.pos.y - sprites->sprites[i].y));
		i++;
	}
	sort_sprites(sprites->sprite_order, sprites->sprite_distance, \
		sprites->count);
}

void	calculations_sprites_2(t_sprites *sprites, t_res res, t_plr plr, int i)
{
	sprites->sprite.x = sprites->sprites[sprites->sprite_order[i]].x - plr \
		.pos.x;
	sprites->sprite.y = sprites->sprites[sprites->sprite_order[i]].y - plr \
		.pos.y;
	sprites->inv_det = 1.0 / (plr.plane.x * plr.dir.y - plr \
		.dir.x * plr.plane.y);
	sprites->transform.x = sprites->inv_det * (plr.dir.y * sprites \
		->sprite.x - plr.dir.x * sprites->sprite.y);
	sprites->transform.y = sprites->inv_det * (-(plr.plane \
		.y) * sprites->sprite.x + plr.plane.x * sprites->sprite.y);
	sprites->sprite_screen_x = (int)((res.width / 2) * (1 \
		+ sprites->transform.x / sprites->transform.y));
	sprites->sprite_height = abs((int)(res.height / sprites->transform.y));
}

void	calculations_sprites_3(t_sprites *sprites, t_res res)
{
	sprites->draw_start_y = -(sprites->sprite_height) / 2 + res.height / 2;
	if (sprites->draw_start_y < 0)
		sprites->draw_start_y = 0;
	sprites->draw_end_y = sprites->sprite_height / 2 + res.height / 2;
	if (sprites->draw_end_y >= res.height)
		sprites->draw_end_y = res.height - 1;
	sprites->sprite_width = abs((int)(res.height / sprites->transform.y));
	sprites->draw_start_x = -(sprites->sprite_width) / 2 + \
			sprites->sprite_screen_x;
	if (sprites->draw_start_x < 0)
		sprites->draw_start_x = 0;
	sprites->draw_end_x = sprites->sprite_width / 2 + sprites->sprite_screen_x;
	if (sprites->draw_end_x >= res.width)
		sprites->draw_end_x = res.width - 1;
}
