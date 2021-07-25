#include "cub3d.h"

static void	cpy_map(char **map, char **tmp, int len_map)
{
	int	i;

	i = 0;
	while (i < len_map)
	{
		map[i] = ft_strdup(tmp[i]);
		i++;
	}
	map[len_map] = 0;
}

char	**read_map(char **file)
{
	char		**tmp;
	static int	len;
	static int	len_map;
	char		*haystack;
	char		**map;

	tmp = file;
	map = NULL;
	haystack = ft_strdup(" 10");
	while (*tmp)
	{
		if (ft_strchr(haystack, *tmp[0]))
			len_map++;
		else if (len_map != 0)
			len++;
		tmp++;
	}
	tmp -= (len + len_map);
	map = (char **)malloc(sizeof(char *) * (len_map + 1));
	cpy_map(map, tmp, len_map);
	free(haystack);
	return (map);
}
