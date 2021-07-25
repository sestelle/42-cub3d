#include "cub3d.h"

int	convert_rgb(int t, int r, int g, int b)
{
	if (r >= 0 && r <= 255)
	{
		if (g >= 0 && g <= 255)
		{
			if (b >= 0 && b <= 255)
				return (t << 24 | r << 16 | g << 8 | b);
		}
	}
	print_error("Invalid RGB");
	return (t << 24 | r << 16 | g << 8 | b);
}
