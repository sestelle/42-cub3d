#include "engine.h"

static void	rendering_ceiling(t_cfg cfg, t_img *img)
{
	t_int	point;
	t_res	res;
	int		color;

	res = cfg.res;
	color = cfg.ceiling;
	point.x = 0;
	while (point.x < res.width)
	{
		point.y = 0;
		while (point.y < res.height / 2)
		{
			pixel_put(img, point.x, point.y, color);
			point.y += 1;
		}
		point.x += 1;
	}
}

static void	rendering_floor(t_cfg cfg, t_img *img)
{
	t_int	point;
	t_res	res;
	int		color;

	res = cfg.res;
	color = cfg.floor;
	point.x = 0;
	while (point.x < res.width)
	{
		point.y = res.height / 2;
		while (point.y < res.height)
		{
			pixel_put(img, point.x, point.y, color);
			point.y += 1;
		}
		point.x += 1;
	}
}

void	rendering_background(t_cfg cfg, t_img *img)
{
	rendering_ceiling(cfg, img);
	rendering_floor(cfg, img);
}
