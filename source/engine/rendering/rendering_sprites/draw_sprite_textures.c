#include "cub3d.h"

static void	cycle(t_sprites *sprites, int *texture, t_engine *engine, \
				int stripe)
{
	int	y;
	int	d;

	y = sprites->draw_start_y;
	while (y < sprites->draw_end_y)
	{
		d = (y) * 256 - engine->cfg.res.height * 128 + sprites \
			->sprite_height * 128;
		sprites->tex_y = ((d * TEX_HEIGHT) / sprites \
			->sprite_height) / 256;
		sprites->color = texture[TEX_WIDTH * sprites \
			->tex_y + sprites->tex_x];
		if ((sprites->color & 0x00FFFFFF) != 0)
			pixel_put(&engine->img, stripe, y, sprites->color);
		y++;
	}
}

void	draw_sprite_textures(t_sprites *sprites, int *texture, t_engine *engine)
{
	int	stripe;

	stripe = sprites->draw_start_x;
	while (stripe < sprites->draw_end_x)
	{
		sprites->tex_x = (int)(256 * (stripe - (-(sprites->sprite_width) \
			/ 2 + sprites->sprite_screen_x)) * TEX_WIDTH / sprites-> \
				sprite_width) / 256;
		if (sprites->transform.y > 0 && stripe > 0 && stripe < engine->cfg \
			.res.width && sprites->transform.y < engine->z_buffer[stripe])
		{
			cycle(sprites, texture, engine, stripe);
		}
		stripe++;
	}
}
