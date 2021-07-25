#include "cub3d.h"

void	engine(t_cfg cfg)
{
	t_engine	engine;

	engine.cfg = cfg;
	ft_bzero(&engine.events, sizeof(t_events));
	engine.mlx.mlx = mlx_init();
	engine.mlx.win = mlx_new_window(engine.mlx.mlx, cfg.res.width, cfg.res
			.height, "cub3D");
	engine.img.img = mlx_new_image(engine.mlx.mlx, cfg.res.width, cfg.res
			.height);
	engine.img.addr = (int *) mlx_get_data_addr(engine.img.img, &engine.img
			.bpp, &engine.img.ll, &engine.img.endian);
	load_textures(&engine);
	engine.z_buffer = (double *)malloc(sizeof(double) * cfg.res.width);
	mlx_loop_hook(engine.mlx.mlx, &rendering, &engine);
	mlx_hook(engine.mlx.win, 2, 0, &events_press, &engine.events);
	mlx_hook(engine.mlx.win, 3, 0, &events_release, &engine.events);
	mlx_hook(engine.mlx.win, 17, 0, &close_button, NULL);
	mlx_loop(engine.mlx.mlx);
}
