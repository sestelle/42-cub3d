#ifndef ENGINE_H
# define ENGINE_H

# include "structs.h"
# include "events.h"

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define M_SPEED 0.05
# define R_SPEED 0.05

# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0

void	engine(t_cfg cfg);
void	load_textures(t_engine *engine);

int		rendering(t_engine *engine);
void	create_screenshot(t_res res, t_img img);

void	rendering_background(t_cfg cfg, t_img *img);

void	rendering_walls(t_img *img, t_cfg cfg, t_textures textures, double
			*buffer);
void	calculation_1(t_walls *walls, t_plr plr, int x, t_res res);
void	calculation_2(t_walls *walls, t_plr plr, t_res res);
void	calculation_3(t_walls *walls, t_plr plr, t_res res);
void	dda_alg(t_walls *walls, t_plr plr, char **map);
void	tex_num(int side, t_walls *walls, int **texture, t_textures *textures);
void	draw_textures(t_walls *walls, t_img *img, int *texture, int x);

void	find_sprites(t_sprites *sprites, char **map);
void	sort_sprites(int *order, double *dist, int amount);
void	rendering_sprites(t_cfg cfg, t_engine *engine);
void	draw_sprite_textures(t_sprites *sprites, int *texture, \
			t_engine *engine);
void	calculations_sprites_1(t_sprites *sprites, t_plr plr, char **map);
void	calculations_sprites_2(t_sprites *sprites, t_res res, t_plr plr, int i);
void	calculations_sprites_3(t_sprites *sprites, t_res res);

void	pixel_put(t_img *img, int x, int y, int color);
int		close_button(void *param);

#endif
