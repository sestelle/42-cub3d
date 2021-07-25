#include "cub3d.h"

void	events(char **map, t_plr *plr, t_events *events)
{
	movements(map, plr, events);
	rotations(plr, events);
}
