#include "cub3d.h"

static void	malloc_textures(t_textures *textures)
{
	textures->north = (int *)malloc(sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
	if (textures->north == NULL)
		print_error("Malloc error");
	textures->south = (int *)malloc(sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
	if (textures->south == NULL)
		print_error("Malloc error");
	textures->west = (int *)malloc(sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
	if (textures->west == NULL)
		print_error("Malloc error");
	textures->east = (int *)malloc(sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
	if (textures->east == NULL)
		print_error("Malloc error");
	textures->sprite = (int *)malloc(sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
	if (textures->sprite == NULL)
		print_error("Malloc error");
}

static void	load_img(t_mlx *mlx, int *texture, char *path, t_img *img)
{
	t_int	point;

	img->img = mlx_xpm_file_to_image(mlx->mlx, path, &img->width, &img->height);
	if (img->img == NULL)
		print_error("Can not open texture file");
	img->addr = (int *) mlx_get_data_addr(img->img, &img->bpp, &img->ll,
			&img->endian);
	point.y = 0;
	while (point.y < img->height)
	{
		point.x = 0;
		while (point.x < img->width)
		{
			texture[img->width * point.y + point.x] = img->addr
			[img->width * point.y + point.x];
			point.x += 1;
		}
		point.y += 1;
	}
}

void	load_textures(t_engine *engine)
{
	t_img	img;

	malloc_textures(&engine->textures);
	load_img(&engine->mlx, engine->textures.north, engine->cfg.north, &img);
	load_img(&engine->mlx, engine->textures.south, engine->cfg.south, &img);
	load_img(&engine->mlx, engine->textures.west, engine->cfg.west, &img);
	load_img(&engine->mlx, engine->textures.east, engine->cfg.east, &img);
	load_img(&engine->mlx, engine->textures.sprite, engine->cfg.sprite, &img);
}
