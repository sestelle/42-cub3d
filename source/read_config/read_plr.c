#include "cub3d.h"

static void	set_dir(double dir_x, double dir_y, t_plr *plr)
{
	plr->dir.x = dir_x;
	plr->dir.y = dir_y;
}

static void	set_plane(double plane_x, double plane_y, t_plr *plr)
{
	plr->plane.x = plane_x;
	plr->plane.y = plane_y;
}

static t_plr	plr_dir(int x, int y, char c)
{
	t_plr	plr;

	plr.pos.x = x + 0.5;
	plr.pos.y = y + 0.5;
	if (c == 'N')
	{
		set_dir(-1, 0, &plr);
		set_plane(0, 0.66, &plr);
	}
	else if (c == 'S')
	{
		set_dir(1, 0, &plr);
		set_plane(0, -0.66, &plr);
	}
	else if (c == 'E')
	{
		set_dir(0, 1, &plr);
		set_plane(0.66, 0, &plr);
	}
	else if (c == 'W')
	{
		set_dir(0, -1, &plr);
		set_plane(-0.66, 0, &plr);
	}
	return (plr);
}

static t_plr	check(char **map, t_bool *flag, t_int point)
{
	t_plr	plr;

	ft_bzero(&plr, sizeof(t_plr));
	if (*flag == false)
	{
		plr = plr_dir(point.y, point.x, map[point.y][point.x]);
		*flag = true;
	}
	else
		print_error("Double player position");
	return (plr);
}

t_plr	read_plr(char **map)
{
	t_int	point;
	t_plr	plr;
	t_bool	flag;

	flag = false;
	point.y = -1;
	while (map[++point.y])
	{
		point.x = -1;
		while (map[point.y][++point.x])
		{
			if (ft_strchr("NSWE", map[point.y][point.x]))
				plr = check(map, &flag, point);
		}
	}
	if (flag == false)
		print_error("Invalid map");
	return (plr);
}
