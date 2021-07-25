#include "cub3d.h"

static void	rotate_right(t_plr *plr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = plr->dir.x;
	plr->dir.x = plr->dir.x * cos(-R_SPEED) - plr->dir.y * sin(-R_SPEED);
	plr->dir.y = old_dir_x * sin(-R_SPEED) + plr->dir.y * cos(-R_SPEED);
	old_plane_x = plr->plane.x;
	plr->plane.x = plr->plane.x * cos(-R_SPEED) - plr->plane.y * sin
		(-R_SPEED);
	plr->plane.y = old_plane_x * sin(-R_SPEED) + plr->plane.y * cos
		(-R_SPEED);
}

static void	rotate_left(t_plr *plr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = plr->dir.x;
	plr->dir.x = plr->dir.x * cos(R_SPEED) - plr->dir.y * sin(R_SPEED);
	plr->dir.y = old_dir_x * sin(R_SPEED) + plr->dir.y * cos(R_SPEED);
	old_plane_x = plr->plane.x;
	plr->plane.x = plr->plane.x * cos(R_SPEED) - plr->plane.y * sin
		(R_SPEED);
	plr->plane.y = old_plane_x * sin(R_SPEED) + plr->plane.y * cos
		(R_SPEED);
}

void	rotations(t_plr *plr, t_events *events)
{
	if (events->key_right)
		rotate_right(plr);
	else if (events->key_left)
		rotate_left(plr);
}
