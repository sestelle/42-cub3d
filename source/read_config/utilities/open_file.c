#include "cub3d.h"

/* static void	clean(char **split)
{
	int	i;

	i = 0;
	while (i < split_size(split))
	{
		free(split[i]);
		i++;
	}
} */

static void	concatenate_file(int fd, char **file, int *ret)
{
	char	*line;
	char	*tmp;

	*ret = get_next_line(fd, &line);
	if (*ret < 0)
		print_error("Can not read .cub file");
	tmp = ft_strjoin(line, "\n");
	free(line);
	line = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strjoin(*file, line);
	free(line);
	free(*file);
	*file = ft_strdup(tmp);
	free(tmp);
}

char	**open_file(char *path)
{
	char	*file;
	int		fd;
	int		ret;
	char	**split_file;

	fd = open(path, O_RDONLY);
	file = ft_strdup("\0");
	ret = 1;
	while (true && ret == 1)
		concatenate_file(fd, &file, &ret);
	split_file = ft_split(file, '\n');
	free(file);
	return (split_file);
}
