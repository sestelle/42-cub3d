#include "cub3d.h"

void	draw_textures(t_walls *walls, t_img *img, int *texture, int x)
{
	int		y;

	y = walls->draw_start;
	while (y < walls->draw_end)
	{
		walls->tex_y = (int)walls->tex_pos & (TEX_WIDTH - 1);
		walls->tex_pos += walls->_step;
		walls->color = texture[TEX_HEIGHT * walls->tex_y + walls->tex_x];
		pixel_put(img, x, y, walls->color);
		y++;
	}
}
