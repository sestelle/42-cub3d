#include "cub3d.h"

static void	move_left(char **map, t_plr *plr)
{
	double	old_dir_x;
	double	old_dir_y;

	old_dir_x = plr->dir.x;
	old_dir_y = plr->dir.y;
	plr->dir.x = -plr->dir.y;
	plr->dir.y = old_dir_x;
	if (map[(int)(plr->pos.x + plr->dir.x * M_SPEED)][(int)(plr->pos.y)] != '1')
		plr->pos.x += plr->dir.x * M_SPEED;
	if (map[(int)(plr->pos.x)][(int)(plr->pos.y + plr->dir.y * M_SPEED)] != '1')
		plr->pos.y += plr->dir.y * M_SPEED;
	plr->dir.x = old_dir_x;
	plr->dir.y = old_dir_y;
}

static void	move_right(char **map, t_plr *plr)
{
	double	old_dir_x;
	double	old_dir_y;

	old_dir_x = plr->dir.x;
	old_dir_y = plr->dir.y;
	plr->dir.x = -plr->dir.y;
	plr->dir.y = old_dir_x;
	if (map[(int)(plr->pos.x - plr->dir.x * M_SPEED)][(int)(plr->pos.y)] != '1')
		plr->pos.x -= plr->dir.x * M_SPEED;
	if (map[(int)(plr->pos.x)][(int)(plr->pos.y - plr->dir.y * M_SPEED)] != '1')
		plr->pos.y -= plr->dir.y * M_SPEED;
	plr->dir.x = old_dir_x;
	plr->dir.y = old_dir_y;
}

void	movements(char **map, t_plr *plr, t_events *events)
{
	float	s;

	s = M_SPEED;
	if (events->key_w)
	{
		if (map[(int)(plr->pos.x + plr->dir.x * s)][(int)(plr->pos.y)] != '1')
			plr->pos.x += plr->dir.x * s;
		if (map[(int)(plr->pos.x)][(int)(plr->pos.y + plr->dir.y * s)] != '1')
			plr->pos.y += plr->dir.y * s;
	}
	if (events->key_s)
	{
		if (map[(int)(plr->pos.x - plr->dir.x * s)][(int)(plr->pos.y)] != '1')
			plr->pos.x -= plr->dir.x * s;
		if (map[(int)(plr->pos.x)][(int)(plr->pos.y - plr->dir.y * s)] != '1')
			plr->pos.y -= plr->dir.y * s;
	}
	if (events->key_a)
		move_left(map, plr);
	if (events->key_d)
		move_right(map, plr);
}
