#include "cub3d.h"

int	events_press(int code, t_events *events)
{
	if (code == 0)
		events->key_a = true;
	if (code == 1)
		events->key_s = true;
	if (code == 2)
		events->key_d = true;
	if (code == 13)
		events->key_w = true;
	if (code == 123)
		events->key_left = true;
	if (code == 124)
		events->key_right = true;
	if (code == 53)
		exit(0);
	return (0);
}
