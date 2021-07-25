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

char	*read_texture(char *line)
{
	char	*texture;
	char	**split;

	split = ft_split(line, ' ');
	free(line);
	if (split_size(split) == 2)
	{
		texture = ft_strdup(split[1]);
		clean(split);
		free(split);
		if (open(texture, O_RDONLY) < 0)
			print_error("Invalid texture");
		return (texture);
	}
	clean(split);
	free(split);
	print_error("Invalid texture line");
	return (NULL);
}
