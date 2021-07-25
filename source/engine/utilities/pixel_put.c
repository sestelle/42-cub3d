#include "cub3d.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = (char *)img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
