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

void	read_config(char *path, t_cfg *cfg)
{
	char	**file;

	file = open_file(path);
	cfg->map = read_map(file);
	cfg->plr = read_plr(cfg->map);
	check_map(cfg->map, cfg->plr.pos);
	cfg->res = read_resolution(find_line(file, "R "));
	cfg->floor = read_color(find_line(file, "F "));
	cfg->ceiling = read_color(find_line(file, "C "));
	cfg->north = read_texture(find_line(file, "NO "));
	cfg->south = read_texture(find_line(file, "SO "));
	cfg->west = read_texture(find_line(file, "WE "));
	cfg->east = read_texture(find_line(file, "EA "));
	cfg->sprite = read_texture(find_line(file, "S "));
	clean(file);
	free(file);
}
