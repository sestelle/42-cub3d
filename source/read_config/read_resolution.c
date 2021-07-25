#include "cub3d.h"

static void	check_resolution(t_res *res)
{
	int	x;
	int	y;

	if (res->width <= 0 || res->height <= 0)
		print_error("Negative resolution value(s)");
	mlx_get_screen_size(&x, &y);
	if (res->width > x)
		res->width = x;
	if (res->height > y)
		res->height = y;
}

static void	clean(char **split)
{
	int	i;

	i = 0;
	while (i < split_size(split))
	{
		free(split[i]);
		i++;
	}
}

t_res	read_resolution(char *line)
{
	t_res	res;
	char	**split;

	split = ft_split(line, ' ');
	free(line);
	ft_bzero(&res, sizeof(t_res));
	if (split_size(split) == 3)
	{
		res.width = ft_atoi(split[1]);
		res.height = ft_atoi(split[2]);
	}
	else
		print_error("Invalid resolution line");
	check_resolution(&res);
	clean(split);
	free(split);
	return (res);
}
