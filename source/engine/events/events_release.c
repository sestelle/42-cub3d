#include "cub3d.h"

int	events_release(int code, t_events *events)
{
	if (code == 0)
		events->key_a = false;
	if (code == 1)
		events->key_s = false;
	if (code == 2)
		events->key_d = false;
	if (code == 13)
		events->key_w = false;
	if (code == 123)
		events->key_left = false;
	if (code == 124)
		events->key_right = false;
	return (0);
}
