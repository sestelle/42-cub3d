#include "cub3d.h"

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

int	read_color(char *line)
{
	int		color;
	char	**split;
	char	**colors;

	split = ft_split(line, ' ');
	free(line);
	if (split_size(split) == 2)
	{
		colors = ft_split(split[1], ',');
		clean(split);
		free(split);
		if (split_size(colors) == 3)
		{
			color = convert_rgb(0, ft_atoi(colors[0]),
					   ft_atoi(colors[1]), ft_atoi(colors[2]));
			clean(colors);
			free(colors);
			return (color);
		}
	}
	print_error("Invalid color line");
	return (0);
}
